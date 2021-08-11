/* Forces the CPU to wait for an I/O operation to complete. only use this when there's nothing like a status register or an IRQ to tell you the info has been received.  */
void
io_wait(void){
  asm volatile ( "jmp 1f\n\t"
                 "1:jmp 2f\n\t"
                 "2:" );
}
