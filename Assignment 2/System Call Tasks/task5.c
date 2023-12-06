#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t parent_pid,child_pid,grandchild_pid1,grandchild_pid2,grandchild_pid3;
    parent_pid = getpid();

    printf("1.Parent process ID: %d\n",parent_pid);
    child_pid=fork();

    if (child_pid==0) {
        parent_pid=getpid();
        printf("2.Child process ID: %d\n",parent_pid);
        // Create grandchild processes
        grandchild_pid1=fork();
        if (grandchild_pid1==0) {
            parent_pid=getpid();
            printf("3.Grandchild process ID: %d\n",parent_pid);
            return 0;
        }
        grandchild_pid2=fork();
        if (grandchild_pid2==0) {
            parent_pid=getpid();
            printf("4.Grandchild process ID: %d\n",parent_pid);
            return 0;
        }
        grandchild_pid3=fork();
        if (grandchild_pid3==0) {
            parent_pid=getpid();
            printf("5.Grandchild process ID: %d\n",parent_pid);
            return 0;
        }
        return 0;
    }
    return 0;
}