#ifndef ALGO_UTILS_H
#define ALGO_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// ====================== Expression Tree =========================
typedef struct ExprNode {
    char data;
    struct ExprNode *left, *right;
} ExprNode;

ExprNode* newExprNode(char c);
ExprNode* prefixToExprTree(char* expr);
void inorderExpr(ExprNode* root);

// ====================== Binary Tree / BST ======================
typedef struct BTreeNode {
    int data;
    struct BTreeNode *left, *right;
} BTreeNode;

BTreeNode* createBTreeNode(int data);
int isBSTUtil(BTreeNode* root, int min, int max);
int isBST(BTreeNode* root);

// ====================== Max Heap =================================
typedef struct MaxHeap {
    int* arr;
    int capacity;
    int size;
} MaxHeap;

MaxHeap* createMaxHeap(int capacity);
void insertHeap(MaxHeap* heap, int key);
int extractMaxHeap(MaxHeap* heap);
void maxHeapify(MaxHeap* heap, int i);

// ====================== Graph ================================
typedef struct Graph {
    int V;
    int** adj; // adjacency matrix
} Graph;

Graph* createGraph(int V);
void addEdge(Graph* g, int u, int v);
int hasCycleUndirectedUtil(Graph* g, int v, int parent, int* visited);
int hasCycleUndirected(Graph* g);

// ====================== Islands in Grid ========================
int countIslandsUtil(char** grid, int i, int j, int n, int m);
int countIslands(char** grid, int n, int m);

// ====================== MST: Kruskal ===========================
typedef struct Edge {
    int u, v, w;
} Edge;

typedef struct Subset {
    int parent;
    int rank;
} Subset;

int kruskalMST(Edge edges[], int E, int V);

// ====================== Dijkstra ===============================
void dijkstra(int** graph, int V, int src, int* dist);

// ====================== Mother Vertex ==========================
void motherVertexDFS(Graph* g, int v, int* visited);
int findMotherVertex(Graph* g);

// ====================== Strongly Connected Components =========
void SCCUtil(Graph* g, int v, int* visited, int* stack, int* top);
Graph* transposeGraph(Graph* g);
void printSCC(Graph* g);

// ====================== Bipartite Graph ========================
int isBipartite(Graph* g);

#endif
