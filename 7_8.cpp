//
// Created by catherine janet on 27/10/25.
//
#include "algo_utils.h"

int main() {
    Graph* g = createGraph(7, 1); // directed
    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 1, 3);
    addEdge(g, 4, 1);
    addEdge(g, 6, 4);
    addEdge(g, 5, 6);
    addEdge(g, 5, 2);
    addEdge(g, 6, 0);

    int mv = findMotherVertex(g);
    if(mv >= 0) printf("Mother vertex: %d\n", mv);
    else printf("No mother vertex\n");
    freeGraph(g);
    return 0;
}
