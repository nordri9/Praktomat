#include <stdio.h>
#include <stdlib.h>
#include "node.h"

Node *Node_New(void) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("No memory\n");
        return NULL;
    }
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void Node_Insert(Node *head, Node *newNode) {
    if (head == NULL) {
        head = newNode;
    } else {
        Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void Output_Tour(Node *tour) {
    Node *current = tour;
    while (current != NULL) {
        Output_Island(current->island);
        current = current->next;
    }
    printf("End\n");
}
