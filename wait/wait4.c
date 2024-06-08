#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int status;
    pid_t pid, ppid;
    
    // Create the first child
    pid_t child1 = fork();

    if (child1 < 0) {
        perror("Failed to fork child1");
        exit(1);
    } else if (child1 == 0) {
        // Child1 process
        pid = getpid();
        ppid = getppid();
        printf("I am Child1 %d of parent %d\n", pid, ppid);
        printf("Enter the Exit Status for Child1: ");
        scanf("%d", &status);
        exit(status);
    } else {
        // Parent process
        // Create the second child
        pid_t child2 = fork();

        if (child2 < 0) {
            perror("Failed to fork child2");
            exit(1);
        } else if (child2 == 0) {
            // Child2 process
            pid = getpid();
            ppid = getppid();
            printf("I am Child2 %d of parent %d\n", pid, ppid);
            printf("Enter the Exit Status for Child2: ");
            scanf("%d", &status);
            exit(status);
        } else {
            // Parent process
            // Create the third child
            pid_t child3 = fork();

            if (child3 < 0) {
                perror("Failed to fork child3");
                exit(1);
            } else if (child3 == 0) {
                // Child3 process
                pid = getpid();
                ppid = getppid();
                printf("I am Child3 %d of parent %d\n", pid, ppid);
                printf("Enter the Exit Status for Child3: ");
                scanf("%d", &status);
                exit(status);
            } else {
                // Parent process
                // Wait for each child to terminate
                for (int i = 0; i < 3; i++) {
                    pid_t wpid = wait(&status);
                    if (wpid == -1) {
                        perror("wait");
                        exit(1);
                    }
                    printf("Parent process %d: Child %d terminated with status %d\n", getpid(), wpid, WEXITSTATUS(status));
                }
            }
        }
    }

    return 0;
}

