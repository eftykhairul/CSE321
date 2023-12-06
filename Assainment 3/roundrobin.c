#include <stdio.h>

#define MAX_PROCESSES 10
struct Process {
    int pid;
    int b_time;
    int r_time;
};

int main() {
    int num_pross,q,time=0;
    struct Process processes[MAX_PROCESSES];
    int completed[MAX_PROCESSES]={0};
    int c_time[MAX_PROCESSES]={0};
    int t_time[MAX_PROCESSES]={0};
    int w_time[MAX_PROCESSES]={0};
    printf("Enter the number of processes: ");
    scanf("%d", &num_pross);
    printf("Enter the time quantum: ");
    scanf("%d", &q);
    printf("Enter the burst times for each process:\n");
    for (int x= 0;x<num_pross;x++) {
        printf("Process %d: ",x+1);
        scanf("%d",&processes[x].b_time);
        processes[x].pid=x+1;
        processes[x].r_time=processes[x].b_time;
    }

    while (1) {
        int all_completed = 1;
        for (int x=0;x<num_pross;x++) {
            if (completed[x]==0) {
                all_completed=0;
                if (processes[x].r_time>q) {
                    processes[x].r_time-=q;
                    time+=q;
                } else {
                    time+=processes[x].r_time;
                    processes[x].r_time=0;
                    completed[x]=1;
                    c_time[x]=time;
                    t_time[x]=c_time[x];
                    w_time[x]=t_time[x]-processes[x].b_time;
                }
            }
        }
        if (all_completed) {
            break;
        }
    }
    printf("\n");
    printf("PID\tBT\tCT\tTAT\tWT\n");
    for (int x=0;x<num_pross;x++) {
        printf("%d\t%d\t%d\t%d\t%d\n",processes[x].pid,processes[x].b_time,c_time[x],t_time[x],w_time[x]);
    }

    return 0;
}

