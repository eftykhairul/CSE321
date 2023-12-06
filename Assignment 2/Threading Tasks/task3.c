#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *cal_ascii(void *arg) {
    char *user=(char*)arg;
    int i=0,sum=0;
    int *output=(int*)malloc(sizeof(int));
    while (user[i] != '\0') {
        sum+= user[i];
        i++;
    }
    *output=sum;
    return output;
}

// main function
int main() {
    pthread_t n1,n2,n3;
    char *user1="Efta";
    char *user2="Khairul";
    char *user3="Islam";
    int *output1, *output2, *output3;

    pthread_create(&n1,NULL,cal_ascii,(void*)user1);
    pthread_join(n1,(void **)&output1);
    pthread_create(&n2,NULL,cal_ascii,(void*)user2);
    pthread_join(n2,(void**)&output2);
    pthread_create(&n3,NULL,cal_ascii,(void*)user3);
    pthread_join(n3,(void**)&output3);

    if (*output1 == *output2 && *output1 == *output3)
    {
        printf("Youreka\n");
    }
    else if (*output1== *output2|| *output1== *output3|| *output2== *output3)
    {
        printf("Miracle\n");
    }
    else
    {
        printf("Hasta la vista\n");
    }

    return 0;
}