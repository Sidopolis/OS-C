#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid2, pid3, pid4;

    // fork p2
    pid2 = fork();
    if (pid2 == 0) {
        printf("p2: Hello, I'm the child process!\n");

        // fork p3
        pid3 = fork();
        if (pid3 == 0) {
            printf("p3: Hello, I'm the child process!\n");

            // fork p4
            pid4 = fork();
            if (pid4 == 0) {
                printf("p4: Hello, I'm the child process!\n");
                exit(0);
            }

            // p3 continues executing
            printf("p3: My child is p4=%d.\n", pid4);

            // wait for p4 to finish
            wait(NULL);
            exit(0);
        }

        // p2 continues executing
        printf("p2: My child is p3=%d.\n", pid3);

        // wait for p3 to finish
        wait(NULL);
        exit(0);
    }

    // p1 continues executing
    printf("p1: Hello, I'm the parent process!\n");
    printf("p1: My child is p2=%d.\n", pid2);

    // wait for p2 to finish
    wait(NULL);
    printf("p1: All child processes have completed.\n");

return 0;
}