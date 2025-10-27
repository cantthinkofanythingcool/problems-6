//
// Created by catherine janet on 27/10/25.
//
#include "algo_utils.h"

int main() {
    Graph* g = createGraph(4, 0); // undirected
    addEdge(g, 0, 1);
    addEdge(g, 0, 3);
    addEdge(g, 1, 2);
    addEdge(g, 2, 3); // this edge makes it non-bipartite? check

    printf("Is Bipartite? %s\n", isBipartite(g) ? "Yes" : "No");
    freeGraph(g);
    return 0;
}
