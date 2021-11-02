#sh ex1.sh

directory=lofsdisk
echo "Vlasov" >> $directory/file1.txt
echo "Egor" >> $directory/file2.txt

sudo chmod 777 $directory/

sudo mkdir -p $directory/{bin,lib64,lib}
sudo cp /bin/{bash,ls,cat,echo} $directory/bin

elements="$(ldd /bin/{bash,ls,cat,echo} | egrep -o '/lib.*\.[0-9]')"
for i in $elements; do sudo cp "$i" "${directory}${i}"; done

sudo gcc -o ex2.out ex2.c
sudo cp ./ex2.out $directory/
sudo chroot $directory ./ex2.out >> ex2.txt
./ex2.out >> ex2.txt