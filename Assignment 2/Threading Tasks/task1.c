#include <stdio.h>
#include <pthread.h>

#define THRDS_NUM 5

//Thread
void* thrd_function(void*arg) {
    int thrd_number= *((int*)arg);
    printf("thread-%d running\n",thrd_number);
    printf("thread-%d closed\n",thrd_number);
    return NULL;
}
//Main
int main() {
    pthread_t thrds[THRDS_NUM];
    int thrd_nums[THRDS_NUM];
    for (int i=0;i<THRDS_NUM;i++) {
        thrd_nums[i]=i + 1;
        pthread_create(&thrds[i],NULL, thrd_function,(void*) &thrd_nums[i]);
        pthread_join(thrds[i],NULL);
    }

    return 0;
}