as -g -o baremetal_square.o baremetal_square.s
ld --oformat binary -o 'baremetal_square.img' -Ttext 0x7C00 baremetal_square.o
qemu-system-i386 -hda 'baremetal_square.img'
