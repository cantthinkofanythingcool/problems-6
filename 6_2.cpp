//
// Created by catherine janet on 26/10/25.
//
#include "ds_utils.h"

DNode* intersection(DNode* l1, DNode* l2) {
    DNode *head = NULL, *tail = NULL;
    while (l1 && l2) {
        if (l1->data < l2->data) l1 = l1->next;
        else if (l2->data < l1->data) l2 = l2->next;
        else { // equal
            DNode* node = createDNode(l1->data);
            if (!head) head = tail = node;
            else { tail->next = node; node->prev = tail; tail = node; }
            l1 = l1->next; l2 = l2->next;
        }
    }
    return head;
}

DNode* unionList(DNode* l1, DNode* l2) {
    DNode *head = NULL, *tail = NULL;
    while(l1 && l2) {
        int val;
        if(l1->data < l2->data) { val = l1->data; l1 = l1->next; }
        else if(l2->data < l1->data) { val = l2->data; l2 = l2->next; }
        else { val = l1->data; l1 = l1->next; l2 = l2->next; }

        DNode* node = createDNode(val);
        if(!head) head = tail = node;
        else { tail->next = node; node->prev = tail; tail = node; }
    }
    while(l1) { DNode* node = createDNode(l1->data); tail->next=node; node->prev=tail; tail=node; l1=l1->next; }
    while(l2) { DNode* node = createDNode(l2->data); tail->next=node; node->prev=tail; tail=node; l2=l2->next; }
    return head;
}

int main() {
    DNode *l1 = createDNode(1); l1->next=createDNode(3); l1->next->prev=l1; l1->next->next=createDNode(5); l1->next->next->prev=l1->next;
    DNode *l2 = createDNode(3); l2->next=createDNode(4); l2->next->prev=l2; l2->next->next=createDNode(5); l2->next->next->prev=l2->next;

    DNode* inter = intersection(l1, l2);
    printf("Intersection: "); printDList(inter);

    DNode* uni = unionList(l1, l2);
    printf("Union: "); printDList(uni);

    return 0;
}
