#include "shuttle_sort.h"

// shuttle.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to create a new shuttle node
Shuttle *create_shuttle(int mission_number, const char *start_date, const char *mission_designation, const char *orbiter, const char *launch_site)
{
    Shuttle *new_shuttle = (Shuttle *)malloc(sizeof(Shuttle));
    new_shuttle->mission_number = mission_number;
    strcpy(new_shuttle->start_date, start_date);
    strcpy(new_shuttle->mission_designation, mission_designation);
    strcpy(new_shuttle->orbiter, orbiter);
    strcpy(new_shuttle->launch_site, launch_site);
    new_shuttle->prev = NULL;
    new_shuttle->next = NULL;
    return new_shuttle;
}

// Function to load shuttle data from a file and create a linked list
Shuttle *load_shuttle_data(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        printf("Error: Could not open file %s\n", filename);
        return NULL;
    }

    Shuttle *head = NULL;
    Shuttle *tail = NULL;
    int mission_number;
    char start_date[11], mission_designation[20], orbiter[20], launch_site[10];

    // Skip the header lines
    char buffer[200];
    fgets(buffer, sizeof(buffer), file);
    fgets(buffer, sizeof(buffer), file);

    // Read shuttle data
    while (fscanf(file, "%d | %10s | %19s | %19s | %9s", &mission_number, start_date, mission_designation, orbiter, launch_site) == 5)
    {
        Shuttle *new_shuttle = create_shuttle(mission_number, start_date, mission_designation, orbiter, launch_site);

        if (head == NULL)
        {
            head = tail = new_shuttle;
        }
        else
        {
            tail->next = new_shuttle;
            new_shuttle->prev = tail;
            tail = new_shuttle;
        }
    }

    fclose(file);
    return head;
}

// Function to split a linked list into two halves
Shuttle *split(Shuttle *head)
{
    Shuttle *fast = head->next;
    Shuttle *slow = head;

    // Move fast pointer two nodes and slow pointer one node at a time
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    Shuttle *second_half = slow->next;
    slow->next = NULL;
    return second_half;
}

// Function to merge two sorted linked lists
Shuttle *merge(Shuttle *first, Shuttle *second)
{
    if (!first)
        return second;
    if (!second)
        return first;

    // Compare mission designations and merge in ascending order
    if (strcmp(first->mission_designation, second->mission_designation) <= 0)
    {
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

// Function to perform merge sort on the linked list
Shuttle *merge_sort(Shuttle *head)
{
    if (!head || !head->next)
        return head;

    Shuttle *second = split(head);

    // Recursively sort both halves
    head = merge_sort(head);
    second = merge_sort(second);

    // Merge the sorted halves
    return merge(head, second);
}

// Function to sort shuttles using merge sort
void sort_shuttles(Shuttle **head)
{
    if (!head || !*head)
        return;
    *head = merge_sort(*head);
}

// Function to print the sorted shuttle list
void print_shuttles(Shuttle *head)
{
    if (!head)
        return;

    // Print table header with aligned columns
    printf("%-12s | %-11s | %-19s | %-10s | %s\n",
           "Missions-Nr.", "Start-Datum", "Missionsbezeichnung", " Orbiter", "Startrampe");
    printf("-------------------------------------------------------------------------\n");

    Shuttle *current = head;
    while (current != NULL)
    {
        // Print each shuttle's information with formatted columns
        printf("%-12d | %-11s | %-19s | %-10s | %s\n",
               current->mission_number,
               current->start_date,
               current->mission_designation,
               current->orbiter,
               current->launch_site);
        current = current->next;
    }
}

// Function to free the allocated memory for the linked list
void free_shuttles(Shuttle *head)
{
    Shuttle *current = head;
    Shuttle *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
}
