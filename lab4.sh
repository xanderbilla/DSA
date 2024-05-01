df -h
sudo mkfs -t ext3 /dev/sdf
sudo mkdir /mnt/data-store
sudo mount /dev/sdf /mnt/data-store
echo "/dev/sdf   /mnt/data-store ext3 defaults,noatime 1 2" | sudo tee -a /etc/fstab
cat /etc/fstab
df -h
echo "Adding sometext to newly created data store"
sudo sh -c "echo some text has been written > /mnt/data-store/file.txt"
cat /mnt/data-store/file.txt



sudo mkdir /mnt/data-store2
sudo mount /dev/sdg /mnt/data-store2
ls /mnt/data-store2/
cat /mnt/data-store2/fi1e.txt