//Non DMA method (makes use of free ram space by unused font)
.headersize 0x7FFFF400
.org 0x8009F400
    .importobj "obj/mp3.o" //include modified boot code

//patch func_800F92A0_10CEC0_shared_board
.headersize 0x800F92A0 - 0x10CEC0
.org 0x800F9334
    J checkGameEnd
    NOP