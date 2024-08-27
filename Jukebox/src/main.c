#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// Function to search for tracks in the file
void Track_Search(FILE *file, const char *searchString) {
    char line[MAX_LINE_LENGTH];
    int trackNumber = 0;

    // Read the file line by line
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        trackNumber++;
        // Check if the search string is in the current line
        if (strstr(line, searchString) != NULL) {
            // Print the matching track
            printf("Track %d: %s", trackNumber, line);
        }
    }
}
