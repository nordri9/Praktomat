#include "digits.h"
#include <stdio.h>

int digits();
unsigned long long calculateSeries(int n);
void printLastDigits(unsigned long long number);

// Function to calculate the sum of the numbers k^k
unsigned long long calculateSeries(int n) {
  unsigned long long sum = 0;

  // Loop through each value of k from 1 to n
  for (int k = 1; k <= n; k++) {
    unsigned long long term = 1;

    // Calculate k^k and use modulo to prevent overflow
    for (int i = 0; i < k; i++) {
      term *= k;
      term %= 100000000; // Use modulo to prevent overflow
    }

    // Add the calculated term to the sum and use modulo
    sum += term;
    sum %= 100000000; // Use modulo to prevent overflow
  }

  return sum;
}

// Function to print the last eight digits of the calculated number
void printLastDigits(unsigned long long number) {
  // Use printf to format the output with leading zeros if needed
  printf("The last digits of the series are %08llu\n", number);
}

int digits() {
  int highestValue;

  // User input prompt
  printf("Please enter the highest value, which will be selected: ");
  // Read the user input into the variable highestValue
  scanf("%d", &highestValue);

  // Calculate the number according to the given instructions
  unsigned long long result = calculateSeries(highestValue);

  // Print the last eight digits of the calculated number
  printLastDigits(result);

  return 0;
}
