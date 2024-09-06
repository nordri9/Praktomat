#include "shuttle_sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Creates a new Shuttle node, initializes its fields, and returns it
Shuttle *create_shuttle(int mission_number, const char *start_date, const char *mission_designation, const char *orbiter, const char *launch_site)
{
    Shuttle *new_shuttle = (Shuttle *)malloc(sizeof(Shuttle));
    
    // Set the shuttle's attributes
    new_shuttle->mission_number = mission_number;
    strcpy(new_shuttle->start_date, start_date);
    strcpy(new_shuttle->mission_designation, mission_designation);
    strcpy(new_shuttle->orbiter, orbiter);
    strcpy(new_shuttle->launch_site, launch_site);
    
    // Initialize the next and prev pointers
    new_shuttle->prev = NULL;
    new_shuttle->next = NULL;
    return new_shuttle;
}

// Reads shuttle data from a text file and stores it in a doubly linked list
Shuttle *load_shuttle_data(const char *filename)
{
    FILE *file = fopen(filename, "r");
    
    // If the file cannot be opened, print an error message and return NULL
    if (!file)
    {
        printf("Error: Could not open file %s\n", filename);
        return NULL;
    }

    Shuttle *head = NULL; // Start of the linked list
    Shuttle *tail = NULL; // End of the linked list
    int mission_number;
    char start_date[11], mission_designation[20], orbiter[20], launch_site[10];

    char buffer[200];
    
    // Skip the first two lines (header information)
    fgets(buffer, sizeof(buffer), file);
    fgets(buffer, sizeof(buffer), file);

    // Read each line in the file and populate the linked list
    while (fscanf(file, "%d | %10s | %19s | %19s | %9s", &mission_number, start_date, mission_designation, orbiter, launch_site) == 5)
    {
        Shuttle *new_shuttle = create_shuttle(mission_number, start_date, mission_designation, orbiter, launch_site);

        // If this is the first shuttle, set it as head and tail
        if (head == NULL)
        {
            head = tail = new_shuttle;
        }
        else
        {
            // Append the new shuttle to the end of the list
            tail->next = new_shuttle;
            new_shuttle->prev = tail;
            tail = new_shuttle;
        }
    }

    fclose(file);
    return head;
}

// Splits a linked list into two halves and returns the second half
Shuttle *split(Shuttle *head)
{
    Shuttle *fast = head->next;  // Move this pointer twice as fast
    Shuttle *slow = head;        // Move this pointer at normal speed

    // Move fast and slow pointers to find the middle of the list
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    // The second half of the list starts from slow->next
    Shuttle *second_half = slow->next;
    slow->next = NULL;  // Split the list by setting the end of the first half to NULL
    return second_half;
}

// Merges two sorted linked lists into one
Shuttle *merge(Shuttle *first, Shuttle *second)
{
    // Base cases: If one list is empty, return the other
    if (!first)
        return second;
    if (!second)
        return first;

    // Compare the mission designations to merge the lists in order
    if (strcmp(first->mission_designation, second->mission_designation) <= 0)
    {
        // Recursively merge, adjusting the pointers
        first->next = merge(first->next, second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    }
    else
    {
        second->next = merge(first, second->next);
        second->next->prev = second;
        second->prev = NULL;
        return second;
    }
}

// Sorts the linked list using the merge sort algorithm
Shuttle *merge_sort(Shuttle *head)
{
    // Base case: If the list is empty or has only one element, it's already sorted
    if (!head || !head->next)
        return head;

    // Split the list into two halves
    Shuttle *second = split(head);

    // Recursively sort both halves
    head = merge_sort(head);
    second = merge_sort(second);

    // Merge the sorted halves and return the result
    return merge(head, second);
}

// Sorts the shuttle list by calling the merge_sort function
void sort_shuttles(Shuttle **head)
{
    if (!head || !*head)
        return;
    *head = merge_sort(*head);
}

// Prints the shuttle list in the specified format
void print_shuttles(Shuttle *head)
{
    if (!head)
        return;

    // Print the header
    printf("%-12s | %-11s | %-19s | %-10s | %s\n",
           "Missions-Nr.", "Start-Datum", "Missionsbezeichnung", " Orbiter", "Startrampe");
    printf("-------------------------------------------------------------------------\n");

    // Iterate through the list and print each shuttle's details
    Shuttle *current = head;
    while (current != NULL)
    {
        printf("%-12d | %-11s | %-19s | %-10s | %s\n",
               current->mission_number,
               current->start_date,
               current->mission_designation,
               current->orbiter,
               current->launch_site);
        current = current->next;
    }
}

// Frees the memory allocated for the shuttle list
void free_shuttles(Shuttle *head)
{
    Shuttle *current = head;
    Shuttle *next;

    // Traverse the list and free each node
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
}
