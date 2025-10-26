#include "ds_utils.h"

void swapNodes(DNode **head, DNode *a, DNode *b) {
    if(a == b) return;

    DNode *prevA=a->prev, *nextA=a->next;
    DNode *prevB=b->prev, *nextB=b->next;

    if(prevA) prevA->next=b; else *head=b;
    if(nextA) nextA->prev=b;
    if(prevB) prevB->next=a; else *head=a;
    if(nextB) nextB->prev=a;

    a->prev=prevB; a->next=nextB;
    b->prev=prevA; b->next=nextA;
}

int main() {
    DNode* head=createDNode(1);
    head->next=createDNode(2); head->next->prev=head;
    head->next->next=createDNode(3); head->next->next->prev=head->next;

    swapNodes(&head, head, head->next->next); // swap 1 and 3
    printDList(head); // Output should be 3 2 1
    return 0;
}
//
// Created by catherine janet on 26/10/25.
//
