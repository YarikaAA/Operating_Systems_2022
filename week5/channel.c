#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char** argv) {

    //The publisher/subscriber is always ready for reading/writing messages from/to stdin/stdout.
    //work till ctrl+C 
    

        int fd[2];
        // fd[0] - read end
        // fd[1] - write end
        if(pipe(fd) == -1) { 
            printf("Error");
            return 1;
        };

        int id = fork();

    while(1){
        if (id == 0) {
            close(fd[0]);
            char message[1024];
            fgets(message, 1024, stdin);
            write(fd[1], message, sizeof(message));
            close(fd[1]);
        } else {
            close(fd[1]);
            char y[1024];
            read(fd[0], y, 1024);
            for (int i = 0; i < argv[1][0] - '0'; ++i){
                printf("Sub\nPublication: %s\n", y);
            }
            
            close(fd[0]);
        }
    }

    return 0;
}