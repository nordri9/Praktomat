#include "prime_factors.h"
#include <stdio.h>

// Funktion zur Primfaktorzerlegung
unsigned int prime_factors(unsigned int zahl) {
  int i = 2;
  // Schleife zum Finden der Primfaktoren
  for (; i <= zahl; i++) {
    while (zahl % i == 0) {
      // printf("%d ", i);
      zahl /= i;
    }
  }

  return i - 1;
}

unsigned print_number() {
  unsigned num;

  // Benutzereingabe
  printf("Please enter the number which should be factorized: ");
  scanf("%d", &num);


  if (prime_factors(num) == num || num <= 0) {
    printf("The entered number is invalid!\n");
    return 1;
  }
  // Primfaktorzerlegung aufrufen
  printf("Highest prime factor of %d is %d\n", num, prime_factors(num));

  return 0;
}