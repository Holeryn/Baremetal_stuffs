// A not really good implementation
// of bitmap memory

#include "memory.h"

// Initialize the Bitmap memory
// i iterate the memory from 0 to CHUNKS * PAGE
// for see which "block" is free and which not
// The memory will contain 0 for identify a free block
// and 1 for identify a not free block
void
BM_init(BM_memory BitmapMemory[CHUNKS]){
  void *address;
  int i;

  // TODO : address = the most near value out of the bootloader region
  for(i = 0,address = (void *)0xFF; *(int *)address <= (CHUNKS * PAGE); i++,*(int *)address = (void *)address + PAGE){
    if(i != 0){
      BitmapMemory[i].status = 1;
      BitmapMemory[i].address = address;
     }else{
      BitmapMemory[i].status = 0;
      BitmapMemory[i].address = address;
    }
  }
}

// Allocate memory for something (yeah generic type gne gne gne)
void *
BM_malloc(BM_memory BitmapMemory[CHUNKS],unsigned int size){
  BM_init(BitmapMemory);

  for(int i = 0; i <= CHUNKS; i++){
    if(BitmapMemory[i].status == 0){
      if(size <= PAGE){
        return BitmapMemory[i].address;
      }else{ // Ok! maybe there is a better way for this
        int flag = 0;
        for(int unit = size / PAGE; unit >= 0; unit--){
          if(BitmapMemory[i+unit].address != 0)
            flag = 1;
        }

        if(flag == 1)
          continue;
        else
          return BitmapMemory[i].address;
      }
    }
  }

  return NULL;
}

// free a block of memory
// Use a variable freed of course is a UB
void *
BM_free(void *block, BM_memory BitmapMemory[CHUNKS]){
  BM_init(BitmapMemory);

  for(int i = 0; i <= CHUNKS; i++){
    if(BitmapMemory[i].address == block){
      if(sizeof(block) <= PAGE){
        BitmapMemory[i].status = 0;
      }else{
        for(int j = sizeof(block) / PAGE; j >= 0; --j)
          BitmapMemory[i+j].status = 0;
      }

      return BitmapMemory[i].address;
    }
  }

  return NULL;
}
