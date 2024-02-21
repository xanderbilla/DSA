#!/bin/bash


#Setting up the bridge

sudo apt install -y bridge-utils

read -p "Enter the bridge name: " bridge_name

sudo brctl addbr "$bridge_name"

sudo brctl addif "$bridge_name" ens33

read -p "Enter the gateway4 address: " gateway4
read -p "Enter the address in CIDR notation (e.g., 192.168.114.129/24): " address

cat <<EOF | sudo tee -a /etc/netplan/01-network-manager-all.yaml
network:
  version: 2
  bridges:
    $bridge_name:
      interfaces: [ens33]
      dhcp4: no
      dhcp6: no
      addresses: [$address]
      gateway4: $gateway4
      nameservers:
        addresses: [8.8.8.8, 8.8.4.4]
EOF

sudo netplan apply

sudo systemctl restart NetworkManager
