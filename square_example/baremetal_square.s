    .code16

    .section .data
X:  	.word 0
WIDTH:  .word 0

	.section .text
    .globl _start
    .globl _write_square
_start:
    CLI

	# CLear the Screen
    MOV $0X0600,%AX
    MOV $0XA4,%BH
    MOV $0x0000,%CX
	MOV $0X184F,%DX
    INT $0X10

    # Enter video mode 13h
    MOV $0X0013,%AX
    INT $0X10

loop:
    call _write_square

    ADD $2,%CX
    OR $5,%SI
    ADD $12,%DX
    XOR $0Xa,%DI
    ADD $5,%AX

    JMP loop

    JMP halt

   	/*

	     * * AH = 0Ch
	     * * AL = Color
	     * * BH = Page Number
	     * * CX = x
	     * * DX = y

		_write_square procedure write a square of color AX,
    	to the cordinate CX (X1) and DX (Y1) of base SI(px) and height DI(px)
    */
_write_square:
    MOV $0x0C,%AH
    MOV $0X01,%BH

	MOVW %CX,(X)
	MOVW %SI,(WIDTH)

L1: # Loop the Base
    DEC %SI
    INC %CX
   	INT $0X10
    CMP $0,%SI
	JG	L1

    DEC %DI
    INC %DX
    INT $0X10

    MOVW (X),%CX
    MOVW (WIDTH),%SI

    CMP $0,%DI
    JG L1


    RET


halt:
    HLT

    .org 510
    .word 0xAA55
