/*
Exercise description:
  1. Write a program ex2.c that asks the user to type a string 
  character-by-character until dot (.) character is entered and 
  prints its reverse with double quotation
  2. Hints:
    – a string in C is an array of chars (more about arrays next week)
    – use strlen() function to get the length of a string

Solution:
*/

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

  char myString[256];
  scanf("%[^\n]%*c", myString);


  char temp;
  int str_size = strlen(myString);
  int final_size = str_size;

  //Loop for cut part after "."
  for (int i = 0; i < str_size; ++i){
    if(myString[i] == '.'){
      final_size = i;
      break;
    }
  }

  //delete symbol after "."
  for (int i = 0; i < str_size; ++i){
    if(i > final_size){
      myString[i] = '\0';
    }
  }
  
  // Loop from swap letters (from begin to end and so on)
  for(int i = 0; i < final_size / 2; ++i) {
    temp = myString[final_size - 1 - i];
    myString[final_size - 1 - i] = myString[i];
    myString[i] = temp;
  }

  printf("%s", myString);
  return 0;
}