#include <stdio.h>

#define MAX 100
int arr[MAX], n=0;

void insert(int x) { arr[n++] = x; } // always insert at front
int find(int x) {
    for(int i=0;i<n;i++){
        if(arr[i]==x){
            int temp=arr[i];
            for(int j=i;j>0;j--) arr[j]=arr[j-1];
            arr[0]=temp;
            return 1;
        }
    }
    return 0;
}

void printArr() { for(int i=0;i<n;i++) printf("%d ",arr[i]); printf("\n"); }

int main() {
    insert(1); insert(2); insert(3); // inserted at front
    printArr(); // 1 2 3
    find(2);
    printArr(); // 2 1 3
    return 0;
}
//
// Created by catherine janet on 26/10/25.
//
