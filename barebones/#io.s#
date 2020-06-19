    global outb

    ;;  outb -  send a byte to an I/O port
    ;;  stack:  [esp + 8] the data byte
    ;;          [esp + 4] the I/O port
    ;;          [esp]     return address
outb:
    mov al,[esp + 8]            ; al = the data type
    mov dx,[esp + 4]            ; dx = the I/O port
    out dx,al                   ; Write at port [dx] th value of [al]
    ret

    global inb
inb:
    mov	dx,[esp + 4]
    in 	al,dx
    ret
