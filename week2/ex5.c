/*
Exercise description:
    1. Write a function tribonacci that takes as argument n and returns the value of Tn (0 ≤ n ≤ 37)
    2. You are neither allowed to use arrays nor function recursion
    3. Write a program ex5.c which calls the above function with arguments 4, 36 and print the output to standard output

Solution:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Tribo(int n){
    if (n < 1){
        return;
    }
 
    int first = 0, second = 1, third = 1;
    int curr = first + second + third;
 
    for (int i = 3; i < n; i++){
        curr = first + second + third;
        first = second;
        second = third;
        third = curr;
    }

    printf("Tribonacci with n = %d: %d\n", n, curr);
}
 
 
int main(int argc, char *argv[]){
    
    int n = 4;
    Tribo(n);

    n = 36;
    Tribo(n);

    return 0;
}