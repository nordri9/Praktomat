#include <stdio.h>
#include "shuttle_sort.h"

int main()
{
    // Load shuttle data from the text file into a linked list
    Shuttle *shuttle_list = load_shuttle_data("shuttle_data.txt");

    // If the file could not be opened or list is empty, exit with an error code
    if (shuttle_list == NULL)
    {
        return 1;
    }

    // Sort the shuttle list by mission designation
    sort_shuttles(&shuttle_list);

    // Print the sorted shuttle list to the console
    print_shuttles(shuttle_list);

    // Free the memory allocated for the shuttle list
    free_shuttles(shuttle_list);

    return 0;
}
