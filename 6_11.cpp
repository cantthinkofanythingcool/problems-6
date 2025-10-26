#include "ds_utils.h"

void BTtoDLL(BTreeNode* root, BTreeNode** head, BTreeNode** prev) {
    if(!root) return;
    BTtoDLL(root->left, head, prev);
    if(!(*head)) *head=root;
    root->left=*prev;
    if(*prev) (*prev)->right=root;
    *prev=root;
    BTtoDLL(root->right, head, prev);
}

int main() {
    BTreeNode* root = createBTreeNode(1);
    root->left = createBTreeNode(2);
    root->right = createBTreeNode(3);
    root->left->left = createBTreeNode(4);
    root->left->right = createBTreeNode(5);

    BTreeNode* head=NULL;
    BTreeNode* prev=NULL;
    BTtoDLL(root, &head, &prev);

    printf("Doubly linked list in inorder: ");
    BTreeNode* temp=head;
    while(temp) {
        printf("%d ", temp->data);
        temp=temp->right;
    }
    printf("\n");
    return 0;
}

//
// Created by catherine janet on 26/10/25.
//
