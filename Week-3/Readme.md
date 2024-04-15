# Wearable Health Monitoring Device

## Project Overview:

Abstract:
This C program, designed for wearable health monitoring, accepts input from a temperature sensor. The input data consists of four boolean values representing temperature readings. Each boolean value corresponds to a sensor output, capturing different aspects of temperature. The program's output is directed to a seven-segment display, where the temperature value is visually represented. This implementation underscores the seamless integration of input from a temperature sensor into a compact wearable device, culminating in a clear and concise visual display of temperature information on the seven-segment interface.
### Components Needed:
1. RISCV Microcontroller with Required I/O
2. Temperature sensor (e.g., LM35 or DS18B20)
3. 4 bit ADC
4. 7 segments or LCD display
5. Battery for power.


### Blockdiagram
![adc](https://github.com/Daniel4bit/RISC-V_HDP/assets/65249875/fcf3ed61-966d-44d1-beed-f04129e50c1f)

### C-Code
```
#include <stdio.h>
// Function to display a digit on a seven-segment display
void displayDigit(int digit) {
    // Define patterns for each digit
    const int patterns[10][7] = {
        {1, 1, 1, 1, 1, 1, 0},  // 0
        {0, 1, 1, 0, 0, 0, 0},  // 1
        {1, 1, 0, 1, 1, 0, 1},  // 2
        {1, 1, 1, 1, 0, 0, 1},  // 3
        {0, 1, 1, 0, 0, 1, 1},  // 4
        {1, 0, 1, 1, 0, 1, 1},  // 5
        {1, 0, 1, 1, 1, 1, 1},  // 6
        {1, 1, 1, 0, 0, 0, 0},  // 7
        {1, 1, 1, 1, 1, 1, 1},  // 8
        {1, 1, 1, 0, 0, 1, 1}   // 9
    };

    printf("Displaying digit: %d\n", digit);
    printf("Segment pattern: ");
    for (int i = 0; i < 7; i++) {
        printf("%d ", patterns[digit][i]);
    }
    printf("\n");
    // Here you would write code to drive your seven-segment display using these individual bits
}

int main() {
    int input[4];

    // Accept inputs
    printf("Enter 4 boolean inputs (0 or 1) representing temperature sensor outputs:\n");
    for (int i = 0; i < 4; ++i) {
        printf("Input %d: ", i + 1);
        scanf("%d", &input[i]);
    }

    // Convert binary input to decimal
    int digit = input[0] * 8 + input[1] * 4 + input[2] * 2 + input[3];

    // Display the digit on the seven-segment display
    if (digit >= 0 && digit <= 9) {
        displayDigit(digit);
    } else {
        printf("Invalid input. Please enter a 4-bit binary number.\n");
    }

    return 0;
}
```
## Register architecture of x30 for GPIOs
+Input Signals -Adc 1-4;

+Output Signals - seven segment [e1-e7];

+Number of Register bits Required - 11

+Register bits allocations are given below

+x30 [2:0] is Adc - Adc 1 - x30[0]; Adc 2 - x30[1]; Adc 3 - x30[2]; Adc 4 - x30[3]; // Input - Read

+x30 [10:4] is e1 & e7 - e1 x30 [4] ; e2 x30 [5] ; e3 x30 [6] ;e4 x30 [7] ;e5 x30 [8] ;e6 x30 [9] ;e7 x30 [9] ;// Output Write


```
#include <stdio.h>
// Function to display a digit on a seven-segment display
void displayDigit(int digit) {
    // Define patterns for each digit

    const int patterns[10][7] = {
        {1, 1, 1, 1, 1, 1, 0},  // 0
        {0, 1, 1, 0, 0, 0, 0},  // 1
        {1, 1, 0, 1, 1, 0, 1},  // 2
        {1, 1, 1, 1, 0, 0, 1},  // 3
        {0, 1, 1, 0, 0, 1, 1},  // 4
        {1, 0, 1, 1, 0, 1, 1},  // 5
        {1, 0, 1, 1, 1, 1, 1},  // 6
        {1, 1, 1, 0, 0, 0, 0},  // 7
        {1, 1, 1, 1, 1, 1, 1},  // 8
        {1, 1, 1, 0, 0, 1, 1}   // 9
    };

    printf("Displaying digit: %d\n", digit);
    printf("Segment pattern: ");
    for (int i = 0; i < 7; i++) {
        printf("%d ", patterns[digit][i]);
asm volatile(
		"and x30,x30,%1\n\t"
	    	"li x30, patterns[digit][i] \n\t "
             ori %0, x30 \n\t "
	    	:
	    	:"=r"(digit[i]),"r"(mask)
	    	:"x30"
	    	);

    }
    printf("\n");
    // Here you would write code to drive your seven-segment display using these individual bits
}

int main() {
    int input[4];

    // Accept inputs
    printf("Enter 4 boolean inputs (0 or 1) representing temperature sensor outputs:\n");
  int mask=0xFFFFF800;
    for (int i = 0; i < 4; ++i) {
        printf("Input %d: ", i + 1);
        asm volatile(
		"and x30,x30,%1\n\t"
	    	"or x30, x30, %0\n\t"
	    	:
	    	:"r"(input[i]),"r"(mask)
	    	:"x30"
	    	);
  }

    // Convert binary input to decimal
    int digit = input[0] * 8 + input[1] * 4 + input[2] * 2 + input[3];

    // Display the digit on the seven-segment display
    if (digit >= 0 && digit <= 9) {
        displayDigit(digit);
    } else {
        printf("Invalid input. Please enter a 4-bit binary number.\n");
    }

    return 0;
}
```
