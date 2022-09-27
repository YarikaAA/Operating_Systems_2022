#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char** argv){

	for (int i = 0; i < argv[1][0] - '0'; ++i){
		fork();
		sleep(5);
	}

	return EXIT_SUCCESS;

}