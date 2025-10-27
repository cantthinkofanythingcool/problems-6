//
// Created by catherine janet on 27/10/25.
//
#include "algo_utils.h"

int main() {
    /* Build a sample tree:
            8
           / \
          3  10
         / \   \
        1   6   14
    */
    BTreeNode* root = createBTreeNode(8);
    root->left = createBTreeNode(3);
    root->right = createBTreeNode(10);
    root->left->left = createBTreeNode(1);
    root->left->right = createBTreeNode(6);
    root->right->right = createBTreeNode(14);

    printf("Is BST? %s\n", isBST(root) ? "Yes" : "No");
    return 0;
}
