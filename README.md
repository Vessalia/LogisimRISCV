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
