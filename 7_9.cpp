//
// Created by catherine janet on 27/10/25.
//
#include "algo_utils.h"

int main() {
    Graph* g = createGraph(5, 1); // directed
    addEdge(g, 1, 0);
    addEdge(g, 0, 2);
    addEdge(g, 2, 1);
    addEdge(g, 0, 3);
    addEdge(g, 3, 4);

    printf("SCCs:\n");
    printSCC(g);

    freeGraph(g);
    return 0;
}
