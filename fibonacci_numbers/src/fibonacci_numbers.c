#include "fibonacci_numbers.h"
#include <stdio.h>
#include <time.h>

int fibonacciRecursive(int n) {
  if (n <= 1) {
    return n;
  } else {
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
  }
}

int fibonacci_numbers() {
  int n, i;
  int summ_even = 0;
  int summ_odd = 0;
  int summ = 0;

  printf("Please enter the max value for calculating the even- and uneven sum "
         "of fibonacci-numbers: ");

  if (scanf("%d", &n) < 1 || n < 3) {
    printf("Enter a number that is 3 or greater.\n");
    return 0;
  }
  /*
    clock_t start_time = clock();
  */

  for (i = 2; i < n; i++) {

    if (fibonacciRecursive(i) < n) {
      if (fibonacciRecursive(i) % 2 == 0) {
        summ_even = summ_even + fibonacciRecursive(i);
      } else {
        summ_odd = summ_odd + fibonacciRecursive(i);
      }

      summ = summ + fibonacciRecursive(i);
      /*
           printf("%d, ", fibonacciRecursive(i));
     */

    } else {
      /*
      printf("\nSumm: %d \n", summ);
      printf("Summ of the even numbers: %d \n", summ_even);
      printf("Summ of the odd numbers: %d \n", summ_odd);

        clock_t end_time = clock();
        double time_taken = ((double)(end_time - start_time)) /
      CLOCKS_PER_SEC;

      printf("\nTime taken: %f seconds\n", time_taken);
     */
      printf("The sum of all Fibonacci-numbers not exceeding the entered max "
             "of %d is %d (even) and %d (odd)\n",
             n, summ_even, summ_odd);
      return 0;
    }
  }
  return 0;
}
