//
// Created by catherine janet on 26/10/25.
//
#include "ds_utils.h"
#include <queue>

void connectNextRight(BTreeNode* root) {
    if(!root) return;
    std::queue<BTreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        int size=q.size();
        BTreeNode* prev=NULL;
        for(int i=0;i<size;i++){
            BTreeNode* node=q.front(); q.pop();
            if(prev) prev->nextRight=node;
            prev=node;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        prev->nextRight=NULL;
    }
}

int main() {
    BTreeNode* root = createBTreeNode(1);
    root->left = createBTreeNode(2);
    root->right = createBTreeNode(3);
    root->left->left = createBTreeNode(4);
    root->left->right = createBTreeNode(5);
    root->right->right = createBTreeNode(6);

    connectNextRight(root);

    printf("NextRight of root->left: %d\n", root->left->nextRight ? root->left->nextRight->data : -1); // should be 3
    return 0;
}

