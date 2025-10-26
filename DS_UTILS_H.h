//
// Created by catherine janet on 26/10/25.
//

#ifndef DS_UTILS_H
#define DS_UTILS_H

#include <stdio.h>
#include <stdlib.h>

// ====================== Doubly Linked List ======================
typedef struct DNode {
    int data;
    struct DNode *prev, *next;
} DNode;

DNode* createDNode(int data);
void printDList(DNode* head);
int lengthDList(DNode* head);

// ====================== Circular Doubly Linked List ==============
typedef struct CDNode {
    int data;
    struct CDNode* next;
    struct CDNode* prev;
} CDNode;

CDNode* createCDNode(int data);
void printCDList(CDNode* head, int n);

// ====================== Binary Tree =============================
typedef struct BTreeNode {
    int data;
    struct BTreeNode *left, *right, *nextRight;
} BTreeNode;

BTreeNode* createBTreeNode(int data);
void inorder(BTreeNode* root);
void preorder(BTreeNode* root);
void postorder(BTreeNode* root);

#endif

