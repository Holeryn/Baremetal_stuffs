*A really easy barbone os* 

It is divides in:

* boot.s - The multibootloader that set the stack and create a good environment for C and call the kernel, written in assembly
* kernel.c - The kernel, with some function for work with the vga graphics (Today is osbsolete, but always valid for learn)
* linker.ld - The linker script for use c with assembly
* Makefile - a realy simple makefile for compile the project ($ make all)

*Build the cross-compiler*

https://wiki.osdev.org/GCC_Cross-Compiler

* For more documentation *

https://wiki.osdev.org/Bare_Bones

Output:
