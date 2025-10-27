//
// Created by catherine janet on 27/10/25.
//
#include "algo_utils.h"

int main() {
    int V = 4;
    Edge edges[] = {
            {0,1,10}, {0,2,6}, {0,3,5}, {1,3,15}, {2,3,4}
    };
    int E = sizeof(edges)/sizeof(edges[0]);
    int cost = kruskalMST(edges, E, V);
    printf("MST total weight = %d\n", cost); // expected 19
    return 0;
}
