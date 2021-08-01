#include "lgdt.h"
#include "reloadsegments.h"

#define NUMBER_OF_SEGMENTS 3

#define TYPE_RX 0x9A // Read and execute
#define TYPE_RW 0x92 // Read and write

// macro that gives the size of n segment
// the GDT/LDT is an array of 8 byte segment descriptor
#define S_SEGMENT(n) 8*n

void load_gdt(void){
  gdt_entry_t gdt[NUMBER_OF_SEGMENTS];

  // disable interrupts
  asm volatile ("cli");

  // Initialize GDT

  // Null segment
  gdt[0].base = 0;
  gdt[0].limit = 0;
  gdt[0].type = 0;
  gdt[0].access = 0;

  // Kernel code segment
  gdt[0].base = 0;
  gdt[0].limit = 0xFFFFFFFF;
  gdt[0].type = TYPE_RX;
  gdt[0].access = 0;

  // Kernel data segment
  gdt[0].base = 0;
  gdt[0].limit = 0xFFFFFFFF;
  gdt[0].type = TYPE_RW;
  gdt[0].access = 0;

  lgdt(&gdt);
  // Grub has already loaded the segment registers
  // with the correct values (0x8 for cs, 0x10 for the others)

  // restore interrupts
  asm volatile ("sti");
}
