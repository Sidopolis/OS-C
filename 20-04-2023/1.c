// Write a C-program for FCFS Schdeuling Age

 // Input-:  processes = P1, P2, P3
        //Burst time = 5, 8, 12
        
// Output-:
//  Processes  Burst    Waiting    Turn around
//   1          5        0           5
//   2          8        5           13
//   3          12       13          25

// The Average Waiting time = 6.000000   and
// The Average turn around time = 14.333333

#include<stdio.h>
int main()
{
    int n,bt[30], wait_t[30], turn_ar_t[30], av_wt_t=0, avturn_ar_t=0, i,j;
    printf("Enter the total number of processes: ");                               // max process should be until 30 processes are entered
    scanf("%d",&n);

    printf("Enter the processes burst time:  ");
    for(i=0;i<n;i++)                                 // burst time of each process is taken as input
    {
        printf("P%d: ",i+1);                              // processes are entered in the form of P1, P2, P3
        scanf("%d",&bt[i]);                               // burst time of each process is taken as input
    }

    wait_t[0]=0;                                           // waiting time of first process is 0

    for(i=1;i<n;i++)                                  // waiting time of each process is calculated
    {
        wait_t[i]=0;
        for(j=0;j<i;j++)
            wait_t[i]+=bt[j];
    }
 
printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");     // processes are printed in the form of P1, P2, P3
 
    for(i=0;i<n;i++)
    {
        turn_ar_t[i]=bt[i]+wait_t[i];                                  // turn around time of each process is calculated
        av_wt_t+=wait_t[i];                                             // waiting time of each process is added
        avturn_ar_t+=turn_ar_t[i];                                      // turn around time of each process is added
        printf("\nP[%d]\t\t%d\t\t\t%d\t\t\t\t%d",i+1,bt[i],wait_t[i],turn_ar_t[i]);               
    }
 
    av_wt_t/=i;        // average calculation is done here
    avturn_ar_t/=i;  // average calculation is done here
    printf("\nAverage Waiting Time:%d",av_wt_t);
    printf("\nAverage Turnaround Time:%d",avturn_ar_t);
 
    return 0;
}
