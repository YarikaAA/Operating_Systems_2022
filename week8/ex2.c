#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {

  void * arr;

  for(int i = 1; i < 2400; i++) {
    // allocate 10 mb to the array
    arr = malloc(10 * 1024 * 1024);  
    // fill it with zeros
    memset(arr, 0, bytes);      
    // sleep for 1 second  
    sleep(1);                     
  }

  free(arr);

	return 0;
}

// 'si' and'so' fields display the amount of memory that has been swapped in and out.
// With 24G of physical memory available on my computer, I specify allocation of 2400 10 mb blocks.
// If swap is off, the OS terminates my program after allocating all available RAM. 
// If I add swap, it uses swap after allocating all of the physical RAM, 
// and the "si" and "so" values are both bigger than 0.
// However, because key OS programs' memory is moved to swap and the hard disk is too sluggish, 
// freezes frequently occur while utilizing swap.