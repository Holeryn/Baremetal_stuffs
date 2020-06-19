#ifndef SERIAL
#define SERIAL

#include "../io.h"


/* The I/O ports */
#define COM1 0x3F8
#define COM2 0x2F8
#define COM3 0x3E8
#define COM4 0x2E8

/* All the I/O ports are calculated relative to the data port. This is because
 * all serial ports (COM1, COM2, COM3, COM4) have their ports in the same
 * order, but they start at different values.
 */

#define SERIAL_DATA_PORT(base)		   	(base)
#define SERIAL_FIFO_COMMAND_PORT(base) 	(base + 2)
#define SERIAL_LINE_COMMAND_PORT(base) 	(base + 3)
#define SERIAL_MODEM_COMMAND_PORT(base) (base + 4)
#define SERIAL_LINE_STATUS_PORT(base)	(base + 5)

/* SERIAL_LINE_ENABLE_DLAB:
 * Tells the serial port to expect first the highest 8 bits on the data port,
 * then the lowest 8 bits will follow
 */
#define SERIAL_LINE_ENABLE_DLAB		0x80


void serial_write(char *s);

int serial_is_transmit_fifo_epmty(unsigned int com);

void serial_configure_line(unsigned short com);

void serial_configure_baud_rate(unsigned short com, unsigned short divisor);

#endif
