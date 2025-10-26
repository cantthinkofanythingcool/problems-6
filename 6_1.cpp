#include "ds_utils.h"

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

    // Simulate edits
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
