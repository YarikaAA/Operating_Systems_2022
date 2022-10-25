#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *my_realloc(void *ptr, int new_size){

    if (ptr == NULL){
        return malloc(new_size);
    }

    if (new_size == 0){
        free(ptr);
        return NULL;
    }

    void *_ptr = malloc(new_size);
    memcpy(_ptr, ptr, new_size);
    free(ptr);

    return _ptr;
}

int main(){

    char *string;
    string = NULL;
    string = my_realloc(string, 18);
    strcpy(string, "Try with length 18");
    printf("%s ", string);

    return EXIT_SUCCESS;
}
