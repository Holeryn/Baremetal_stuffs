#include "../io.h"
#include "../Utils.h"

#define PIC1		0x20		/* IO base address for master PIC */
#define PIC2		0xA0		/* IO base address for slave PIC */
#define PIC1_COMMAND	PIC1
#define PIC1_DATA	(PIC1+1)
#define PIC2_COMMAND	PIC2
#define PIC2_DATA	(PIC2+1)

#define ICW1_ICW4	0x01		/* ICW4 (not) needed */
#define ICW1_SINGLE	0x02		/* Single (cascade) mode */
#define ICW1_INTERVAL4	0x04		/* Call address interval 4 (8) */
#define ICW1_LEVEL	0x08		/* Level triggered (edge) mode */
#define ICW1_INIT	0x10		/* Initialization - required! */

#define ICW4_8086	0x01		/* 8086/88 (MCS-80/85) mode */
#define ICW4_AUTO	0x02		/* Auto (normal) EOI */
#define ICW4_BUF_SLAVE	0x08		/* Buffered mode/slave */
#define ICW4_BUF_MASTER	0x0C		/* Buffered mode/master */
#define ICW4_SFNM	0x10		/* Special fully nested (not) */

#define PIC_EOI		0x20		/* End-of-interrupt command code  (ACK)*/

// Remap the PIC
// giving them specified vector offsets (Moffset, Soffset)
// rather than 8h and 70h, as configured by default
void pic_remap(int Moffset,int Soffset){
  outb(PIC1_COMMAND,ICW1_INIT | ICW1_ICW4); // cascade mode
  io_wait(); // wait a response from the PIC
  outb(PIC2_COMMAND, ICW1_INIT | ICW1_ICW4);
  io_wait();
  outb(PIC1_DATA,Moffset); // Master PIC vector offset
  io_wait();
  outb(PIC2_DATA,Soffset); // Slave PIC vector offset
  io_wait();

  // Connect Master and slave through IRQ2
  outb(PIC1_DATA, 4);                       // ICW3: tell Master PIC that there is a slave PIC at IRQ2 (0000 0100)
  io_wait();
  outb(PIC2_DATA, 2);                       // ICW3: tell Slave PIC its cascade identity (0000 0010)
  io_wait();

  outb(PIC1_DATA, ICW4_8086);
  io_wait();
  outb(PIC2_DATA, ICW4_8086);
  io_wait();

  // At this point the PIC mash should be clear so i just
  // write 0 for the mask
  outb(PIC1_DATA, 0);
  outb(PIC2_DATA, 0);

  // Now the ith (with i from 0 to 8) interrupt of the interrupt master is at
  // offset1 + i, similary for slave PIC
}

void pic_ack(unsigned char irq){
  if(irq >= 8){
    outb(PIC2_COMMAND,PIC_EOI);
  }

  outb(PIC1_COMMAND,PIC_EOI);
}
