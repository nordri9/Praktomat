#include "island.h"

int main()
{
    int tour_number;

    while (1)
    {
        printf("Please enter a tour number (1-4) or enter the number 0 to exit the program: ");
        scanf("%d", &tour_number);

        if (tour_number == 0)
        {
            break;
        }
        else if (tour_number >= 1 && tour_number <= 4)
        {
            Tour *tour = initialize_tour(tour_number);
            if (tour != NULL)
            {
                print_tour(tour, tour_number);
                free_tour(tour);
            }
        }
        else
        {
            printf("Invalid tour number. Please try again.\n");
        }
    }

    return 0;
}
