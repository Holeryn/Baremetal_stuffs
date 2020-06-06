#ifndef MEMORY
#define MEMORY

#include <stddef.h>

#define CHUNKS 100
#define PAGE 4096 // If i will implement real paging, segmentation and other stuff i will calculate this value
				  // like √(2se)

typedef struct BM_memory {
  unsigned int status;
  void *address;
} BM_memory;

// Bit map init
// require : your BitmapMemory array
// return : void
void BM_init(BM_memory BitmapMemory[CHUNKS]);

// Bit map malloc
// require : your BitmapMemory array, the size of your allocation
void *BM_malloc(BM_memory BitmapMemory[CHUNKS],unsigned int size);

#endif
