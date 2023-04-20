// write a c program for sjf scheduling algo

// Enter the number of processes: 4
// Enter the burst time for process 1: 6
// Enter the burst time for process 2: 8
// Enter the burst time for process 3: 4
// Enter the burst time for process 4: 5
// Process Burst Time     Waiting Time    Turnaround Time
// 4       5               4               9
// 3       4               0               4
// 1       6               9               15
// 2       8               15              23
// Average Waiting Time: 7.000000
// Average Turnaround Time: 12.750000


#include <stdio.h>

struct process {
    int pid; // process ID
    int burst_time; // burst time 
    int waiting_time; // waiting time 
    int turnaround_time; // turnaround time 
};

void sjf(struct process p[], int n) {
    int i, j, min, sum_waiting_time = 0, sum_turnaround_time = 0;
    double avg_waiting_time, avg_turnaround_time;
    struct process temp;

    // sort the processes by burst time in ascending order using selection sort
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (p[j].burst_time < p[min].burst_time) {
                min = j;
            }
        }
        temp = p[i];
        p[i] = p[min];
        p[min] = temp;
    }

    // calculate waiting time and turnaround time for each process
    p[0].waiting_time = 0;
    p[0].turnaround_time = p[0].burst_time;
    for (i = 1; i < n; i++) {
        p[i].waiting_time = p[i-1].burst_time + p[i-1].waiting_time;
        p[i].turnaround_time = p[i].burst_time + p[i].waiting_time;
    }

    // calculate average waiting time and average turnaround time
    for (i = 0; i < n; i++) {
        sum_waiting_time += p[i].waiting_time;
        sum_turnaround_time += p[i].turnaround_time;
    }
    avg_waiting_time = (double) sum_waiting_time / n;
    avg_turnaround_time = (double) sum_turnaround_time / n;

    // print the results
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].burst_time, p[i].waiting_time, p[i].turnaround_time);
    }
    printf("Average Waiting Time: %f\n", avg_waiting_time);
    printf("Average Turnaround Time: %f\n", avg_turnaround_time);
}

int main() {
    int i, n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process p[n];
    for (i = 0; i < n; i++) {
        printf("Enter the burst time for process %d: ", i+1);
        scanf("%d", &p[i].burst_time);
        p[i].pid = i+1;
    }

    sjf(p, n);

    return 0;
}



