#include <stdio.h>
int main()
{
    int a_time[20]; 
    int w_time[20];
    int t_time[20]; 
    int b_time[20]; 
    int prio[20]; 
    int c_time[20];
    int num_pross,save[20],t,count =0,num;
    printf("Enter the number of Processes: ");
    scanf("%d", &num_pross);

    for (int x=0;x<num_pross;x++)
    {
        printf("\nEnter Process P%d\n",x+1);
        printf("Arrival Time: ");
        scanf("%d", &a_time[x]);
        printf("Burst Time: ");
        scanf("%d", &b_time[x]);
        save[x]=b_time[x];
        printf("Priority: ");
        scanf("%d",&prio[x]);
    }

    prio[9]=9999;

    for (t=0;count!=num_pross;t++)
    {
        num=9;
        for (int x=0;x<num_pross;x++)
        {
            if (prio[num]>prio[x] &&a_time[x]<=t && b_time[x]>0)
            {
                num=x;
            }
        }

        b_time[num]=b_time[num]-1;

        if (b_time[num]==0)
        {
            count++;
            t_time[num]=t+1-a_time[num]-save[num];
            w_time[num]=t+1-a_time[num];
            c_time[num]=t+1;
        }
    }
	
	printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int x=0;x<num_pross;x++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", x+1,a_time[x],save[x],c_time[x],w_time[x],t_time[x]);
    }

    return 0;
}
