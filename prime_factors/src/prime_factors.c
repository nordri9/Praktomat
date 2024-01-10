#include "prime_factors.h"
#include <stdio.h>

// Funktion zur Primfaktorzerlegung
unsigned long long int prime_factors(unsigned long long int zahl) {
  unsigned long long int i = 2;
  // Schleife zum Finden der Primfaktoren
  for (; i <= zahl; i++) {
    while (zahl % i == 0) {
      // printf("%d ", i);
      zahl /= i;
    }
  }

  return i - 1;
}

unsigned long long int print_number() {
  unsigned long long int num;

  // Benutzereingabe
  printf("Please enter the number which should be factorized: ");
  scanf("%lld", &num);

  if (num <= 2) {
    printf("The entered number is invalid!\n");
    return 1;
  }
  // Primfaktorzerlegung aufrufen
  printf("Highest prime factor of %lld is %lld\n", num, prime_factors(num));

  return 0;
}