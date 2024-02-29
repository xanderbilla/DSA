#!/bin/bash

echo "Uninstalling MySQL"

sudo systemctl stop mysql
sudo apt purge mysql-server mysql-client mysql-common mysql-server-core-* mysql-client-core-*
sudo rm -rf /etc/mysql /var/lib/mysql /var/log/mysql
sudo apt autoremove
sudo apt autoclean
sudo apt remove dbconfig-mysql

echo "MySQL Uninstalled Successfully"