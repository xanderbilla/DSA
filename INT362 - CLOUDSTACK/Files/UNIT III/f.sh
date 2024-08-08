#!/bin/bash

# Update package lists
sudo apt update

sudo apt install -y qemu-kvm cloudstack-agent
sudo sed -i -e 's/\#vnc_listen.*$/vnc_listen = "0.0.0.0"/g'  /etc/libvirt/qemu.conf

sudo echo 'listen_tls=0' >> /etc/libvirt/libvirtd.conf
sudo echo 'listen_tcp=1' >> /etc/libvirt/libvirtd.conf
sudo echo 'tcp_port = "16509"' >> /etc/libvirt/libvirtd.conf
sudo echo 'mdns_adv = 0' >> /etc/libvirt/libvirtd.conf
sudo echo 'auth_tcp = "none"' >> /etc/libvirt/libvirtd.conf
systemctl restart libvirtd

ln -s /etc/apparmor.d/usr.sbin.libvirtd /etc/apparmor.d/disable/
ln -s /etc/apparmor.d/usr.lib.libvirt.virt-aa-helper/etc/apparmor.d/disable/
apparmor_parser -R /etc/apparmor.d/usr.sbin.libvirtd
apparmor_parser -R /etc/apparmor.d/usr.lib.libvirt.virt-aa-helper

sudo modprobe kvm 
lsmod | grep kvm
