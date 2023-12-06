#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thrd_function(void *arg) {
    int *num=(int*)arg;
    for (int x=0;x<5;x++)
    {
        if (*num==1)
        {
            printf("Thread %d prints %d\n", *num,x+1);
        }
        else if (*num==2)
        {
            printf("Thread %d prints %d\n", *num,x+6);
        }
        else if (*num==3)
        {
            printf("Thread %d prints %d\n", *num,x+11);
        }
        else if (*num==4)
        {
            printf("Thread %d prints %d\n", *num,x+16);
        }
        else if (*num==5)
        {
            printf("Thread %d prints %d\n", *num,x+21);
        }
    }
    pthread_exit(NULL);
}
// Main function
int main()
{
    pthread_t thrd_id[5];
    int x;
    int *num;
    for (x=0;x<5;x++)
    {
        num=(int *)malloc(sizeof(int));
        *num=x+1;
        pthread_create(&thrd_id[x], NULL, thrd_function,num);
        pthread_join(thrd_id[x], NULL);
    }
    return 0;
}