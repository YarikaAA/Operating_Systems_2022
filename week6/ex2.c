#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void sort(int *pInt, int *pInt1, int *pInt2, int n);

int main() {

    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int *process = (int*) malloc(n * sizeof(int));
    int *arrivalTime = (int*) malloc(n * sizeof(int));
    int *burstTime = (int*) malloc(n * sizeof(int));
    int *finishTime = (int*) malloc(n * sizeof(int));
    int *turnAroundTime = (int*) malloc(n * sizeof(int));
    int *waitingTime = (int*) malloc(n * sizeof(int));

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

    sort(arrivalTime, burstTime, process, n);

    finishTime[0] = arrivalTime[0] + burstTime[0];
    turnAroundTime[0] = finishTime[0] - arrivalTime[0];
    waitingTime[0] = turnAroundTime[0] - burstTime[0];

    for (int i = 1; i < n; ++i) {
        finishTime[i] = finishTime[i - 1] + burstTime[i];
        turnAroundTime[i] = finishTime[i] - arrivalTime[i];
        waitingTime[i] = turnAroundTime[i] - burstTime[i];
    }

    printf("Process\tArrival Time\tBurst Time\tFinish Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; ++i) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", process[i], arrivalTime[i], burstTime[i], finishTime[i], turnAroundTime[i], waitingTime[i]);
    }

    float averageTurnAroundTime = 0;
    float averageWaitingTime = 0;

    for (int i = 0; i < n; ++i) {
        averageTurnAroundTime += turnAroundTime[i];
        averageWaitingTime += waitingTime[i];
    }

    averageTurnAroundTime /= n;
    averageWaitingTime /= n;

    printf("Average Turn Around Time: %.2f\n", averageTurnAroundTime);
    printf("Average Waiting Time: %.2f\n", averageWaitingTime);


    return EXIT_SUCCESS;
}

void sort(int *pInt, int *pInt1, int *pInt2, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (pInt[i] > pInt[j]) {
                int temp = pInt[i];
                pInt[i] = pInt[j];
                pInt[j] = temp;

                temp = pInt1[i];
                pInt1[i] = pInt1[j];
                pInt1[j] = temp;

                temp = pInt2[i];
                pInt2[i] = pInt2[j];
                pInt2[j] = temp;
            }
            if(pInt[i] == pInt[j]) {
                if (pInt1[i] > pInt1[j]) {
                    int temp = pInt[i];
                    pInt[i] = pInt[j];
                    pInt[j] = temp;

                    temp = pInt1[i];
                    pInt1[i] = pInt1[j];
                    pInt1[j] = temp;

                    temp = pInt2[i];
                    pInt2[i] = pInt2[j];
                    pInt2[j] = temp;
                }
            }

            if(pInt1[i] > pInt1[j]) {
                if (pInt[i] + pInt1[i] > pInt[j] + pInt1[j]) {
                    int temp = pInt[i];
                    pInt[i] = pInt[j];
                    pInt[j] = temp;

                    temp = pInt1[i];
                    pInt1[i] = pInt1[j];
                    pInt1[j] = temp;

                    temp = pInt2[i];
                    pInt2[i] = pInt2[j];
                    pInt2[j] = temp;
                }
            }

        }
    }
}

