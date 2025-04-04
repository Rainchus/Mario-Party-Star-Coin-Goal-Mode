//data
.definelabel Player1Buttons,		0x800CCF7C
.definelabel Player1Pressedbuttons,	0x800C9520
.definelabel Player2Pressedbuttons,	0x800C9522
.definelabel Player3Pressedbuttons,	0x800C9524
.definelabel Player4Pressedbuttons,	0x800C9526
.definelabel inBoardPtr, 0x800CC3DC
.definelabel objects, 0x80114B18
.definelabel cur_rng_seed, 0x80097650
.definelabel debugPrintBool, 0x800A1760
.definelabel num_board_spaces, 0x80105210
.definelabel hydrated_space_data, 0x80105214
.definelabel gPlayers, 0x800D1108

//functions
.definelabel GetCurrentPlayerIndex, 0x800F2130
.definelabel GetPlayerStruct, 0x800F213C
.definelabel unknownDMAFunc, 0x8004DB14
.definelabel PlaySound, 0x8004AA88
.definelabel DrawDebugText, 0x8004DD7C
.definelabel _sprintf, 0x8007BDC0
.definelabel HuGetRandomByte, 0x8000B16C
.definelabel DrawBox, 0x8004DE24
.definelabel RedrawSpaces, 0x800EBDAC

// Tell armips' linker where the assets we declared in sm64.h are located
// .definelabel dmaCopy, 0x80062088
// .definelabel dmaCopy2, 0x80061FE8
// .definelabel sleepVProcess, 0x800635B4
// .definelabel drawDebugText, 0x800622BC
// .definelabel mp1_sprintf, 0x8008C490
// .definelabel mallocPerm, 0x8003B6A4
// .definelabel createBox, 0x80062364
.definelabel osGetTime, 0x8007CC90
// .definelabel osGetCount, 0x80093780
// .definelabel __osVIIntrCount, 0x800ED608
// .definelabel rng_seed, 0x800C2FF4
// .definelabel GetRandomByte, 0x8001758C
// .definelabel rngSeed, 0x800C2FF4
// .definelabel func_80018B2C, 0x80018B2C
// .definelabel func_8001E5A0, 0x8001E5A0
// .definelabel func_800247FC, 0x800247FC
// .definelabel func_8005E3FC, 0x8005E3FC
// .definelabel boxDrawn, 0x800C59A6
// .definelabel box0Struct, 0x800ED448
// .definelabel minigameIslandLives, 0x800F37BB
// .definelabel func_800672DC, 0x800672DC
// .definelabel func_800635B4, 0x800635B4
// .definelabel func_800672B0, 0x800672B0
// .definelabel D_800D84E4, 0x800D84E4
// .definelabel func_8002B6C8, 0x8002B6C8
// .definelabel func_8001DFC0, 0x8001DFC0
// .definelabel func_80025658, 0x80025658
// .definelabel func_800621D8, 0x800621D8
// .definelabel osContGetReadData, 0x80090120

//.definelabel cFile, 0x800C2000
.definelabel osMemSize, 0x80000318
.definelabel __osCurrentTime, 0x800CE2B8
.definelabel memcpy, 0x8007BD94
.definelabel _Printf, 0x80081A40
.definelabel osWritebackDCacheAll, 0x80078D50
.definelabel osViBlack, 0x8007DC60
.definelabel osViSwapBuffer, 0x8007D900
.definelabel __osActiveQueue, 0x800A2DBC
.definelabel osSetEventMesg, 0x8007C2D0
.definelabel osRecvMesg, 0x8007C070
.definelabel osStopThread, 0x80086B70
.definelabel osCreateMesgQueue, 0x8007BF00
.definelabel osCreateThread, 0x8007C810
.definelabel osStartThread, 0x8007CAE0

.definelabel GWPlayer, 0x800FD2C0
.definelabel GWSystem, 0x800F93A8
.definelabel starAmountToEndGame, 0x800C7530
.definelabel coinAmountToEndGame, 0x800C7532