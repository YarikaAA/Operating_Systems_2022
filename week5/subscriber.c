#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>

#define MAX_BUF 1024

int main(){

    printf("Subscriber\n");

    int fd;
    char * myfifo = "/tmp/ex1";
    char buf[MAX_BUF];

    while(1){
        /* open, read, and display the message from the FIFO */
        fd = open(myfifo, O_RDONLY);
        read(fd, buf, MAX_BUF);
        printf("Publication: %s\n", buf);
        close(fd);
        usleep(1000);
    }

    return 0;
}