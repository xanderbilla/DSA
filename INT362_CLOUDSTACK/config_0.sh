sudo apt install openssh-server
sudo ufw status
sudo ufw enable
sudo ufw allow ssh
sudo cp /etc/ssh/sshd_config /etc/ssh/sshd_config.bak
sudo nano /etc/ssh/sshd_config