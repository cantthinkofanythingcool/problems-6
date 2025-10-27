#include "algo_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>

// ====================== Expression Tree =========================
ExprNode* newExprNode(char c) {
    ExprNode* node = (ExprNode*)malloc(sizeof(ExprNode));
    node->data = c;
    node->left = node->right = NULL;
    return node;
}

ExprNode* prefixToExprTree(char* expr) {
    int len = strlen(expr);
    ExprNode* stack[100]; int top=-1;
    for(int i=len-1;i>=0;i--){
        char c=expr[i];
        if(isalnum(c)) stack[++top]=newExprNode(c);
        else {
            ExprNode* node=newExprNode(c);
            node->left=stack[top--];
            node->right=stack[top--];
            stack[++top]=node;
        }
    }
    return stack[top];
}

void inorderExpr(ExprNode* root) {
    if(!root) return;
    if(root->left || root->right) printf("(");
    inorderExpr(root->left);
    printf("%c", root->data);
    inorderExpr(root->right);
    if(root->left || root->right) printf(")");
}

// ====================== Binary Tree / BST ======================
BTreeNode* createBTreeNode(int data) {
    BTreeNode* node = (BTreeNode*)malloc(sizeof(BTreeNode));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int isBSTUtil(BTreeNode* root, int min, int max) {
    if(!root) return 1;
    if(root->data < min || root->data > max) return 0;
    return isBSTUtil(root->left, min, root->data-1) &&
           isBSTUtil(root->right, root->data+1, max);
}

int isBST(BTreeNode* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

// ====================== Max Heap =================================
MaxHeap* createMaxHeap(int capacity) {
    MaxHeap* heap = (MaxHeap*)malloc(sizeof(MaxHeap));
    heap->capacity=capacity;
    heap->size=0;
    heap->arr=(int*)malloc(capacity*sizeof(int));
    return heap;
}

void insertHeap(MaxHeap* heap, int key) {
    if(heap->size==heap->capacity) return;
    int i=heap->size++;
    heap->arr[i]=key;
    while(i!=0 && heap->arr[(i-1)/2]<heap->arr[i]){
        int temp=heap->arr[i];
        heap->arr[i]=heap->arr[(i-1)/2];
        heap->arr[(i-1)/2]=temp;
        i=(i-1)/2;
    }
}

void maxHeapify(MaxHeap* heap, int i){
    int l=2*i+1, r=2*i+2, largest=i;
    if(l<heap->size && heap->arr[l]>heap->arr[largest]) largest=l;
    if(r<heap->size && heap->arr[r]>heap->arr[largest]) largest=r;
    if(largest!=i){
        int temp=heap->arr[i];
        heap->arr[i]=heap->arr[largest];
        heap->arr[largest]=temp;
        maxHeapify(heap, largest);
    }
}

int extractMaxHeap(MaxHeap* heap){
    if(heap->size<=0) return INT_MIN;
    if(heap->size==1) return heap->arr[--heap->size];
    int root=heap->arr[0];
    heap->arr[0]=heap->arr[--heap->size];
    maxHeapify(heap,0);
    return root;
}

// ====================== Graph ===================================
Graph* createGraph(int V){
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->V=V;
    g->adj=(int**)malloc(V*sizeof(int*));
    for(int i=0;i<V;i++){
        g->adj[i]=(int*)calloc(V,sizeof(int));
    }
    return g;
}

void addEdge(Graph* g, int u, int v){
    g->adj[u][v]=1;
    g->adj[v][u]=1; // For undirected graph by default
}

// --------------------- Cycle Detection -------------------------
int hasCycleUndirectedUtil(Graph* g, int v, int parent, int* visited){
    visited[v]=1;
    for(int i=0;i<g->V;i++){
        if(g->adj[v][i]){
            if(!visited[i]){
                if(hasCycleUndirectedUtil(g,i,v,visited)) return 1;
            } else if(i!=parent) return 1;
        }
    }
    return 0;
}

int hasCycleUndirected(Graph* g){
    int* visited=(int*)calloc(g->V,sizeof(int));
    for(int i=0;i<g->V;i++){
        if(!visited[i] && hasCycleUndirectedUtil(g,i,-1,visited)) return 1;
    }
    return 0;
}

// ====================== Islands in Grid ========================
int countIslandsUtil(char** grid, int i, int j, int n, int m){
    if(i<0 || j<0 || i>=n || j>=m || grid[i][j]=='w') return 0;
    grid[i][j]='w';
    countIslandsUtil(grid,i+1,j,n,m);
    countIslandsUtil(grid,i-1,j,n,m);
    countIslandsUtil(grid,i,j+1,n,m);
    countIslandsUtil(grid,i,j-1,n,m);
    return 1;
}

int countIslands(char** grid, int n, int m){
    int count=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(grid[i][j]=='l') count+=countIslandsUtil(grid,i,j,n,m);
    return count;
}

// ====================== Kruskal's MST ==========================
int findParent(Subset subsets[], int i){
    if(subsets[i].parent!=i) subsets[i].parent=findParent(subsets,subsets[i].parent);
    return subsets[i].parent;
}

void unionSets(Subset subsets[], int x, int y){
    int xroot=findParent(subsets,x);
    int yroot=findParent(subsets,y);
    if(subsets[xroot].rank<subsets[yroot].rank) subsets[xroot].parent=yroot;
    else if(subsets[xroot].rank>subsets[yroot].rank) subsets[yroot].parent=xroot;
    else { subsets[yroot].parent=xroot; subsets[xroot].rank++; }
}

int cmpEdge(const void* a, const void* b){
    return ((Edge*)a)->w - ((Edge*)b)->w;
}

int kruskalMST(Edge edges[], int E, int V){
    qsort(edges,E,sizeof(Edge),cmpEdge);
    Subset* subsets=(Subset*)malloc(V*sizeof(Subset));
    for(int i=0;i<V;i++){ subsets[i].parent=i; subsets[i].rank=0; }
    int total=0, count=0;
    for(int i=0;i<E && count<V-1;i++){
        int x=findParent(subsets,edges[i].u);
        int y=findParent(subsets,edges[i].v);
        if(x!=y){
            total+=edges[i].w;
            unionSets(subsets,x,y);
            count++;
        }
    }
    free(subsets);
    return total;
}

// ====================== Dijkstra ===============================
void dijkstra(int** graph, int V, int src, int* dist){
    int visited[V];
    for(int i=0;i<V;i++){ dist[i]=INT_MAX; visited[i]=0; }
    dist[src]=0;
    for(int count=0; count<V-1; count++){
        int u=-1, min=INT_MAX;
        for(int i=0;i<V;i++){ if(!visited[i] && dist[i]<=min){ min=dist[i]; u=i; } }
        if(u==-1) break;
        visited[u]=1;
        for(int v=0;v<V;v++){
            if(!visited[v] && graph[u][v] && dist[u]!=INT_MAX && dist[u]+graph[u][v]<dist[v])
                dist[v]=dist[u]+graph[u][v];
        }
    }
}

// ====================== Mother Vertex ==========================
void motherVertexDFS(Graph* g, int v, int* visited){
    visited[v]=1;
    for(int i=0;i<g->V;i++)
        if(g->adj[v][i] && !visited[i]) motherVertexDFS(g,i,visited);
}

int find
