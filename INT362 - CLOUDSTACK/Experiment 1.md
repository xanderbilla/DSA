# **Apache Cloud Stack**

![](https://33333.cdn.cke-cs.com/kSW7V9NHUXugvhoQeFaf/images/2cd49546dc12bfcfbcc9f7770da8938277bb1e7866c93874.png)

## Files

Here is the direct link for entire script (just paste the following in terminal) - 

```plaintext
wget https://xanderbilla.s3.ap-south-1.amazonaws.com/LPU-K22DP-2024/INT_362/run_2.sh 
wget https://xanderbilla.s3.ap-south-1.amazonaws.com/LPU-K22DP-2024/INT_362/run_1.sh
chmod u+x run*
./run_1.sh

#Once the system reboot automatically -> Open the terminal and run the second script 

./run_2.sh
```

## **Management Server Setup**

**Step 1:** Create virtual machine with following configuration – 

<table><tbody><tr><td>RAM</td><td>4 GB</td></tr><tr><td>Processor</td><td>2 Core</td></tr><tr><td>HDD</td><td>60 GB</td></tr></tbody></table>


**Step 2:** Launch virtual machine

**Step 3:** Login and open Terminal by any of the following way – 

*   Right Click on **Desktop** and select **Open a Terminal**
*   Goto **Menu** and select **Terminal**

**following command – 

```plaintext
[student@localhost]$ sudo apt get update
```

_**Remember:** In case if the output saying_ user not in sudoers file _then run the following command –_

```plaintext
[student@localhost]$ su
[student@localhost]$ apt install sudo 
[student@localhost]# usermod -aG sudo <username>
```

In some cases, it might not fix the issue so we need to manually add user into sudoers file o do it following – 

```plaintext
[student@localhost]$ su -
[student@localhost]# nano /etc/sudoers
.
.
.
# User privilege specification
root    ALL=(ALL:ALL) ALL
# Members of the admin group may gain root privileges
%admin ALL=(ALL) ALL
# Allow members of group sudo to execute any command
%sudo   ALL=(ALL:ALL) ALL
# See sudoers(5) for more information on "@include" directives:
@includedir /etc/sudoers.d 
<username> ALL=(ALL) NOPASSWD:ALL
```

After the configuration Save the file.

**your IP address – 

```plaintext
[student@localhost]$ ip a
[student@localhost]$ ip r
default via 192.168.11.2 dev ens33 proto dhcp metric 100
169.254.0.0/16 dev ens33 scope link metric 1000
192.168.11.0/24 dev ens33 proto kernel scope link src 192.168.11.129 metric 100
```

ip r used to display the route for the interface

From here check for inet that contain broadcast address.  
Here my IP Address is – `192.168.11.11/24`

**Step 6 - Setup of Static IP Address –**

Open a file as a root and make the following changes–

```plaintext
[student@localhost]$ sudo nano /etc/netplan/01-network-manager-all.yaml
```

It is commonly used for configuration files and in applications where data is being stored or transmitted. 

Configuration – 

```yaml
network:
 version: 2
 renderer: NetworkManager
 ethernets:
   <InterfaceName>:
     dhcp4: no
     addresses: [<IPAddress/subnetMask>]
     gateway4: <Default_Gateway_Address>
     nameservers:
         addresses: [8.8.8.8, 8.8.8.4]
```

Once done save the file and apply the changes and verify the IP Address from following command –

```plaintext
[student@localhost]$ sudo netplan apply
[student@localhost]$ ip a
[student@localhost]$ sudo systemctl restart NetworkManager
```

**Step 7 - Setup of host name and creating a network –**

```plaintext
[student@localhost]$ hostname -f 
localhost
[student@cloud]$ sudo nano /etc/hosts
Configuration – 
127.0.0.1       localhost
127.0.1.1       admin
192.168.11.11   apache.cloud.u1 cloud

# The following lines are desirable for IPv6 capable hosts
::1     ip6-localhost ip6-loopback
fe00::0 ip6-localnet
ff00::0 ip6-mcastprefix
ff02::1 ip6-allnodes
ff02::2 ip6-allrouters
```

Add the highlighted line in the hosts configuration file.

```plaintext
[student@cloud]$ sudo hostnamectl set-hostname cloud 
[student@cloud]$ hostname -f
apache.cloud.u1
```

**Step 7 - Creating bridge**

_Note:_

*   _It is a software or a tool that is used for configuring and managing network bridges on Linux operating system._
*   _A network bridge is a software or hardware entity that connects multiple network segments together allowing them to function as a single network._

```plaintext
[student@cloud]$ sudo apt install bridge-utils
[student@cloud]$ sudo brctl addbr cloudbr0
[student@cloud]$ sudo brctl addif cloudbr0 ens33
[student@cloud]$ sudo nano /etc/netplan/01-network-manager-all.yaml
```

`/etc/netplan/01-network-manager-all.yaml` configuration - 

```yaml
network:
    version: 2
    renderer: NetworkManager
    ethernets:
        ens3:
            dhcp4: no
            dhcp6: no

    bridges:
        cloudbr0:
            interfaces: [ens33]
            dhcp4: no
            dhcp6: no
            addresses: [192.168.11.11/24]
            gateway4: 192.168.11.2
            nameservers:
                addresses: [8.8.8.8, 8.8.4.4]
```

```plaintext
sudo netplan apply
sudo systemctl restart NetworkManager
sudo apt install ntp
```
**Step 8 -** Install NTP

**Network Time Protocol (NTP)** is a protocol that is used to synchronize all system clocks in a network to use the same time.

```plaintext
sudo systemctl enable ntp
sudo systemctl start ntp
sudo apt install chrony
sudo apt install openjdk-11-jdk
sudo nano /etc/apt/sources.list.d/cloudstack.list
```

Add the follwoing line -

```yaml
deb https://download.cloudstack.org/ubuntu jammy 4.18
```

Now, add [public key](https://docs.cloudstack.apache.org/en/latest/installguide/management-server/) to the trusted keys

```plaintext
wget -O - https://download.cloudstack.org/release.asc |sudo tee /etc/apt/trusted.gpg.d/cloudstack.asc 
```

Update local cache - 

```plaintext
sudo apt update
```

If Error comes here: use below commands

```plaintext
sudo apt install --only-upgrade ca-certificates
[trusted = yes]
```

**Step 9 -** Installing Cloud Management & My SQL Server

```plaintext
sudo apt install cloudstack-management
sudo apt install mysql-server
sudo nano /etc/mysql/my.cnf
```

Add the below lines at the bottom:

```conf
[mysqld]
server-id=1
innodb_rollback_on_timeout=1
innodb_lock_wait_timeout=600
max_connections=350
log-bin=mysql-bin
binlog-format = 'ROW'
```

**Restart My SQL Server**

```plaintext
sudo systemctl restart mysql
sudo mysql_secure_installation
Would you like to setup VALIDATE PASSWORD component?
Press y|Y for Yes, any other key for No: y
Please enter 0 = LOW, 1 = MEDIUM and 2 = STRONG: 0
Remove anonymous users? (Press y|Y for Yes, any other key for No) : y
Success.
Disallow root login remotely? (Press y|Y for Yes, any other key for No) : y
Success.
Remove test database and access to it? (Press y|Y for Yes, any other key for No) : y
Reload privilege tables now? (Press y|Y for Yes, any other key for No) : y
Success.
All done!
sudo mysql
```

Execute the following QUERY in My SQL

```sql
-- Create the cloud and cloud_usage databases
CREATE DATABASE `cloud`;
CREATE DATABASE `cloud_usage`;
-- Create the cloud user
CREATE USER cloud@`localhost` identified by '<password>';
CREATE USER cloud@'localhost' identified by '123@Msql';
CREATE USER cloud@`%` identified by '<password>';
CREATE USER cloud@'%' identified by '1234@Sql';
-- Grant all privileges to the cloud user on the databases
GRANT ALL ON cloud.* to cloud@`localhost`;
GRANT ALL ON cloud.* to cloud@`%`;
GRANT ALL ON cloud_usage.* to cloud@`localhost`;
GRANT ALL ON cloud_usage.* to cloud@`%`;
-- Grant process list privilege for all other databases
GRANT process ON *.* TO cloud@`localhost`;
GRANT process ON *.* TO cloud@`%`;
Exit
```

**Step 10 -** Deply the cloudstack

```plaintext
 sudo cloudstack-setup-databases cloud:password@localhost --deploy-as=root
sudo ufw allow mysql
sudo mkdir -p /export/primary
sudo mkdir -p /export/secondary
sudo nano /etc/exports
```
Add the follwoing line -

```conf
/export *(rw,async,no_root_squash,no_subtree_check)
```

If any error occur than - 
```plaintext
sudo apt remove nfs-common
sudo apt install nfs-kernel-server
sudo exportfs -a
service nfs-kernel-server restart
```
**Step 11 -** Create a primary disk for the server

```plaintext
sudo mkdir -p /mnt/primary
sudo chmod 777 /etc/fstab
sudo echo "192.168.139.133:/export/primary /mnt/primary nfs
rsize=8192,wsize=8192,timeo=14,intr,vers=3,noauto 0 2" >> /etc/fstab
sudo mount /mnt/primary
```

**Step 12 -** Open [http://localhost:8080](http://localhost:8080) using following credentials...

**Username:** admin, **Password:** password

## Support

For support or colab, [email](mailto:dev.xanderbilla@gmail.com) or visit [website](https://xanderbilla.com)

## Authors

[Xander Billa](https://xanderbilla.com)
