#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#ifdef DEBUG
#define LOG(x) printf(x)
#else
#define LOG(x)
#endif

#define MAX_EMPLOYEES 32 

struct employee_t {
    int id;
    int income;
    bool staff;
};

int initialize_employee(struct employee_t *e){
    static int numEmployees = 0;
    numEmployees += 1;

    e->id = numEmployees;
    e->income = 0;
    e->staff = false;

    return numEmployees;
}

int main(){
    int n = 4;
    struct employee_t employees_static[n]; // n has to be known at compile time
    struct employee_t *employees_d = malloc(sizeof(struct employee_t)*n); // n can be dynamic at runtime
    if (employees_d == NULL){
        printf("Allocator failed\n");
        return -1;
    }
    int i = 0;
    for (i = 0; i < n; i+= 1){
        int id = initialize_employee(&employees_d[i]);
        printf("New employee, ID is %d\n", id);
    }
    initialize_employee(&employees_d[0]);
    printf("%d\n", employees_d[0].income);
    
    free(employees_d);
    employees_d = NULL;
}