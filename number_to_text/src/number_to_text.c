#include "number_to_text.h"
#include <stdio.h>

// Function to print words for individual digits
void print_digits(int decimal_place) {
  switch (decimal_place) {
  case 0:
    printf("ZERO ");
    break;
  case 1:
    printf("ONE ");
    break;
  case 2:
    printf("TWO ");
    break;
  case 3:
    printf("THREE ");
    break;
  case 4:
    printf("FOUR ");
    break;
  case 5:
    printf("FIVE ");
    break;
  case 6:
    printf("SIX ");
    break;
  case 7:
    printf("SEVEN ");
    break;
  case 8:
    printf("EIGHT ");
    break;
  case 9:
    printf("NINE ");
    break;
  }
}

// Function to convert a number to words, and decide special input chases

void convert_to_words(int number) {

  // Extracting hundreds, tens, and ones places
  int hundreds = number / 100;
  int tens = (number % 100) / 10;
  int ones = number % 10;

  // Printing words for hundreds place if it is greater than 0
  if (hundreds > 0) {
    print_digits(hundreds);
  }

  // Printing words for tens place if it is greater than 0, or if there are
  // hundreds
  if (tens > 0 || hundreds > 0) {
    print_digits(tens);
  }

  // Printing words for ones place
  print_digits(ones);
}

// function to take user input and call the conversion function
int number_to_text() {
  int number;

  // Taking user input for a number between 0 and 999
  printf("Please enter a number between 0 and 999: ");
  scanf("%d", &number);

  // Validating the input range
  if (number < 0 || number > 999) {
    printf("Invalid input. Please enter a number between 0 and 999.\n");
    return 1; // Returning 1 to indicate error
  }

  // Calling the function to convert and print the number in words
  convert_to_words(number);

  printf("\n");

  return 0; // successful execution
}
