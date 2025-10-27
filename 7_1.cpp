//
// Created by catherine janet on 27/10/25.
//
#include "algo_utils.h"

int main() {
    const char *prefix = "*+AB-CD"; // example
    ExprNode* root = prefixToExprTree(prefix);
    if(!root) { printf("Invalid expression or allocation failed\n"); return 1; }
    printf("Inorder (infix) expression: ");
    inorderExpr(root);
    printf("\n");
    return 0;
}
