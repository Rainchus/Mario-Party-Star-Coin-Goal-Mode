mkdir obj
mips64-elf-gcc -Wall -O2 -mtune=vr4300 -march=vr4300 -mabi=32 -fomit-frame-pointer -G0 -c src/mp1.c
mv mp1.o obj/
armips asm/main.asm
n64crc "rom/mp1mod.z64"