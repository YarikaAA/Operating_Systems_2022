/*
Exercise description:
    1. You have to write a function convert which converts a given number x from a numeral system s to another
    numeral system t where t, s are numbers in the range [2-10]. If the
    given number is wrong or s or t are out of the previous range then
    we should print the error message “cannot convert!”.
    2. Notes:
        – We assume that the user enters a non-negative number.
        – The numerals in the number systems are represented by decimal
            numbers [0-9]. For instance, in the number system 7, we have the numerals [0, 1, 2, 3, 4, 5, 6].

Solution:
*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
 
char *Scale="0123456789";
 
int dig2int(char d){
    for (int i = 0; i < 10; ++i){ 
        if (Scale[i] == d) return i;
    }
}
 
char  *convert(char *n, int from, int to){
    
    int j, l = strlen(n), p = 0, k = 99;
    char *buf;
    
    for (int i = 0; i < l; ++i){
        p = p * from + dig2int(n[i]);
    }

    buf = (char *) calloc(100,1), l = 0;

    while (1){
        j = p % to;
        buf[k--] = Scale[j];
        l++;
        p = p / to;
        if (p == 0) break;
    }  

    j = 0; k++;

    while (1){
        buf[j++] = buf[k++];
        if (k == 100) break;
    }  

    buf = (char *) realloc(buf,(l+1));
    return buf;
} 

int main(int argc, char *argv[]){
 
    char P[10000];
    int from, to;

    scanf("%s%d%d", P, &from, &to);

    if(from > 11 || to > 11 from < 2 || to < 2){
        printf("Cannot convert!");
    }

    printf("%s\n", convert(P, from, to));

    return 0;
 
}