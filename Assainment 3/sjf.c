#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESS 8

struct Process {
    int pid;
    int a_time;
    int b_time;
    int r_time;
    int c_time;
    int t_time;
    int w_time;
};

int main() {
    struct Process processes[MAX_PROCESS];
    int num_pross,x,time,min_r_time,min_r_index;

    printf("Enter the number of processes: ");
    scanf("%d", &num_pross);
    for (x=0;x<num_pross;x++) {
        processes[x].pid = x+ 1;
        printf("\nEnter details for process %d:\n", processes[x].pid);
        printf("Arrival time: ");
        scanf("%d", &processes[x].a_time);
        printf("Burst time: ");
        scanf("%d", &processes[x].b_time);
        processes[x].r_time = processes[x].b_time;
    }

    // SJF scheduling
    time = 0;
    while (1) {
        min_r_time=9999;
        min_r_index=-1;

        for (x=0; x<num_pross;x++) {
            if (processes[x].a_time<=time && processes[x].r_time<min_r_time && processes[x].r_time>0){
                min_r_time=processes[x].r_time;
                min_r_index=x;
            }
        }
        if (min_r_index==-1) {
            break;
        }
        processes[min_r_index].r_time--;
        time++;
        if (processes[min_r_index].r_time == 0) {
            processes[min_r_index].c_time = time;
            processes[min_r_index].t_time = processes[min_r_index].c_time - processes[min_r_index].a_time;
            processes[min_r_index].w_time = processes[min_r_index].t_time - processes[min_r_index].b_time;
        }
    }
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (x=0;x<num_pross;x++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",processes[x].pid,processes[x].a_time, processes[x].b_time, processes[x].c_time,processes[x].t_time,processes[x].w_time);
    }
    return 0;
}

