#include "ds_utils.h"

BTreeNode* minValueNode(BTreeNode* node) {
    BTreeNode* current=node;
    while(current && current->left) current=current->left;
    return current;
}

BTreeNode* deleteNode(BTreeNode* root, int key) {
    if(!root) return root;
    if(key < root->data) root->left = deleteNode(root->left,key);
    else if(key > root->data) root->right = deleteNode(root->right,key);
    else {
        if(!root->left) {
            BTreeNode* temp=root->right;
            free(root);
            return temp;
        } else if(!root->right) {
            BTreeNode* temp=root->left;
            free(root);
            return temp;
        }
        BTreeNode* temp=minValueNode(root->right);
        root->data=temp->data;
        root->right=deleteNode(root->right,temp->data);
    }
    return root;
}

int main() {
    BTreeNode* root=NULL;
    root=insertBST(root,5);
    root=insertBST(root,3);
    root=insertBST(root,7);
    root=insertBST(root,6);
    root=insertBST(root,8);

    root=deleteNode(root,7);
    printf("Inorder after deletion: "); inorder(root); printf("\n");
    return 0;
}
//
// Created by catherine janet on 26/10/25.
//
