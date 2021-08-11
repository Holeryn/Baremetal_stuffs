#ifndef PIC
#define PIC

void pic_remap(int Moffset,int Soffset);
void pic_ack(unsigned char irq);

#endif
