#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char* argv){
    
    int n;
    printf("Enter the N: ");
    scanf("%d", &n);

    int *arr = (int*) malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i) {
        arr[i] = i;
    }

    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }

    free(arr);

    return EXIT_SUCCESS;
}
