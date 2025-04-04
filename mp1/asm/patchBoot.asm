//Non DMA method (makes use of free ram space by unused font)
.headersize 0x7FFFF400
.org 0x800C0730
displacedPrologue:
    DADDU gp, ra, r0 //push RA for later
    JAL checkGameEnd
    NOP
    LH v0, 0x0008 (s5) //restore from hook
    LH v1, 0x0006 (s5) //restore from hook
    SLT v0, v0, v1 //restore from hook
    J 0x800580B4
    DADDU ra, gp, r0 //pop RA
 
.org 0x800C0750
    .importobj "obj/mp1.o" //include modified boot code

.org 0x800580AC
    J displacedPrologue
    NOP
