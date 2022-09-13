/*
Exercise description:
  1. Create a program ex1.c that declares integer, unsigned short integer, signed long int, float and double variables.
  2. Find out how to assign maximum values for each variable (hint: use INT_MAX for integer, etc.)
  3. Print sizes and values of each variable
  4. Write a script ex1.sh to run your program.

Solution:
*/

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(int argc, char *argv[]) {

  int _int;
  unsigned short int _unsigned_short_int;
  signed long int _signed_long_int;
  float _float; 
  double _double;

  // Assign maximum values to each variable
  _int = INT_MAX;
  _unsigned_short_int = USHRT_MAX;
  _signed_long_int = LONG_MAX;
  _float = FLT_MAX;
  _double = DBL_MAX;
  
  // Print the sizes
  printf("The size of: \n_int is %lu bytes,\n_unsigned_short_int is %lu bytes,\n_signed_long_int is %lu bytes,\n_float is %lu bytes,\n_double is %lu bytes.\n", sizeof(_int), sizeof(_unsigned_short_int), sizeof(_signed_long_int), sizeof(_float), sizeof(_double));

  // Print the values
  printf("\nThe value of:\n_int is %d,\n_unsigned_short_int is %hu,\n_signed_long_int is %lu,\n_float is %f,\n_double is %f.\n", _int, _unsigned_short_int, _signed_long_int, _float, _double);

  return 0;
}
