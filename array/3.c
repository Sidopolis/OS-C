#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid2, pid3, pid4, pid5, pid6, pid7, pid8;

    // fork p2
    pid2 = fork();
    if (pid2 == 0) {
        printf("p2: Hello, I'm the child process!\n");
        exit(0);
    }

    // fork p3
    pid3 = fork();
    if (pid3 == 0) {
        printf("p3: Hello, I'm the child process!\n");

        // fork p5
        pid5 = fork();
        if (pid5 == 0) {
            printf("p5: Hello, I'm the child process!\n");

            // fork p6
            pid6 = fork();
            if (pid6 == 0) {
                printf("p6: Hello, I'm the child process!\n");
                exit(0);
            }

            // fork p7
            pid7 = fork();
            if (pid7 == 0) {
                printf("p7: Hello, I'm the child process!\n");
                exit(0);
            }

            // fork p8
            pid8 = fork();
            if (pid8 == 0) {
                printf("p8: Hello, I'm the child process!\n");
                exit(0);
            }

            exit(0);
        }

        exit(0);
    }

    // fork p4
    pid4 = fork();
    if (pid4 == 0) {
        printf("p4: Hello, I'm the child process!\n");
        exit(0);
    }

    // p1 continues executing
    printf("p1: Hello, I'm the parent process!\n");
    printf("p1: My children are p2=%d, p3=%d, p4=%d.\n", pid2, pid3, pid4);

    // wait for all child processes to finish
    wait(NULL);
    wait(NULL);
    wait(NULL);
    wait(NULL);

    printf("p1: All child processes have completed.\n");

return 0;
}