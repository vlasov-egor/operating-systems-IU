mkdir week11 
cd week11
sudo fallocate -l 50M lofs.img
sudo mkfs.ext4 lofs.img
sudo mkdir lofsdisk 
mount /dev/loop9 /week11/lofsdisk
cd /week11 | history > ex1.sh
