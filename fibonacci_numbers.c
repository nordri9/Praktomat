#include "fibonacci_numbers.h"
#include <stdio.h>

// Recursive function to calculate the nth Fibonacci number
int fibonacciRecursive(int n) {
  if (n <= 1) {
    return n;
  } else {
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
  }
}

// Function to calculate the sum of even and odd Fibonacci numbers up to a given
// maximum
int fibonacci_numbers() {
  int n, i;
  int summ_even = 0; // Sum of even Fibonacci numbers
  int summ_odd = 0;  // Sum of odd Fibonacci numbers
  int summ = 0;      // Total sum of Fibonacci numbers

  // Prompting the user to enter the maximum value for calculating the sums
  printf("Please enter the max value for calculating the even- and odd sum "
         "of Fibonacci numbers: ");

  // Reading user input for the maximum value
  if (scanf("%d", &n) < 1 || n < 3) {
    // If the input is invalid or less than 3, prompt the user to enter a valid
    // number
    printf("Enter a number that is 3 or greater.");
    return 1;
  }

  // Loop to calculate the sums of even and odd Fibonacci numbers
  for (i = 2; i < n; i++) {
    // Check if the current Fibonacci number is less than the maximum value
    if (fibonacciRecursive(i) < n) {
      // Update sums based on whether the current Fibonacci number is even or
      // odd
      if (fibonacciRecursive(i) % 2 == 0) {
        summ_even = summ_even + fibonacciRecursive(i);
      } else {
        summ_odd = summ_odd + fibonacciRecursive(i);
      }

      // Update the total sum
      summ = summ + fibonacciRecursive(i);

    } else {
      // If the current Fibonacci number exceeds the maximum value, print the
      // results
      printf("The sum of all Fibonacci numbers not exceeding the entered max "
             "of %d is %d (even) and %d (odd)",
             n, summ_even, summ_odd);
      return 0;
    }
  }
  return 0;
}
