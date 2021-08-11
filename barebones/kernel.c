#include "memory/memory.h"
#include "terminal/terminal.h"
#include "segmentation/segmentation.h"
#include "pic/pic.h"


// Check if the compiler thinks you are targeting the wrong operating systems.
#if defined(__linux__)
#error "You are not using a cross compiler, you will most cretainly run into trouble"
#endif

/* This tutorial will only work for the 32-bit ix86 targets. */
#if !defined(__i386__)
#error "This tutorial needs to be compiled with a ix86-elf compiler"
#endif

void kernel_main(void){
  char *s;
  BM_memory BitmapMemory[CHUNKS];

  // initialize the terminal
  terminal_initialize();
  terminal_setcolor(VGA_COLOR_WHITE);
  BM_init(BitmapMemory);
  terminal_writeString("Initialized the terminal...\n");

  // Load the global descriptor table
  terminal_writeString("Loading GDT...\n");
  load_gdt();

  // Initialize PIC
  terminal_writeString("Remapping PIC...\n");
  pic_remap(0,0xF);

}
