#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void){

	char a[100];

	while(1){
		fgets(a, 100, stdin);
		if(a == "^C"){
			return EXIT_SUCCESS;
		}
		else{
			if(a[strlen(a) - 3] == '&'){
				a[strlen() - 3] = '/0';
				if(fork() == 0){
					system(a);
					return 0;
				}
			}

			else{
				system(a);
			}
		}	
	}
	

	return EXIT_SUCCESS;

}