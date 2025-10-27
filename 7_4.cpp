//
// Created by catherine janet on 27/10/25.
//
#include "algo_utils.h"

int main() {
    int V = 5;
    Graph* g = createGraph(V, 0); // undirected
    addEdge(g, 0, 1);
    addEdge(g, 1, 2);
    addEdge(g, 2, 3);
    addEdge(g, 3, 1); // cycle 1-2-3-1
    printf("Has cycle? %s\n", hasCycleUndirected(g) ? "Yes" : "No");
    freeGraph(g);
    return 0;
}

