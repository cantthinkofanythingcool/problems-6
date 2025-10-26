#include "ds_utils.h"

int searchBT(BTreeNode* root, int key) {
    if(!root) return 0;
    if(root->data == key) return 1;
    return searchBT(root->left, key) || searchBT(root->right, key);
}

int main() {
    BTreeNode* root = createBTreeNode(1);
    root->left = createBTreeNode(2);
    root->right = createBTreeNode(3);
    root->left->left = createBTreeNode(4);
    root->left->right = createBTreeNode(5);

    int key = 5;
    if(searchBT(root, key))
        printf("%d found in binary tree\n", key);
    else
        printf("%d not found\n", key);
    return 0;
}

//
// Created by catherine janet on 26/10/25.
//
