#include "ds_utils.h"

int height(BTreeNode* root) {
    if(!root) return 0;
    int l = height(root->left);
    int r = height(root->right);
    return (l > r ? l : r) + 1;
}

int main() {
    BTreeNode* root = createBTreeNode(1);
    root->left = createBTreeNode(2);
    root->right = createBTreeNode(3);
    root->left->left = createBTreeNode(4);
    root->left->right = createBTreeNode(5);

    printf("Height of tree: %d\n", height(root));
    return 0;
}

//
// Created by catherine janet on 26/10/25.
//
