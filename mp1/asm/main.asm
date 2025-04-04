.n64 // Let armips know we're coding for the N64 architecture
.open "rom/mp1.z64", "rom/mp1mod.z64", 0 // Open the ROM file
.include "asm/mp1.asm" // Include mp1.asm to tell armips' linker where to find the game's function(s)
// Set the displacement between ROM and RAM addresses
.include "asm/patchBoot.asm" //include modified boot code
.close // Close the ROM file