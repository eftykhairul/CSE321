#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int compare(const void * x, const void * y) {
    return (*(int*)y - *(int*)x);
}

int main(int argc,char *argv[]) {
    int arr[argc-1];
    int n=argc-1;
    for(int i=0; i<argc-1;i++) {
        arr[i]=atoi(argv[i+1]);
    }
    pid_t pid=fork();

    if(pid==0) {
        // Child process
        qsort(arr,n,sizeof(int),compare);
        printf("Sorted array in descending order: ");
        for(int i=0; i<n;i++) {
            printf("%d ",arr[i]);
        }
        printf("\n");
    } else {
        // Parent process
        wait(NULL);
        printf("Odd/Even status of the numbers: ");
        for(int i=0;i<n;i++) {
            int number=arr[i];
            if(number%2==0) {
                printf("%d is even\n",number);
            } else {
                printf("%d is odd\n",number);
            }
        }
        printf("\n");
    }

    return 0;
}