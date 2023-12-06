#include <stdio.h>

int find_perfect(int i) {
    int x,sum=0;
    // Find divisors
    for (x=1;x<i;x++) {
        if (i%x==0) {
            sum=sum+x;
        }
    }
    if (sum==i) {
        return 1;
    } 
    else {
        return 0;
    }
}

int main() {
    int start,end,x;
    printf("Enter start range: ");
    scanf("%d", &start);
    printf("Enter end range: ");
    scanf("%d", &end);
    for (x=start;x<=end;x++) {
        if (find_perfect(x)) {
            printf("%d\n",x);
        }
    }
    
    return 0;
}