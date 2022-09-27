#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h> 
#include <sys/types.h>

int main(){

    //declare timer
    clock_t t = clock();
    t = clock() - t;
    
    //create first child
    int pid1 = fork();

    //create second child
    int pid2 = fork();
    
    
    
    wait(NULL);

    if (pid1 > 0 && pid2 > 0) {
        wait(NULL);
        printf("Parent id: %d, ppid: %d, ", getpid(), getppid());
        t = clock() - t;
        printf("Execution time: %f\n", ((float)t) / CLOCKS_PER_SEC * 1000);
    }
    else if (pid1 > 0 && pid2 == 0){
        printf("Second child id: %d, ppid: %d, ", getpid(), getppid());
        t = clock() - t;
        printf("Execution time: %f\n", ((float)t) / CLOCKS_PER_SEC * 1000);
    }
    else if (pid1 == 0 && pid2 > 0){
        printf("First child id: %d, ppid: %d, ", getpid(), getppid());
        t = clock() - t;
        printf("Execution time: %f\n", ((float)t) / CLOCKS_PER_SEC * 1000);
    }
    else{
        return EXIT_SUCCESS;
    }

    return EXIT_SUCCESS;
}