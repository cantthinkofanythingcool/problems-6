#include "ds_utils.h"
#include <string.h>
#include <ctype.h>

BTreeNode* newNode(char c) {
    return createBTreeNode(c);
}

BTreeNode* prefixToExprTree(char* expr) {
    int len=strlen(expr);
    BTreeNode* stack[100]; int top=-1;
    for(int i=len-1;i>=0;i--){
        char c=expr[i];
        if(isalnum(c)) stack[++top]=newNode(c);
        else {
            BTreeNode* node=newNode(c);
            node->left=stack[top--];
            node->right=stack[top--];
            stack[++top]=node;
        }
    }
    return stack[top];
}

void inorderExpr(BTreeNode* root) {
    if(!root) return;
    if(root->left || root->right) printf("(");
    inorderExpr(root->left);
    printf("%c", root->data);
    inorderExpr(root->right);
    if(root->left || root->right) printf(")");
}

int main() {
    char expr[] = "*+AB-CD";
    BTreeNode* root=prefixToExprTree(expr);
    printf("Inorder expression: ");
    inorderExpr(root);
    printf("\n");
    return 0;
}
//
// Created by catherine janet on 26/10/25.
//
