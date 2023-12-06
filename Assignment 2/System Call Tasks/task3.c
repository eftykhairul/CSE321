#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int a,b,c;
    int count=1;
    a = fork();
    b = fork();
    c = fork();
    if (c==0){
        if (getpid() % 2!=0){
            fork();
            count++;
        }
    }
    else if (a==0) {
        if (getpid() % 2 != 0) {
            fork();
            count++;
        }
    } 
    else if (b==0) {
        if (getpid() % 2!=0){
            fork();
            count++;
        }
    } 
    else {
        count+=3;

        printf("Total processes created: %d\n",count);
    }

    return 0;
}