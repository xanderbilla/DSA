#!/bin/bash

# Check if the user is in the sudoers file
if ! sudo grep -q "^$USER" /etc/sudoers; then
    sudo usermod -aG sudo $USER
fi

# Display message while checking for internet connection
echo "Wait while we check for internet..."

# Check for internet connection
if ! ping -c 1 8.8.8.8 &> /dev/null; then
    echo "No internet connection. Aborting..."
    echo "."
    echo "."
    echo "."
    echo "Please check your internet connection and try again!"
    exit 1
fi

# Update and upgrade packages
echo "Updating and upgrading packages..."
if sudo apt update && sudo apt upgrade -y; then
    echo "Packages updated and upgraded successfully."
else
    echo "Error: Failed to update and upgrade packages."
    exit 1
fi

# Determine default gateway address with subnet mask
gateway_info=$(ip route | awk '/default/ {print $3}')
gateway_address=$(ip -o -4 addr show scope global | awk '{print $4}' | awk -F"/" '{print $1}')
subnet_mask=$(ip -o -4 addr show scope global | awk '{print $4}' | awk -F"/" '{print $2}')
default_gateway="$gateway_info"

# Determine IP address range for interface
interface_name=$(ip route get 8.8.8.8 | awk '{print $5}')
ip_range=$(ip -4 -o addr show dev "$interface_name" | awk '{print $4}')

# Loop to prompt the user three times for IP address input
for i in {1..3}; do
    # Ask user for IP address
    read -p "Enter the IP address to allocate (within the range $ip_range): " ip_address

    # Validate user-provided IP address format
    if [[ ! $ip_address =~ ^([0-9]{1,3}\.){3}[0-9]{1,3}/[0-9]+$ ]]; then
        echo "Invalid IP address format. Please enter a valid IP address in the format x.x.x.x/y."
        if [ $i -eq 3 ]; then
            echo "Failed to provide a valid IP address. Aborting."
            exit 1
        fi
    else
        break
    fi
done

# Determine interface name
interface_name=$(ip route get 8.8.8.8 | awk '{print $5}')

# Backup /etc/netplan/01-network-manager-all.yaml
sudo cp /etc/netplan/01-network-manager-all.yaml /etc/netplan/01-network-manager-all.yaml.bak

# Backup /etc/hosts
sudo cp /etc/hosts /etc/hosts.bak

# Replace the contents of 01-network-manager-all.yaml file
sudo bash -c "cat > /etc/netplan/01-network-manager-all.yaml" <<EOF
network:
  version: 2
  renderer: NetworkManager
  ethernets:
    $interface_name:
      dhcp4: no
      addresses: [$ip_address]
      gateway4: $default_gateway
      nameservers:
        addresses: [8.8.8.8, 8.8.8.4]
EOF

# Apply the changes
sudo netplan apply

# Update /etc/hosts
sudo sed -i "3i\\
$(echo "$ip_address" | cut -d'/' -f1)   apache.cloud.u1 cloud" /etc/hosts

# Set hostname
current_hostname=$(hostname -f)

# Set new hostname
sudo hostnamectl set-hostname cloud

new_hostname=$(hostname -f)

# Restart NetworkManager
sudo systemctl restart NetworkManager

# Display updated IP address
ip a

read -p "Enter the name of bridge to setup: " bridge_name

sudo apt install bridge-utils -y
sudo brctl addbr $bridge_name
sudo brctl addif $bridge_name $interface_name
sudo bash -c "cat > /etc/netplan/01-network-manager-all.yaml" <<EOF
network:
    version: 2
    renderer: NetworkManager
    ethernets:
        $interface_name:
            dhcp4: no
            dhcp6: no

    bridges:
        $bridge_name:
            interfaces: [$interface_name]
            dhcp4: no
            dhcp6: no
            addresses: [$ip_address]
            gateway4: $default_gateway
            nameservers:
                addresses: [8.8.8.8, 8.8.4.4]
EOF

