#include "ds_utils.h"

DNode* reverse(DNode* head) {
    DNode *temp=NULL, *current=head;
    while(current) {
        temp=current->prev;
        current->prev=current->next;
        current->next=temp;
        current=current->prev;
    }
    if(temp) head=temp->prev;
    return head;
}

int main() {
    DNode* head=createDNode(1);
    head->next=createDNode(2); head->next->prev=head;
    head->next->next=createDNode(3); head->next->next->prev=head->next;

    head=reverse(head);
    printDList(head); // Output: 3 2 1
    return 0;
}
//
// Created by catherine janet on 26/10/25.
//
