#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int foo(int age){
    int currentYear = 2022;
    return currentYear - age;
}

int main() {

    const int x = 10;
    const int *q = &x;
    const int withCells = (const int) malloc(5);
    const char* p = &withCells;
    memset(p, *q, 5);

    printf("%p %p %p %p %p\n\n", p, p + 1, p + 2, p + 3, p + 4);

    for(int i = 0; i < 5; ++i) {
        scanf("%d", &p[i]);
    }

    printf("%d %d %d %d %d\n", *p, *(p + 1), *(p + 2), *(p + 3), *(p + 4));

    for (int i = 0; i < 5; ++i) {
        p[i] = foo(p[i]);
    }

    printf("%d %d %d %d %d\n", *p, *(p + 1), *(p + 2), *(p + 3), *(p + 4));

    free(p);

    return EXIT_SUCCESS;
}