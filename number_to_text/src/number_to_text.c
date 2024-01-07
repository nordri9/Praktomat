#include "number_to_text.h"
#include <stdio.h>

// Function to convert a number to words
void convertToWords(int number) {
  // Extracting digits from the number
  int hundreds = number / 100;
  int tens = (number % 100) / 10;
  int ones = number % 10;

  // Handling hundreds place
  if (hundreds > 0) {
    switch (hundreds) {
    // Printing words for digits 1 to 9 in the hundreds place
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

  // Handling tens place
  switch (tens) {
  // Printing words for digits 1 to 9 in the tens place
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

  // Special case: If tens place is 0 and hundreds place is greater than 0
  if (tens == 0 && hundreds > 0) {
    printf("ZERO ");
  }

  // Handling ones place
  switch (ones) {
  // Printing words for digits 0 to 9 in the ones place
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

// Main function to get user input and call the conversion function
int number_to_text() {
  int number;

  // User input
  printf("Please enter a number between 0 and 999: ");
  scanf("%d", &number);

  // Checking if the entered number is within the valid range
  if (number < 0 || number > 999) {
    printf("Invalid input. Please enter a number between 0 and 999.\n");
    return 1; // Error code
  }

  // Output the number in words
  convertToWords(number);
  printf("\n");
  return 0; // Successfully completed
}
