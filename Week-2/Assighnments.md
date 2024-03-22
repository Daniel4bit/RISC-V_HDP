# Assignment

## Using RISC-V GCC compiler (riscv64-unknown-elf-gcc) to compile a C source file (Counter.c) into an object file (Counter.o).
` riscv64-unknown-elf-gcc -march=rv64i -mabi=lp64 -ffreestanding -o ./Counter.o Counter.c`

` spike pk Counter.o` 


Let's break down the options used:

-march=rv64i: This specifies the RISC-V architecture variant to target. In this case, it's rv64i, indicating a 64-bit RISC-V ISA with the base integer instruction set (I).

-mabi=lp64: This specifies the ABI (Application Binary Interface) to use. lp64 stands for "long" and "pointer", indicating that int and long are 64 bits wide, as well as pointers.

-ffreestanding: This option tells the compiler that the program does not require a standard library, which is typical for embedded systems or kernels.

-o ./Counter.o: This specifies the output file name (Counter.o) for the compiled object file.

## Code for Counter.C
``` #include <stdio.h>
#include <time.h>

void delay(int n) {
    int us = n; // microseconds
    clock_t start_time = clock();
    while (clock() < start_time + (us * CLOCKS_PER_SEC / 1000000));
}

void display(int count) // Function to display the data on the four Led's
{
	printf("Count value is: %d\n", count);						
}

int main()
{
	int count = 0x00000000;
	while (1)
	{
		display(count);
		count++;
        if(count==16){
            count=0;
        }
		delay(500000);   // delay by 0.5 microseconds
	}
}
```

## SPIKE SIMULATION
![Screenshot from 2024-03-21 18-27-16](https://github.com/Daniel4bit/RISC-V_HDP/assets/65249875/3ae13397-a005-43b2-a6ee-3665b28dce02)


## Assignment 2

Measure CPU performance of all the programs mentioned above using either godbolt or RISC-V disassembler.
Command

` riscv64-unknown-elf-gcc -march=rv32i -mabi=ilp32 -ffreestanding -o ./Counter.o Counter.c`

` riscv64-unknown-elf-objdump -d -r Counter.o > Counter_assembly.txt`

Let us assume the number of clock cycles for the RISC-V instructions.

Instructions associated with add : 2 cycles.

Instructions associated with mul, div, load, store, and move: 3 cycles.

Instructions associated with jump, and branch: 4 cycles.

All other Instructions: 2 cycles.

### Counter

CPU performance

addi	sp,sp,-32 -> 2 cycles
sd	ra,24(sp) -> 3 cycles
sd	s0,16(sp) -> 3 cycles
addi	s0,sp,32 -> 2 cycles
sw	zero,-20(s0) -> 3 cycles 

Clock cycle per instruction (CPI) = Total number of clock cycles / Number of instructions

So, CPI will be 13 / 5 = 2.6.

Now, CPU time = CPI x Number of instructions for a program x Clock cycle time (T)

Let's assume, T = 100ps.

So, CPU time = 2.6 x 5 x 100ps = 2600ps or 1.3ns.

