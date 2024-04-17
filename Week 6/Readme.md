# Commands to do iverilog Simulation
```
iverilog -o Wearable_v testbench.v processor.v
vvp Wearable_v
```
![VCD FIle generation](https://github.com/Daniel4bit/RISC-V_HDP/assets/65249875/ab7fa986-0907-499e-8783-376e6e9f8250)

## Simulation Result

![GatelevelSimulation](https://github.com/Daniel4bit/RISC-V_HDP/assets/65249875/f42e7025-08a8-40cc-be64-74cdb913c52c)

# Synthesis
Commands
```
read_liberty -lib sky130_fd_sc_hd__tt_025C_1v80_256.lib
read_verilog processor.v
synth -top wrapper
abc -liberty sky130_fd_sc_hd__tt_025C_1v80_256.lib
dfflibmap -liberty sky130_fd_sc_hd__tt_025C_1v80_256.lib
write_verilog synth_processor.v
show wrapper

```

### abc Command output
![abc](https://github.com/Daniel4bit/RISC-V_HDP/assets/65249875/83588c22-4346-4cad-956d-9275f627026c)

### Schematic
![RTL Schematic](https://github.com/Daniel4bit/RISC-V_HDP/assets/65249875/6c5070b6-6f6b-45c4-aba4-4b3a74744756)

# GateLevel Simulation Output

![Gatelevel Simulation](https://github.com/Daniel4bit/RISC-V_HDP/assets/65249875/8ec7c5a9-9a35-4480-8e77-abc7f9a3d4b6)
