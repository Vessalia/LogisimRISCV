# LogisimRISCV
Logisim Simulation of a RISC-V computer

## How to Build
Build by navigating to `LogisimRISCV/build/` and executing:
```
cmake ..
cmake --build .
```

## Running Programs
Run the desired program by executing:
```
./build/bin/launcher [logisim|rars]
```
for either Logisim-Evolution, or RARS.

## Loading the Simulation
Simply run the Logisim-Evolution program, and open the `riscv_simulator.circ` file

## Loading Programs
In the RARS program: 
- Write your desired program
- Assemble the program
- Dump the binary file into the desired folder
  
Then in the Logisim simulation:
- Right-click on the instruction RAM
- Click `Load Image...`
- Select the dumped binary file
- Load using `Little-Endian`

Finally, either cycle the clock manually, or let the simulation run!

## Simulation Details
- To reset the computer, set the `RestSim` pin to 1, the cycle the clock
- When reset, the PC will point to the memory location indicated by `orig`, ensure your program starts here
- Only a subset of the instructions are defined, these include:
```
Arithmetic:
- ADD  / ADDI
- SUB  / SUBI
- SLL  / SLLI
- SLTU / SLLI
- XOR  / XORI
- SRL  / SRLI
- SRA  / SRAI
- OR   / ORI
- AND  / ANDI

Load/Store:
- LB/LH/LW
- SB/SH/SW

Branching:
- BEQ
- BNE
- BLT
- BGE
- BLTU
- BGEU

Addressing Modes:
- LUI
- AUIPC

Jumps:
- JAL
- JALR
```

Missing/to be added from the "base" set:
```
- LBU/LHU
- ECALL
- EBREAK
- xRET
- WFI
- CSRRW
- FENCE
```

Additionally, traps and privilege levels are to be added.
