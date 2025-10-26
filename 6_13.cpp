#include "ds_utils.h"

BTreeNode* insertBST(BTreeNode* root, int key) {
    if(!root) return createBTreeNode(key);
    if(key < root->data) root->left = insertBST(root->left, key);
    else root->right = insertBST(root->right, key);
    return root;
}

BTreeNode* extractMax(BTreeNode* root, BTreeNode** maxNode) {
    if(!root) return NULL;
    BTreeNode* parent=NULL;
    BTreeNode* curr=root;
    while(curr->right) { parent=curr; curr=curr->right; }
    *maxNode=curr;
    if(parent) parent->right=curr->left;
    else root=curr->left;
    return root;
}

int main() {
    BTreeNode* root=NULL;
    root=insertBST(root,5);
    root=insertBST(root,2);
    root=insertBST(root,8);
    root=insertBST(root,6);

    BTreeNode* maxNode=NULL;
    root=extractMax(root,&maxNode);
    printf("Highest priority element: %d\n", maxNode->data);
    free(maxNode);

    return 0;
}

//
// Created by catherine janet on 26/10/25.
//
