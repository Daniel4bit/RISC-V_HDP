# Wearable Health Monitoring Device

## Project Overview:

This wearable health monitoring device utilizes an LM35 temperature sensor interfaced with an ADC0804 8-bit analog-to-digital converter (ADC) for accurate temperature measurement. The ADC0804 is controlled by a RISC-V processor, enabling data acquisition through its Chip Select (CS) and Read (RD) pins. The RISC-V processor retrieves digital temperature data from the ADC0804, processes it, and transmits the information to drive two 7-segment displays. These displays provide a user-friendly interface for viewing temperature readings in degrees Celsius.

In addition to temperature monitoring, this device serves as a comprehensive health tracker by integrating additional sensors for monitoring vital signs like heart rate, blood oxygen levels, and activity levels. The RISC-V processor handles data acquisition and processing from these sensors, providing real-time health metrics to the wearer.

To ensure efficient display control, activation signals for the segment driver transistors Q1 and Q2 are available from two pins of the microcontroller. This facilitates seamless operation and allows for precise control over the display output.

Designed for wearable applications, this device offers portability, comfort, and ease of use. Its compact form factor and low-power consumption make it suitable for continuous monitoring without causing discomfort to the user. With its ability to provide accurate and reliable health data, this wearable health monitoring device serves as a valuable tool for individuals seeking to track and improve their overall well-being.
### Components Needed:
1. RISCV Microcontroller with Required I/O
2. Temperature sensor (e.g., LM35 or DS18B20)
3. ADC0804
4. 7 segments or LCD display
5. Battery for power.
6. Buzzer.


### Blockdiagram

![Screenshot 2024-04-10 175423](https://github.com/Daniel4bit/RISC-V_HDP/assets/65249875/81b564ec-3213-4380-8117-0d6afafa9971)


