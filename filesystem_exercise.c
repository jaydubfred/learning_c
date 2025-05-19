#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


#ifdef DEBUG
#define LOG(x) printf(x)
#else
#define LOG(x)
#endif

#define MAX_EMPLOYEES 32 

void print_the_flag() {
    int no_bytes = 64;
    char contents[no_bytes];
    int fd = open("./hexdump", O_RDWR | O_CREAT, 0644);
    read(fd, contents, sizeof(contents));
    printf("%s", contents); 
}


int main(){
    print_the_flag();
}