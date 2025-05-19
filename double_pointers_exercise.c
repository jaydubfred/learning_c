#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#ifdef DEBUG
#define LOG(x) printf(x)
#else
#define LOG(x)
#endif

#define MAX_EMPLOYEES 32 

int foo(int **ptr) {
    int value = 10;
    *ptr = malloc(sizeof(int));  
 
    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return -1;
    }
    **ptr = value; 

    printf("%d\n", **ptr);
    return 0;
}

int main(){
    int *first = malloc(sizeof(int));
    printf("%d\n", sizeof(int));
    return foo(&first);
}