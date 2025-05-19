#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#ifdef DEBUG
#define LOG(x) printf(x)
#else
#define LOG(x)
#endif

#define MAX_IDS 32 


int main(){
    int fd = open("./asdfasdf", O_RDONLY);
    if (fd == -1){
        perror("open");
        return -1;
    }
}