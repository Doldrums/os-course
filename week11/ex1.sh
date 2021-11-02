    1  02/11/21 20:56:01 mkdir week11
    2  02/11/21 20:56:05 cd week11
    3  02/11/21 20:56:10 sudo fallocate -l 50M lofs.img
    4  02/11/21 20:56:14 losetup -a
    5  02/11/21 20:56:28 sudo mkfs.ext4 lofs.img
    6  02/11/21 20:56:34 losetup -a | grep 'lofs.img'
    7  02/11/21 20:56:53 mkdir lofsdisk
    8  02/11/21 20:56:59 sudo mount /dev/loop10 /week11/lofsdisk
    9  02/11/21 20:57:06 sudo mount /dev/loop11 /week11/lofsdisk
   10  02/11/21 20:57:15 cd /week11
   11  02/11/21 20:57:21 history > ex1.sh
