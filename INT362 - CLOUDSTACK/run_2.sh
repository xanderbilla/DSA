#!/bin/bash

#
#       _                 _     _             _    
#      | |               | |   | |           | |   
#   ___| | ___  _   _  __| |___| |_ __ _  ___| | __
#  / __| |/ _ \| | | |/ _` / __| __/ _` |/ __| |/ /
# | (__| | (_) | |_| | (_| \__ \ || (_| | (__|   < 
#  \___|_|\___/ \__,_|\__,_|___/\__\__,_|\___|_|\_\
#                   

#Description of file

echo "-------------------------------------------------------------------------------------------------"
echo "This script will setup a cloudstack management server on a fresh Ubuntu 22.04 LTS server."
echo " "
echo "Author: Xander Billa"
echo "Contact & Support: https://xanderbilla.com | https://github.com/xanderbilla"
echo "-------------------------------------------------------------------------------------------------"

#!This is second file

# Install NTP and Chrony

sudo apt install ntp -y
sudo systemctl enable ntp
sudo systemctl start ntp

sudo apt install chrony -y
sudo apt install openjdk-11-jdk -y

sudo bash -c "cat > /etc/apt/sources.list.d/cloudstack.list" <<EOF
deb [arch=amd64] https://download.cloudstack.org/ubuntu jammy 4.18
EOF

# sudo apt install --only-upgrade ca-certificates -y

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
CREATE USER cloud@'localhost' IDENTIFIED BY '123@Msql';
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
# sudo apt remove nfs-common -y
# sudo apt install nfs-kernel-server -y

# Create directories for primary and secondary storage
service nfs-kernel-server restart

read -p "Enter the IP address to allocate (within the range $ip_range): " ip_address

sudo mkdir -p /mnt/primary
sudo chmod 777 /etc/fstab
sudo echo "$ip_address:/export/primary /mnt/primary nfs
rsize=8192,wsize=8192,timeo=14,intr,vers=3,noauto 0 2" >> /etc/fstab
sudo mount /mnt/primary