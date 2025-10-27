//
// Created by catherine janet on 27/10/25.
//
#include "algo_utils.h"

int main() {
    MaxHeap* h = createMaxHeap(10);
    int vals[] = {5, 3, 17, 10, 84, 19, 6, 22, 9};
    for(int i=0;i<9;i++) insertHeap(h, vals[i]);

    printf("Extracting elements in descending order:\n");
    while(h->size > 0) {
        printf("%d ", extractMaxHeap(h));
    }
    printf("\n");
    freeMaxHeap(h);
    return 0;
}

