//Non DMA method (makes use of free ram space by unused font)
.headersize 0x7FFFF400
.org 0x800C7538
displacedPrologue:
    ADDIU sp, sp, -0x18
    SW ra, 0x0010 (sp)
    JAL checkGameEnd
    NOP
    J 0x8006384C
    NOP

.org 0x800C7550
    .importobj "obj/mp2.o" //include modified boot code

.org 0x80063844
    J displacedPrologue
    NOP

//.org 0x800638C0
    //J checkGameEnd
    //NOP
