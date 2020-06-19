#!/bin/bash
CC=i686-elf-gcc
CC_FLAGS=-std=gnu99 -O2 -Wall -Wextra
AS=i686-elf-as

${AS} boot.s -o boot.o
${AS} io.s -o io.o
${CC} -c cursor/cursor.c -o cursor.o
${CC} -c kernel.c -o kernel.o ${CC_FLAGS} -ffreestanding
${CC} -c serial/serial.c -o serial.o ${CC_FLAGS} -ffreestanding
${CC} -c memory/memory.c -o memory/memory.o ${CC_FLAGS} -ffreestanding
${CC} -c terminal/terminal.c -o terminal/terminal.o ${CC_FLAGS} -ffreestanding
${CC} -T linker.ld -o myos.bin -ffreestanding -O2 -nostdlib cursor.o boot.o terminal/terminal.o kernel.o serial.o memory/memory.o -L libcc.a

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
