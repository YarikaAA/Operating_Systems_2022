#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <unistd.h>
#include <sys/resource.h>
struct rusage usage;

int main() {

    for (int i = 0; i < 2400; i++) {
        void *s = malloc(10 * 1024 * 1024);
        memset(s, 0, 10 * 1024 * 1024);
        getrusage(RUSAGE_SELF, &usage);
        printf("Mem %ldKB\n", usage.ru_maxrss);
        sleep(1);
    }

    return(0);
}


// 'si' and'so' fields display the amount of memory that has been swapped in and out.
// With 24G of physical memory available on my computer, I specify allocation of 2400 10 mb blocks.
// If swap is off, the OS terminates my program after allocating all available RAM. 
// If I add swap, it uses swap after allocating all of the physical RAM, 
// and the "si" and "so" values are both bigger than 0.
// However, because key OS programs' memory is moved to swap and the hard disk is too sluggish, 
// freezes frequently occur while utilizing swap.
