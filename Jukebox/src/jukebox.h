#ifndef jukebox_H
#define jukebox_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototype for Track_Search
// Searches the file for tracks or artists matching the search string
void Track_Search(FILE *file, const char *searchString, const unsigned int max_line_length);

#endif
