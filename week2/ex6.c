/*
Exercise description:
    1. Write a program which prints the following patterns.
    
Solution:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void triangl(int n){
    
    for (int i = 0; i <= n; ++i){
        for (int j = 0; j <= n; ++j){
            if(i > j){
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }

    printf("\n");

}

void pyramid(int n){

    for (int i = 0; i <= n / 2 + 1; ++i){
        for (int j = 0; j <= n / 2 + 1; ++j){
            if(i > j){
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }

    for (int i = n / 2 - 1; i >= 0; --i){
        for (int j = 0; j <= n / 2; ++j){
            if(i < j){
                printf(" ");
            }
            else{
                printf("*");
            }
        }
        printf("\n");
    }

    printf("\n");

}

void near_square(int n){
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            printf("*");
        }
        printf("\n");
    }
}
 
int main(int argc, char *argv[]){
    
    int n;
    scanf("%d", &n);

    triangl(n);

    if(n % 2 != 0){
        pyramid(n);
    }

    near_square(n);


    return 0;
}