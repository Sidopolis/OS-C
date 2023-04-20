#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(int);
    int sum_even = 0, sum_odd = 0;

    pid_t pid = fork();

    if (pid == 0) { // child process finds sum of odd numbers
        for (int i = 0; i < n; i++) {
            if (arr[i] % 2 != 0) {
                sum_odd += arr[i];
            }
        }
        printf("Sum of odd numbers = %d\n", sum_odd);
    } else if (pid > 0) { // parent process finds sum of even numbers
        for (int i = 0; i < n; i++) {
            if (arr[i] % 2 == 0) {
                sum_even += arr[i];
            }
        }
        printf("Sum of even numbers = %d\n", sum_even);
    } else { // error
        fprintf(stderr, "Fork failed.\n");
        return 1;
    }

   return 0;
}