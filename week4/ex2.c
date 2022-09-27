#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


// Calculate the dot product of the vectors u and v from the component [start] till the component [end] exclusively.
int dotprod(int u[], int v[], int start, int end){

	int result = 0;
	
	for (int i = start; i < end; i++){
		result += u[i] * v[i];
	}

	return result;
}


int main(void){

	//for random value
	srand (time(NULL));

	//size of vectors
	int l = 120;

	//file connection
	
	
	//declaretion of 2 vectors
	int u[l], v[l];

	//just fill 2 vectors with random values from 0 to 99
	for (int i = 0; i < l; ++i){
		u[i] = rand() % 100;
		v[i] = rand() % 100;
	}

	//number of processors that will be used
	int n;
	scanf("%d", &n);

	int t;

	//to equally separate elements 
	if(l % n == 0){
		t = l / n;
	}

	printf("%d\n", t);
	//array of n processes
	pid_t pids[n];

	//devided processes to differen processors
	for (int i = 0; i < n; ++i){
		pids[i] = fork();

		if(pids[i] == 0){
			//open file to write a results of prcesses
			FILE * f = fopen("temp.txt", "a");
      		fprintf(f, "%d\n", dotprod(u, v, i * t, i * t + t));
      		printf("ghg\n");
      		fclose(f);
			//printf("%d, i = %d\n", dotprod(&u, &v, i * t, i * t + t), y);
		}
		else{
			return(EXIT_SUCCESS);
		}
	}

	//open file to read
	FILE *f = fopen("temp.txt", "r");

	int result = 0;

	//scan the values and sum them 
	for (int i = 0; i < n; ++i){
		int uwu;
		fscanf(f, "%d[^\n]", &uwu);
		printf("%d\n", uwu);
		result += uwu;
	}

	printf("Result of DotProduct is %d", result);
	
	fclose(f);

	return EXIT_SUCCESS;

}

/*
Example:
Assume that
u = [u1, u2, u3, u4]
v = [v1, v2, v3, v4]
k=1 ==> n = 2 processes
Equally distribute the dot product calculation task. We have multiple ways to distribute the task equally.
1- A possible task distribution is as follows:
First process will calculate dot product for the first two components
Second process will calculate dot product for the last two components
The computation result of the first process is u1 * v1 + u2 * v2 ==> c1
The computation result of the second process is u3 * v3 + u4 * v4 ==> c2
2- Another possible distribution is as follows:
First process will calculate dot product for the even components
Second process will calculate dot product for the odd components
The computation result of the first process is u2 * v2 + u4 * v4 ==> c1
The computation result of the second process is u1 * v1 + u3 * v3 ==> c2
The file temp.txt will contain as follows: (format is not restricted)
-------------------
c1
c2
-------------------
The "main" process will aggregate all dot product computations of its children
It will read the lines and aggregate.
c1 + c2 ==> result of u * v
*/