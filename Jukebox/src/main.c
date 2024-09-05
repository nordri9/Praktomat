#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jukebox.h"


#define MAX_LINE_LENGTH 256

// Function prototype
void Track_Search(FILE *file, const char *searchString);

int main() {
    char fileName[MAX_LINE_LENGTH];
    char searchString[MAX_LINE_LENGTH];
    FILE *file;

    // Prompt the user for the file name
    printf("Please enter a Jukebox file name: ");
    fgets(fileName, MAX_LINE_LENGTH, stdin);
    // Remove newline character from fileName
    fileName[strcspn(fileName, "\n")] = 0;

    // Open the file
    file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", fileName);
        return 1;
    }

    // Prompt the user for the search string
    printf("Please enter a search string: ");
    fgets(searchString, MAX_LINE_LENGTH, stdin);
    // Remove newline character from searchString
    searchString[strcspn(searchString, "\n")] = 0;

    // Perform the search
    Track_Search(file, searchString);

    // Close the file
    fclose(file);

    return 0;
}


