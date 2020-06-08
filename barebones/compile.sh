#!/bin/bash
i686-elf-as boot.s -o boot.o
i686-elf-gcc -c kernel.c -o kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
i686-elf-gcc -c memory/memory.c -o memory/memory.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
i686-elf-gcc -c terminal/terminal.c -o terminal/terminal.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
i686-elf-gcc -T linker.ld -o myos.bin -ffreestanding -O2 -nostdlib boot.o terminal/terminal.o kernel.o memory/memory.o -L libcc.a

if [ ! -d "isodir" ]; then
	mkdir isodir
fi

if [ ! -d "isodir/boot" ]; then
	mkdir mkdir isodir/boot
fi

if [ ! -d "isodir/boot/grub" ]; then
    mkdir isodir/boot/grub
fi

cp myos.bin isodir/boot/
cp grub.cfg isodir/boot/grub/
grub-mkrescue -o myos.iso isodir
