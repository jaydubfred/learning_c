#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#ifdef DEBUG
#define LOG(x) printf(x)
#else
#define LOG(x)
#endif

#define MAX_EMPLOYEES 32 

typedef enum {
    STATUS_GOOD,
    STATUS_BAD,
} status_t;

status_t foo(int **data, int len) {
    int *temp = NULL;
    temp = realloc(*data, len);
    
    if (temp == NULL){
        *data = NULL;
        return STATUS_BAD;
    }
    *data = temp;
    return STATUS_GOOD;
}

int main(){
    int *first = malloc(64);
    if (STATUS_BAD == foo(&first, 128)) {
        printf("Uh oh\n");
        return -1;
    }
    printf("Succes!\n");
    return 0;
}