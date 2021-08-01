    .global lgdt

    # lgdt - Load the global descriptor table
    # parameters: addres of gdt struct
lgdt:
    MOV 	4(%ESP),%EAX
    LGDT 	(%EAX)
    RET
