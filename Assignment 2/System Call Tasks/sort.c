
#include <stdio.h>
#include <stdlib.h>

int compare(const void *x, const void *y) {
    return (*(int*)y - *(int*)x);
}

int main(int argc, char *argv[]) {
    int arr[argc-1];
    int n=argc-1;
    for(int i=0; i<argc-1;i++) {
        arr[i]=atoi(argv[i+1]);
    }
    qsort(arr,n,sizeof(int),compare);
    printf("Sorted array in descending order: ");
    for(int i=0; i<n;i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}