sudo cp 01-network-manager-all.yaml /etc/netplan/bridge_01-network-manager-all.yaml.bak

sudo netplan apply
sudo systemctl restart NetworkManager

# Install NTP and Chrony

sudo apt install ntp -y
sudo systemctl enable ntp
sudo systemctl start ntp

sudo apt install chrony -y
sudo apt install openjdk-11-jdk -y

sudo bash -c "cat > /etc/apt/sources.list.d/cloudstack.list" <<EOF
deb [arch=amd64] https://download.cloudstack.org/ubuntu jammy 4.18
EOF

sudo apt install --only-upgrade ca-certificates -y

wget -O - https://download.cloudstack.org/release.asc |sudo tee /etc/apt/trusted.gpg.d/cloudstack.asc

sudo apt update

# Install cloudstack-management and mysql-server

sudo apt install -y cloudstack-management
sudo apt install -y mysql-server
sudo bash -c "cat >> /etc/mysql/my.cnf" <<EOF
[mysqld]
server-id=1
innodb_rollback_on_timeout=1
innodb_lock_wait_timeout=600
max_connections=350
log-bin=mysql-bin
binlog-format = 'ROW'
EOF

sudo systemctl restart mysql
sudo mysql_secure_installation <<EOF
y
0
y
y
y
y
EOF

# Create database for cloudstack

sudo mysql <<EOF
CREATE DATABASE \`cloud\`;
CREATE DATABASE \`cloud_usage\`;

-- Create the cloud user
CREATE USER cloud@'localhost' IDENTIFIED BY '<password>';
CREATE USER cloud@'localhost' IDENTIFIED BY '123@Msql';

CREATE USER cloud@'%' IDENTIFIED BY '<password>';
CREATE USER cloud@'%' IDENTIFIED BY '1234@Sql';

-- Grant all privileges to the cloud user on the databases

GRANT ALL ON cloud.* TO cloud@'localhost';
GRANT ALL ON cloud.* TO cloud@'%';
GRANT ALL ON cloud_usage.* TO cloud@'localhost';
GRANT ALL ON cloud_usage.* TO cloud@'%';
-- Grant process list privilege for all other databases
GRANT PROCESS ON *.* TO cloud@'localhost';
GRANT PROCESS ON *.* TO cloud@'%';
EXIT
EOF


# Configure cloudstack-management

sudo cloudstack-setup-databases cloud:password@localhost --deploy-as=root
sudo cloudstack-setup-management
sudo ufw allow mysql
sudo mkdir -p /export/primary
sudo mkdir -p /export/secondary
sudo bash -c "cat >> /etc/exports" <<EOF
/export *(rw,async,no_root_squash,no_subtree_check)
EOF
sudo apt install -y nfs-kernel-server
sudo exportfs -a

# Install NFS server (required for secondary storage and system VMs)
#optional
sudo apt remove nfs-common -y
sudo apt install nfs-kernel-server -y

# Create directories for primary and secondary storage
service nfs-kernel-server restart

$pattern = '/^(\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3})\/\d{1,2}$/'; // Pattern to match IP address and subnet mask

if (preg_match($pattern, $ip_addr, $matches)) {
    $ip_address = $matches[1]; // Extracting the IP address
} else {
    echo "No valid IP address found.";
}

sudo mkdir -p /mnt/primary
sudo chmod 777 /etc/fstab
sudo echo "$ip_address:/export/primary /mnt/primary nfs
rsize=8192,wsize=8192,timeo=14,intr,vers=3,noauto 0 2" >> /etc/fstab
sudo mount /mnt/primary

#***************Ouput**********************
echo -n "MySQL running port and PID : "
sudo netstat -tulnp | grep mysql
echo "Default Gateway Address: $default_gateway"
echo "Example IP address range on $interface_name: $ip_range"
echo "IP Address to allocate: $ip_address"
echo "Interface Name: $interface_name"

echo "Current hostname: $current_hostname"
echo "New hostname: $new_hostname"

#***************End of Output**********************
