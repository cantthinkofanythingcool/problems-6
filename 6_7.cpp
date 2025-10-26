#include "ds_utils.h"

DNode* removeDuplicatesSorted(DNode* head) {
    DNode* curr=head;
    while(curr && curr->next) {
        if(curr->data==curr->next->data) {
            DNode* temp=curr->next;
            curr->next=temp->next;
            if(temp->next) temp->next->prev=curr;
            free(temp);
        } else curr=curr->next;
    }
    return head;
}

DNode* removeDuplicatesUnsorted(DNode* head) {
    for(DNode* curr=head; curr; curr=curr->next) {
        DNode* runner=curr->next;
        while(runner) {
            if(curr->data==runner->data) {
                DNode* temp=runner;
                runner->prev->next=runner->next;
                if(runner->next) runner->next->prev=runner->prev;
                runner=runner->next;
                free(temp);
            } else runner=runner->next;
        }
    }
    return head;
}

int main() {
    DNode* head=createDNode(1);
    head->next=createDNode(2); head->next->prev=head;
    head->next->next=createDNode(2); head->next->next->prev=head->next;
    head->next->next->next=createDNode(3); head->next->next->next->prev=head->next->next;

    head=removeDuplicatesSorted(head);
    printDList(head); // Output: 1 2 3
    return 0;
}
//
// Created by catherine janet on 26/10/25.
//
