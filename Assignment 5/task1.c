#include <stdio.h>
#include <stdlib.h>


// deadlockCheck() function to check for a safe state
int deadlockCheck(int n, int m,int avail[m], int max[n][m], int alloc[n][m]) {
  int work[m];
  int need[n][m];
  int finish[n];
  //need
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      need[i][j] = max[i][j] - alloc[i][j];
    }
  }
  for (int i = 0; i < m; i++) {
    work[i] = avail[i];
  }

  int found = 0;
  int count = 0;

  while (count < n && found) {
    found = 0;

    for (int i = 0; i < n; i++) {
      if (!finish[i]) {
        int run_finish = 1;

        for (int j = 0; j < m; j++) {
          if (need[i][j] > work[j]) {
            run_finish = 0;
            break;
          }
        }

        if (run_finish) {
          finish[i] = 1;

          for (int j = 0; j < m; j++) {
            work[j] += alloc[i][j];
          }

          found = 1;
          count++;
          break;
        }
      }
    }
  }

  if (count == n) {
    return 1;
  } else {
    return 0;
  }
}

int main() {
  // Define max and alloc arrays within the main function
    int n = 5; // Number of processes
    int m = 4; // Number of resources
    int alloc[5][4] = { { 0, 1, 0, 3 }, // P0 // Allocation Matrix
                        { 2, 0, 0, 0 }, // P1
                        { 3, 0, 2, 0 }, // P2
                        { 2, 1, 1, 5 }, // P3
                        { 0, 0, 2, 2 } }; // P4
 
    int max[5][4] = { { 6, 4, 3, 4 }, // P0 // MAX Matrix
                      { 3, 2, 2, 1 }, // P1
                      { 9, 1, 2, 6 }, // P2
                      { 2, 2, 2, 8 }, // P3
                      { 4, 3, 3, 7 } }; // P4
    int avail[4] = { 3, 3, 2, 1 };      //Available resources
 

  if (deadlockCheck(n, m,avail, alloc, max)) {
    printf("Safe here\n");
  } else {
    printf("Deadlock ahead\n");
  }

  return 0;
}
