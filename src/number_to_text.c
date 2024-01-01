#include <stdio.h>
#include "number_to_text.h"

void printDigit(int digit)
{
}

void convertToWords(int number)
{
    int hundreds = number / 100;
    int tens = (number % 100) / 10;
    int ones = number % 10;

    if (hundreds > 0)
    {
        switch (hundreds)
        {
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
        switch (tens)
        {
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

        if (tens > 0)
        {
        }
    }
    switch (ones)
    {
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

int number_to_text()
{
    int number;

    // Eingabe
    printf("Please enter a number between 0 and 999: ");
    scanf("%d", &number);

    // Überprüfen, ob die eingegebene Zahl im gültigen Bereich liegt
    if (number < 0 || number > 999)
    {
        printf("Invalid input. Please enter a number between 0 and 999.\n");
        return 1; // Fehlercode
    }

    // Ausgabe
    convertToWords(number);

    return 0; // Erfolgreich beendet
}
