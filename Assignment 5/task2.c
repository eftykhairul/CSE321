#include <stdio.h>

int need[6][4];

int safeSeq(int m, int process, int work[m]) {
    for (int i = 0; i < m; i++) {
        if (need[process][i] > work[i]) {
            return 0;
        }
    }
    return 1;
}

void safeSequence(int n,int m, int avail[m],int max[n][m], int alloc[n][m]) {
    int work[m];
    int finish[n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        work[i] = avail[i];
    }

    for (int i = 0; i < n; i++) {
        finish[i] = 0;
    }

    printf("Safe Sequence: ");

    int count = 0;
    while (count < n) {
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (!finish[i] && safeSeq(m, i, work)) {
                printf("P%d ", i);
                finish[i] = 1;
                count++;

                for (int j = 0; j < m; j++) {
                    work[j] += alloc[i][j];
                }
                found = 1;
            }
        }
        if (!found) {
            printf("\nDeadlock ahead\n");
            break;
        }
    }
    printf("\n");
}

int main() {
    int n = 6; // Number of processes
    int m = 4; // Number of resources
    int alloc[6][4] = { { 0, 1, 0, 3 }, // P0 // Allocation Matrix
                        { 2, 0, 0, 3 }, // P1
                        { 3, 0, 2, 0 }, // P2
                        { 2, 1, 1, 5 }, // P3
                        { 0, 0, 2, 2 }, // P4
                        {1, 2 , 3, 1 } }; //P5
 
    int max[6][4] = { { 6, 4, 3, 4 }, // P0 // MAX Matrix
                      { 3, 2, 2, 4 }, // P1
                      { 9, 1, 2, 6 }, // P2
                      { 2, 2, 2, 8 }, // P3
                      { 4, 3, 3, 7 }, // P4
                      { 6, 2 , 6, 5 } }; //P5
    int avail[4] = { 2, 2, 2, 1 };      //Available resources

    safeSequence(n,m,avail,max,alloc);

    return 0;
}
