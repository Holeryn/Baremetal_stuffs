#ifndef LGDT
#define LGDT

struct gdt_entry {
  unsigned int limit;
  unsigned int base;
  unsigned char type;
  unsigned char access;
} __attribute__((packed));


typedef struct gdt_entry gdt_entry_t;

void lgdt(void *gdt);

#endif
