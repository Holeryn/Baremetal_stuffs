	    .global outb

	    #  outb -  send a byte to an I/O port
	    #  stack:  [esp + 8] the data byte
	    #          [esp + 4] the I/O port
	    #          [esp]     return address
outb:
	    MOV 8(%ESP),%AL            # al = the data type
	    MOV 4(%ESP),%DX            # dx = the I/O port
	    OUT %AL,%DX                   # Write at port [dx] th value of [al]
	    RET

	    .global inb
inb:
	    MOV	4(%ESP),%DX
	    IN 	%DX,%AL
	    RET
