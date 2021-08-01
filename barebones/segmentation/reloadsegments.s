	.global reloadSegments

reloadSegments:
    LJMP $0x08,$reloadCS

reloadCS:
	    MOV $0X10,%EAX
	    MOV %AX,%DS
	    MOV %AX,%ES
	    MOV %AX,%FS
	    MOV %AX,%GS
	    MOV %AX,%SS
	    RET
