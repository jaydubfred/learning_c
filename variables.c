#include <stdio.h>

#ifdef DEBUG
#define LOG(x) printf(x)
#else
#define LOG(x)
#endif

#define MAX_IDS 32 

struct employee_t {
    int id;
    char firstname[64];
    char lastname[64];
    float income;
    int ismanager;
};

int main(){
    char* string = "Hello";
    LOG(string);    
    
    
    int ids[MAX_IDS] = {0,1,2};
    
    printf("%d\n", ids[0]);
    
    ids[1] = 0x41;

    printf("%d\n", ids[1]);
    int i = 0;   
    for(i = 0; i < 32; i += 1){
        ids[i] = 2*i;
        printf("Cur id %d is %d\n", i, ids[i]);
    }
    i = 0;
    while( i < 32 ){
        ids[i] = 3*i;
        printf("Cur id %d is %d\n", i, ids[i]);
        i += 1;
    }
}