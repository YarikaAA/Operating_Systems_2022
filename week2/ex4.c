/*
Exercise description:
    1. Write a function count which returns the number of occurrences of an input character in a string
    2. Write a function countAll which prints the number of occurrences of each character in the input string

    2. Notes:
        – We assume that the user enters a non-negative number.
        – The numerals in the number systems are represented by decimal
            numbers [0-9]. For instance, in the number system 7, we have the numerals [0, 1, 2, 3, 4, 5, 6].

Solution:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int count(char *str, char c){
    
    int res = 0;
 
    for (int i = 0; i < strlen(str); ++i)
 
        if (str[i] == c){
            res++;
        }
 
    return res;
}

void countAll(char *str, char *str_out){

    int j = 0;

    for (int i = 0; i < strlen(str); ++i){
        
        strcat(str_out, str[0] + "");
        strcat(str_out, ": ");
        strcat(str_out, count(str, str[i]) + "");
    }

}
 
int main(int argc, char *argv[]){
    
    char *str = "along the tt";
    char str_out[10000];
 
 
    countAll(str, str_out);
    printf("%s\n", str);
    printf("%s\n", str_out);

    return 0;
}