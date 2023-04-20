#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid1, pid2, pid3;
    
    // Fork first child process (p2)
    pid1 = fork();
    if (pid1 < 0) {
        fprintf(stderr, "Error: Unable to fork first child process\n");
        exit(EXIT_FAILURE);
    } else if (pid1 == 0) {
        printf("p2: I am the first child process, my PID is %d\n", getpid());
        exit(EXIT_SUCCESS);
    }
    
    // Fork second child process (p3)
    pid2 = fork();
    if (pid2 < 0) {
        fprintf(stderr, "Error: Unable to fork second child process\n");
        exit(EXIT_FAILURE);
    } else if (pid2 == 0) {
        printf("p3: I am the second child process, my PID is %d\n", getpid());
        exit(EXIT_SUCCESS);
    }
    
    // Fork third child process (p4)
    pid3 = fork();
    if (pid3 < 0) {
        fprintf(stderr, "Error: Unable to fork third child process\n");
        exit(EXIT_FAILURE);
    } else if (pid3 == 0) {
        printf("p4: I am the third child process, my PID is %d\n", getpid());
        exit(EXIT_SUCCESS);
    }
    
    // Parent process (p1) waits for child processes to finish
    int status;
    waitpid(pid1, &status, 0);
    waitpid(pid2, &status, 0);
    waitpid(pid3, &status, 0);
    
    printf("p1: All child processes have finished\n");
    
  return 0;
}