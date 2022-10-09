#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){

    int n, q;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the quantum: ");
    scanf("%d", &q);

    int *process = (int*) malloc(n * sizeof(int));
    int *arrivalTime = (int*) malloc(n * sizeof(int));
    int *burstTime = (int*) malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i) {
        process[i] = i + 1;
    }

    printf("Enter the arrival time of each process:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arrivalTime[i]);
    }

    printf("Enter the burst time of each process:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &burstTime[i]);
    }


    int *temp = (int*) malloc(n * sizeof(int));
    memcpy(temp, burstTime, n * sizeof(int));

    int time = 0;
    int count = 0;
    int i = 0;
    int remain = n;
    float averageTurnAroundTime = 0;
    float averageWaitingTime = 0;

    printf("Process\tArrival Time\tBurst Time\tFinish Time\tTurnaround Time\tWaiting Time\n");

    while (count != n && remain != 0) {
        if (temp[i] <= q && temp[i] > 0) {
            time += temp[i];
            temp[i] = 0;
            count++;
        } else if (temp[i] > 0) {
            temp[i] -= q;
            time += q;
        }
        if (temp[i] == 0 &&  count == 1) {
            remain--;
            printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", process[i], arrivalTime[i], burstTime[i], time, time - arrivalTime[i], time - arrivalTime[i] - burstTime[i]);
            averageWaitingTime += time - arrivalTime[i] - burstTime[i];
            averageTurnAroundTime += time - arrivalTime[i];
            count = 0;
        }
        if (i == n - 1) {
            i = 0;
        } else if (arrivalTime[i + 1] <= time) {
            i++;
        } else {
            i = 0;
        }
    }

    averageTurnAroundTime /= n;
    averageWaitingTime /= n;

    printf("Average Turnaround Time: %.2f\n", averageTurnAroundTime);
    printf("Average Waiting Time: %.2f\n", averageWaitingTime);


    return EXIT_SUCCESS;
}