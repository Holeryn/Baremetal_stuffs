# Another x86 barbone os 

It is divides in:

* boot.s - The multibootloader that set the stack and create a good environment for C and call the kernel, written in assembly
* kernel.c - The kernel
* memory.c - API for allocate memory with bitmaps  
* terminal.c - API for work with the terminal
* linker.ld - The linker script for use c with assembly
* compile.sh - a bash script for compile,assemble and link the operative system

# Compile, link and assemble the operating system
$ bash compile.sh

or

$ chmod +x compile.sh

$ ./compile.sh

# Build the cross-compiler

https://wiki.osdev.org/GCC_Cross-Compiler

# For more documentation

https://wiki.osdev.org/Bare_Bones (off course is not just a copy of the barebone os into the osdev wiky, but is a good documentation for understand some part of this repo)

# For try on qemu

$ qemu-system-i386 -cdrom myos.iso


# Output:
![](https://github.com/Holeryn/Baremetal_stuffs/blob/master/img/BareBones.png)
