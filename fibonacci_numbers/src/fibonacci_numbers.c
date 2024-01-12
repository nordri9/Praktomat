#include "fibonacci_numbers.h"
#include <stdio.h>

// Function to calculate Fibonacci numbers recursively
int fibonacciRecursive(int n) {
  if (n <= 1) {
    return n;
  } else {
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
  }
}

// Function to calculate and display the sum of even and odd Fibonacci numbers
int fibonacci_numbers() {
  int n, i;
  int summ_even = 0; // Sum of even Fibonacci numbers
  int summ_odd = 0;  // Sum of odd Fibonacci numbers
  int summ = 0;      // Total sum of Fibonacci numbers

  // Prompt the user to enter the maximum value for calculating Fibonacci
  // numbers
  printf("Please enter the max value for calculating the even- and odd sum "
         "of Fibonacci numbers: ");

  // Read the user input for the maximum value
  if (scanf("%d", &n) < 1 || n < 3) {
    // If input is invalid or less than 3, prompt the user to enter a valid
    // number
    printf("Enter a number that is 3 or greater.\n");
    return 0;
  }

  // Iterate through Fibonacci numbers until reaching the specified maximum
  // value
  for (i = 2; i < n; i++) {

    // Check if the current Fibonacci number is less than the maximum value
    if (fibonacciRecursive(i) < n) {

      // Check if the current Fibonacci number is even
      if (fibonacciRecursive(i) % 2 == 0) {
        summ_even =
            summ_even +
            fibonacciRecursive(i); // Add to the sum of even Fibonacci numbers
      } else {
        summ_odd = summ_odd + fibonacciRecursive(
                                  i); // Add to the sum of odd Fibonacci numbers
      }

      summ = summ +
             fibonacciRecursive(i); // Add to the total sum of Fibonacci numbers

    } else {

      // Display the sum of even and odd Fibonacci numbers not exceeding the
      // maximum value
      printf("The sum of all Fibonacci numbers not exceeding the entered max "
             "of %d is %d (even) and %d (odd)\n",
             n, summ_even, summ_odd);
      return 0;
    }
  }

  return 0; 
}
