#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

#define MaxCrops 5      // Maximum crops a Farmer can produce or a Shpoowner can take
#define warehouseSize 5 // Size of the warehouse

sem_t empty;
sem_t full;
int in = 0;
int out = 0;
char crops[warehouseSize] = {'R', 'W', 'P', 'S', 'M'};     // indicatig room for different crops
char warehouse[warehouseSize] = {'N', 'N', 'N', 'N', 'N'}; // initially all the room is empty
pthread_mutex_t mutex;

void *Farmer(void *far)
{
    //    1.Farmer harvest crops and put them in perticular room. For example, room 0 for Rice(R).
    //    2.use mutex and semaphore for critical section.
    //    3.print which farmer is keeping which crops in which room inside the critical section.
    //    4.print the whole warehouse buffer outside of the critical section

    // Write code here
    int x;
    int *f_id = (int *)far;
    for (x=0;x<MaxCrops;x++)
    {
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        warehouse[in]=crops[*f_id];
        printf("Farmer %d: Insert crops %c at %d\n",*f_id,warehouse[in], in);
        in=(in+1)%warehouseSize;
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
    printf("\nFarmer:%d",*f_id);
    for (x=0;x< warehouseSize;x++)
    {
        printf("%c",warehouse[x]);
    }
    printf("\n");
    return 0;
}
void *ShopOwner(void *sho)
{
    /*
       1.Shop owner take crops and make that perticular room empty.
       2.use mutex and semaphore for critical section.
       3.print which shop owner is taking which crops from which room inside the critical section.
       4.print the whole warehouse buffer outside of the critical section
       */
    // Write code here

    int y;
    int *s_id=(int *)sho;
    for (y=0;y<MaxCrops;y++)
    {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        warehouse[out]=warehouse[*s_id];
        printf("Shop owner %d: Remove crops %c from %d\n",*s_id,warehouse[out],out);
        out=(out+1)%warehouseSize;
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }

    printf("\nShop owner %d: ",*s_id);
    for (y=0;y<warehouseSize;y++)
    {
        printf("%c",warehouse[y]);
    }
    printf("\n");
    return 0;
}

int main()
{

    /*intializing thread,mutex,semaphore
     */

    pthread_t Far[5], Sho[5];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty, 0, warehouseSize);
    sem_init(&full, 0, 0);

    int a[5] = {1, 2, 3, 4, 5};
    for (int x=0;x<5;x++)
    {
        pthread_create(&Far[x], NULL,(void *)Farmer,(void *)&a[x]);
    }
    for (int x=0;x<5;x++)
    {
        pthread_create(&Sho[x], NULL,(void *)ShopOwner,(void *)&a[x]);
    }

    for (int x=0;x<5;x++)
    {
        pthread_join(Far[x], NULL);
    }
    for (int x=0;x<5;x++)
    {
        pthread_join(Sho[x], NULL);
    }
    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}
