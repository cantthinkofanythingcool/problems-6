//
// Created by catherine janet on 26/10/25.
//
#include "ds_utils.h"

int search(int arr[], int start, int end, int value) {
    for(int i=start;i<=end;i++) if(arr[i]==value) return i;
    return -1;
}

BTreeNode* buildTreePreIn(int inorder[], int preorder[], int inStart, int inEnd, int* preIndex) {
    if(inStart > inEnd) return NULL;
    BTreeNode* node=createBTreeNode(preorder[*preIndex]);
    (*preIndex)++;
    if(inStart==inEnd) return node;
    int inIndex=search(inorder, inStart, inEnd, node->data);
    node->left=buildTreePreIn(inorder, preorder, inStart, inIndex-1, preIndex);
    node->right=buildTreePreIn(inorder, preorder, inIndex+1, inEnd, preIndex);
    return node;
}

int main() {
    int inorder[]={4,2,5,1,6,3};
    int preorder[]={1,2,4,5,3,6};
    int preIndex=0;
    BTreeNode* root=buildTreePreIn(inorder, preorder, 0, 5, &preIndex);
    printf("Inorder traversal of constructed tree: ");
    inorder(root); printf("\n");
    return 0;
}

