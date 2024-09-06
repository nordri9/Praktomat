#include "jukebox.h"

// This function searches for the provided search string in the given file
void Track_Search(FILE *file, const char *searchString, const unsigned int max_line_length)
{
    char line[max_line_length]; // Buffer to store each line read from the file
    int trackNumber = 0;        // Variable to keep track of the track number (line number)

    // Read the file line by line
    while (fgets(line, max_line_length, file) != NULL)
    {
        trackNumber++; // Increment the track number for each line read

        // Check if the search string is found in the current line
        if (strstr(line, searchString) != NULL)
        {
            // If found, print the track number and the corresponding line
            printf("Track %d: %s", trackNumber, line);
        }
    }
}
