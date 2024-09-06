#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jukebox.h"

#define MAX_LINE_LENGTH 256 // Define the maximum length of a line in the text file

int main()
{
    char fileName[MAX_LINE_LENGTH];     // Buffer to store the file name entered by the user
    char searchString[MAX_LINE_LENGTH]; // Buffer to store the search string entered by the user
    FILE *file;                         // File pointer to handle the file

    // Prompt the user to enter the name of the jukebox file
    printf("Please enter a Jukebox file name: ");
    fgets(fileName, MAX_LINE_LENGTH, stdin); // Read the file name from user input
    fileName[strcspn(fileName, "\n")] = 0;   // Remove the trailing newline character from the input

    // Try to open the file in read mode
    file = fopen(fileName, "r");
    if (file == NULL)
    { // Check if the file could not be opened
        printf("Error: Could not open file %s\n", fileName);
        return 1; // Return with an error code
    }

    // Prompt the user to enter the search string (e.g., artist or track name)
    printf("Please enter a search string: ");
    fgets(searchString, MAX_LINE_LENGTH, stdin);   // Read the search string from user input
    searchString[strcspn(searchString, "\n")] = 0; // Remove the trailing newline character from the input

    // Call the Track_Search function to search for the specified string in the file
    Track_Search(file, searchString, MAX_LINE_LENGTH);

    // Close the file after search is complete
    fclose(file);

    return 0; // Return success
}
