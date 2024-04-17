// #include <stdio.h>

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

   // printf("Displaying digit: %d\n", digit);
   // printf("Segment pattern: ");
    for (int i = 0; i < 7; i++) {
     //   printf("%d ", patterns[digit][i]);
    }
 //   printf("\n");
}

int main() {
    int input[4];
    int mask = 0xFFFFF800; // Define mask for inputs

    // Accept inputs
   // printf("Enter 4 boolean inputs (0 or 1) representing temperature sensor outputs:\n");
    for (int i = 0; i < 4; ++i) {
      //  printf("Input %d: ", i + 1);
     //   scanf("%d", &input[i]);
        input[i] &= mask; // Apply the mask to input
    }

    // Convert binary input to decimal
    int digit = input[0] * 8 + input[1] * 4 + input[2] * 2 + input[3];

    // Display the digit on the seven-segment display
    if (digit >= 0 && digit <= 9) {
        displayDigit(digit);
    } else {
      //  printf("Invalid input. Please enter a 4-bit binary number.\n");
    }

    return 0;
}

