#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char** argv){

    printf("Publisher\n");

    int fd;
    int n = atoi(argv[1]);
    
    char * myfifo = "/tmp/ex1";
    char message[1024];

    /* create the FIFO (named pipe) */
    mkfifo(myfifo, 0666);

    while(1){

        fd = open(myfifo, O_WRONLY);
        fgets(message, 1024, stdin);
        for (int i = 0; i < n; ++i){
            write(fd, message, sizeof(message));
        }
        close(fd);
    }

    /* remove the FIFO */
    unlink(myfifo);

    return 0;
}