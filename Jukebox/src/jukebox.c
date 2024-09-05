#include "jukebox.h"

#define MAX_LINE_LENGTH 256

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