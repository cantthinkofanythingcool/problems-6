#include "ds_utils.h"

/*
 *14, 15
 * 1. simulate the undo and redo options in word packages using a doubly linked list
2. given two sorted lists l1 and l2 write a procedure to compute l1 intersect l2 and l1 union l2
3. swap two eelemnts by adjusting only the pointers and not the data using doubly linked lists
4. write an array implementation of self adjusting list. all the insertinos are performed at the front and when an element is accessed by a find it is moved to the front
5. to reverse a doubly linked list
6. to delete the middle element of a doubly linked list
 7. remove duplicates from a sorted and unsorted dll
8. calculate the frequency count of a given integer in a circular dll
9. searc for a particular element in a binary tree
10. calculate hte heignt or depth of a tree and print
11. given a binary tree convert this a doubly linked list keping the same order
12. given a binary tree, connect the nodes that are the same level using the next right pointer
13. implement priority queue using binary search tree and perform insert
14. in a given biinary search tree write routines to delete a node with no children, one or two children
 15. convert the given prefix ecpression to an expresion tree
16. construct binary srarch tree using 1) inorder node representation 2) preorder and 3) postorder*/
typedef struct State {
    char text[100];
    struct State* prev;
    struct State* next;
} State;

State* createState(const char* text) {
    State* node = (State*)malloc(sizeof(State));
    strcpy(node->text, text);
    node->prev = node->next = NULL;
    return node;
}

int main() {
    State *head = createState("Initial");
    State *current = head;

    // Simula te edits
    current->next = createState("Edit1");
    current->next->prev = current;
    current = current->next;

    current->next = createState("Edit2");
    current->next->prev = current;
    current = current->next;

    // Undo
    if (current->prev) current = current->prev;
    printf("Undo: %s\n", current->text);

    // Redo
    if (current->next) current = current->next;
    printf("Redo: %s\n", current->text);

    return 0;
}
//
// Created by catherine janet on 26/10/25.
//
