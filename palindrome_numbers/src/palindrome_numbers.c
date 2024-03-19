#include "palindrome_numbers.h" // Including header file for function prototypes

#include <stdio.h> // Including standard input/output library

// Function to check if a number is a palindrome
int isPalindrome(int n) {
  int original = n; // Storing the original number
  int reversed = 0; // Initializing variable to store the reversed number

  // Reversing the digits of the number
  while (n > 0) {
    int remainder = n % 10; // Extracting the last digit
    reversed =
        reversed * 10 + remainder; // Appending the digit to the reversed number
    n /= 10;                       // Removing the last digit
  }

  // Checking if the original number is equal to its reverse
  return original == reversed;
}

// Function to find the highest palindrome as a product of two numbers in a
// given range
void findHighestPalindrome(int start, int end) {
  int maxPalindrome = -1; // Variable to store the highest palindrome found
  int factor1,
      factor2; // Variables to store the factors that produce the palindrome

  // Loop through all pairs of numbers in the given range
  for (int i = start; i <= end; i++) {
    for (int j = start; j <= end; j++) {
      int product = i * j; // Calculating the product of the two numbers
      // Checking if the product is a palindrome and if it's greater than the
      // current maximum palindrome
      if (isPalindrome(product) && product > maxPalindrome) {
        maxPalindrome = product; // Updating the maximum palindrome
        factor1 = i;             // Storing the first factor
        factor2 = j;             // Storing the second factor
      }
    }
  }

  // Printing the result
  if (maxPalindrome != -1)
    printf("The highest palindrome as a product of %d and %d is %d\n", factor1,
           factor2, maxPalindrome);
  else
    printf("No palindrome found!\n");
}

// Function to get input from the user and print the highest palindrome
int printPalindrome() {
  int start, end;
  printf("Please enter the range of numbers - multiplied with each other - to "
         "get the highest palindrome: \n");
  // Getting input from the user and checking for errors
  if (scanf("%d %d", &start, &end) != 2 || start < 100 || end > 999 ||
      start > end) {
    printf("Wrong input!\n"); // Printing error message for invalid input
    return 1;
  }

  findHighestPalindrome(start,
                        end); // Finding and printing the highest palindrome

  return 0; // Returning success
}