#!/bin/bash

cat banner.txt
#Description of file

echo ""
echo "-------------------------------------------------------------------------------------------------"
echo "This script will setup a cloudstack management server on a fresh Ubuntu 22.04 LTS server."
echo " "
echo "Author: Xander Billa"
echo "Contact & Support: https://xanderbilla.com | https://github.com/xanderbilla"
echo "-------------------------------------------------------------------------------------------------"

#!This is second file

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

#If you get warning
# network:
#   version: 2
#   renderer: NetworkManager
#   ethernets:
#     $interface_name:
#       dhcp4: no
#       addresses: [$ip_address]
#       routes:
#         - to: default
#             via: $default_gateway 
#       nameservers:
#         addresses: [8.8.8.8, 8.8.8.4]


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
reboot