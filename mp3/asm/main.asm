.n64 // Let armips know we're coding for the N64 architecture
.open "rom/mp3.z64", "rom/mp3mod.z64", 0 // Open the ROM file
.include "asm/mp3.asm" // Include mp3.asm to tell armips' linker where to find the game's function(s)
// Set the displacement between ROM and RAM addresses
.include "asm/patchBoot.asm" //include modified boot code
.close // Close the ROM file