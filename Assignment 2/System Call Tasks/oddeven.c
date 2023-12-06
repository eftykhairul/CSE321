#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[]) {
    printf("Odd/Even status of the numbers: ");
    for(int i=1;i<argc;i++) {
        int number=atoi(argv[i]);
        if(number%2==0) {
            printf("%d is even\n", number);
        } 
        else {
            printf("%d is odd\n", number);
        }
    }
    printf("\n");
    return 0;
}