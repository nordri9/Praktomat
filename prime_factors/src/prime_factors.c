#include "prime_factors.h"
#include <stdio.h>

// Function to calculate the highest prime factor of a given number
unsigned long int prime_factors(unsigned long int zahl) {
  unsigned long int i = 2;

  // Loop through potential prime factors starting from 2
  for (; i <= zahl; i++) {
    // Check if 'i' is a factor of the number
    while (zahl % i == 0) {
      // Divide the number by 'i' as long as it's a factor
      zahl /= i;
    }
  }

  // 'i' will be one more than the highest prime factor found
  return i - 1;
}

// Function to take user input and print the highest prime factor
int print_number() {
  unsigned long int num;

  // Prompt the user to enter a number
  printf("Please enter the number which should be factorized: ");
  scanf("%lu", &num);

  // Check if the entered number is less than or equal to 3
  if (num <= 3) {
    printf("The entered number is invalid!");
    return 1; // Return 1 to indicate an error
  }

  // Print the highest prime factor of the entered number
  printf("Highest prime factor of %lu is %lu", num, prime_factors(num));

  return 0;
}
