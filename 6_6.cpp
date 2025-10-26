//
// Created by catherine janet on 26/10/25.

#include "ds_utils.h"

DNode* deleteMiddle(DNode* head) {
    int len=lengthDList(head);
    if(len==0) return head;
    int mid=len/2;
    DNode* temp=head;
    for(int i=0;i<mid;i++) temp=temp->next;

    if(temp->prev) temp->prev->next=temp->next;
    if(temp->next) temp->next->prev=temp->prev;
    if(temp==head) head=temp->next;
    free(temp);
    return head;
}

int main() {
    DNode* head=createDNode(1);
    head->next=createDNode(2); head->next->prev=head;
    head->next->next=createDNode(3); head->next->next->prev=head->next;

    head=deleteMiddle(head);
    printDList(head); // Output: 1 3
    return 0;
}

//
