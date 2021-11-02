chr=`pwd`/lofsdisk
mkdir -p $chr/bin $chr/lib $chr/lib64

sudo cp -v /bin/bash $chr/bin
sudo cp -v /bin/ls $chr/bin
sudo cp -v /bin/cat $chr/bin
sudo cp -v /bin/echo $chr/bin

gcc ex2.c -o ex2.out
cp -v ex2.out $chr/ex2.out

for cmd in /bin/bash /bin/ls /bin/cat /bin/echo
do
	list=$(ldd $cmd | egrep -o "/lib.*\.[0-9]")
	IFS=$`\n`
	echo $list | while read -r i; do sudo cp -v --parents "$i" "${chr}"; done
done

sudo bash -c "echo 'Arina' > ${chr}/file1" | sudo bash -c "echo 'Cheverda' > ${chr}/file2"

sudo cp ex2.out $chr/ex2.out

sudo chroot $chr ./ex2.out >> ex2.txt
./ex2.out >> ex2.txt

