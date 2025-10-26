#include "ds_utils.h"

int freqCount(CDNode* head, int x, int n) {
    int count=0;
    CDNode* temp=head;
    for(int i=0;i<n;i++){
        if(temp->data==x) count++;
        temp=temp->next;
    }
    return count;
}

int main() {
    CDNode* head=createCDNode(1);
    CDNode* second=createCDNode(2);
    CDNode* third=createCDNode(1);
    head->next=second; second->prev=head; second->next=third; third->prev=second; third->next=head; head->prev=third;

    int n=3;
    printf("Frequency of 1: %d\n", freqCount(head,1,n)); // Output: 2
    return 0;
}
//
// Created by catherine janet on 26/10/25.
//
