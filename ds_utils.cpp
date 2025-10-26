//
// Created by catherine janet on 26/10/25.
//

#include "ds_utils.h"

// ====================== Doubly Linked List ======================
DNode* createDNode(int data) {
    DNode* node = (DNode*)malloc(sizeof(DNode));
    node->data = data;
    node->prev = node->next = NULL;
    return node;
}

void printDList(DNode* head) {
    DNode* temp = head;
    while(temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int lengthDList(DNode* head) {
    int len = 0;
    while(head) {
        len++;
        head = head->next;
    }
    return len;
}

// ====================== Circular Doubly Linked List ==============
CDNode* createCDNode(int data) {
    CDNode* node = (CDNode*)malloc(sizeof(CDNode));
    node->data = data;
    node->next = node->prev = node;
    return node;
}

void printCDList(CDNode* head, int n) {
    if(!head) return;
    CDNode* temp = head;
    for(int i = 0; i < n; i++) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// ====================== Binary Tree =============================
BTreeNode* createBTreeNode(int data) {
    BTreeNode* node = (BTreeNode*)malloc(sizeof(BTreeNode));
    node->data = data;
    node->left = node->right = node->nextRight = NULL;
    return node;
}

void inorder(BTreeNode* root) {
    if(root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(BTreeNode* root) {
    if(root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(BTreeNode* root) {
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

#include <ctype.h>


DNode* createDNode(int data);
void printDList(DNode* head);
int lengthDList(DNode* head);
DNode* intersection(DNode* l1, DNode* l2);
DNode* unionList(DNode* l1, DNode* l2);
void swapNodes(DNode **head, DNode *a, DNode *b);
DNode* reverse(DNode* head);
DNode* deleteMiddle(DNode* head);
DNode* removeDuplicatesSorted(DNode* head);
DNode* removeDuplicatesUnsorted(DNode* head);

// ====================== Circular Doubly Linked List ==============


CDNode* createCDNode(int data);
void printCDList(CDNode* head, int n);
int freqCount(CDNode* head, int x, int n);

// ====================== Binary Tree =============================


BTreeNode* createBTreeNode(int data);
void inorder(BTreeNode* root);
void preorder(BTreeNode* root);
void postorder(BTreeNode* root);

// Binary Tree Utilities
int searchBT(BTreeNode* root, int key);
int height(BTreeNode* root);
void BTtoDLL(BTreeNode* root, BTreeNode** head, BTreeNode** prev);
void connectNextRight(BTreeNode* root);

// ====================== BST / Priority Queue ====================
BTreeNode* insertBST(BTreeNode* root, int key);
BTreeNode* deleteNode(BTreeNode* root, int key);
BTreeNode* minValueNode(BTreeNode* node);
BTreeNode* extractMax(BTreeNode* root, BTreeNode** maxNode);

// ====================== Expression Tree ========================
BTreeNode* prefixToExprTree(char* expr);
void inorderExpr(BTreeNode* root);

// ====================== BST Construction from Traversals =======
BTreeNode* buildTreePreIn(int inorder[], int preorder[], int inStart, int inEnd, int* preIndex);
int search(int arr[], int start, int end, int value);