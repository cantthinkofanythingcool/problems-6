//
// Created by catherine janet on 27/10/25.
//
#include "algo_utils.h"
#include <stdlib.h>

int** allocMatrix(int V) {
    int** mat = malloc(sizeof(int*)*V);
    for(int i=0;i<V;i++) {
        mat[i] = calloc(V, sizeof(int));
    }
    return mat;
}
void freeMatrix(int** m, int V) { for(int i=0;i<V;i++) free(m[i]); free(m); }

int main() {
    int V = 5;
    int** graph = allocMatrix(V);
    // sample weighted graph (0 means no edge)
    graph[0][1] = 10; graph[0][4] = 5;
    graph[1][2] = 1;  graph[1][4] = 2;
    graph[2][3] = 4;
    graph[3][0] = 7;  graph[3][2] = 6;
    graph[4][1] = 3;  graph[4][2] = 9; graph[4][3] = 2;

    int* dist = malloc(sizeof(int)*V);
    dijkstra(graph, V, 0, dist);
    printf("Distances from source 0:\n");
    for(int i=0;i<V;i++) printf("%d: %d\n", i, dist[i]);

    free(dist);
    freeMatrix(graph, V);
    return 0;
}
