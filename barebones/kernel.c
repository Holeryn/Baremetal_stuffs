#include "memory/memory.h"
#include "terminal/terminal.h"
#include "segmentation/segmentation.h"


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
  terminal_setcolor(VGA_COLOR_RED);
  BM_init(BitmapMemory);

  // Load the global descriptor table
  load_gdt();

  // allocate memory for s
  s = BM_malloc(BitmapMemory,PAGE);
  s[0] = 'H';
  s[1] = 'A';
  s[2] = 'C';
  s[3] = 'K';
  s[4] = '!';
  terminal_writeString(s);

  s = BM_free(s, BitmapMemory);
}
