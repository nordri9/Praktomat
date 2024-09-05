// main.c
#include <stdio.h>
#include "shuttle_sort.h"

int main()
{
    Shuttle *shuttle_list = load_shuttle_data("src/shuttle_data.txt");

    if (shuttle_list == NULL)
    {
        return 1; // Exit if there's an error loading the file
    }

    // Sort the list alphabetically by mission designation
    sort_shuttles(&shuttle_list);

    // Print the sorted shuttle list
    print_shuttles(shuttle_list);

    // Free the list
    free_shuttles(shuttle_list);

    return 0;
}
