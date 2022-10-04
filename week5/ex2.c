#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct Thread{
    unsigned long id;
    int i;
    char* message;
} Thread;

void* foo(void* p){
    // usleep(10);
    Thread* t = (Thread*)p;
    t->id = (unsigned long) pthread_self();
    printf("%s, id: %lu\n", t->message, t->id);
    free(p);
    pthread_exit(NULL);
}

int main(){
    int n = 6;
    for (int j = 0; j < n; j++)  {
        Thread* threads = (Thread*) malloc(sizeof(Thread));

        threads->id = -1;
        threads->i = j;

        char* msg = (char*) malloc(256);

        sprintf(msg, "Hello from thread: %i", j);

        threads->message = msg;

        pthread_t thread;
        if (pthread_create(&thread, NULL, foo, threads)) {
            printf("ERROR\n");
            return -1;
        }
        else {
            printf("CREATED %d\n", j);
        }
        

        sleep(1);
        //pthread_join(thread, NULL);
    }
}