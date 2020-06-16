    .global outb

    #  outb -  send a byte to an I/O port
    #  stack:  [esp + 8] the data byte
    #          [esp + 4] the I/O port
    #          [esp]     return address
outb:
    MOV (esp + 8),%AL            # al = the data type
    MOV (esp + 4),%DX            # dx = the I/O port
    OUT %AL,%DX                  # Write at port [dx] th value of [al]
    RET
