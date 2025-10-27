//
// Created by catherine janet on 27/10/25.
//
#include "algo_utils.h"

/* Helper to allocate copy of grid since function mutates it */
char** copyGrid(char** g, int n, int m) {
    char** c = malloc(sizeof(char*)*n);
    for(int i=0;i<n;i++){
        c[i] = malloc(m);
        memcpy(c[i], g[i], m);
    }
    return c;
}
void freeGrid(char** g, int n) { for(int i=0;i<n;i++) free(g[i]); free(g); }

int main() {
    int n = 4, m = 5;
    const char* raw[] = {
            "lwwll",
            "llwwl",
            "wwwlw",
            "lwlll"
    };
    char** grid = malloc(sizeof(char*)*n);
    for(int i=0;i<n;i++){
        grid[i] = malloc(m);
        memcpy(grid[i], raw[i], m);
    }

    int ans = countIslands(grid, n, m);
    printf("Number of islands: %d\n", ans);

    for(int i=0;i<n;i++) free(grid[i]);
    free(grid);
    return 0;
}
