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

#define MAX_IDS 32 

struct database_header_t {
    unsigned short version;
    unsigned short employees;
    unsigned int filesize;
};

int main(int argc, char *argv[]){
    if (argc != 2){
        printf("Usage: %s <filename>\n", argv[0]);
        return 0;
    }
    // rw for user, r for group and everyone
    int fd = open(argv[1], O_RDWR | O_CREAT, 0644); 
    if (fd == -1){
        perror("open");
        return -1;
    }
    
    struct database_header_t head = {0};
    struct stat dbStat = {0};

    if (fd == -1){
        perror("open");
        return -1;
    }
    else if(read(fd, &head, sizeof(head)) != sizeof(head)){
        perror("read");
        close(fd);
        return -1;
    }
    
    if (fstat(fd, &dbStat) < 0){
        perror("fstat");
        close(fd);
        return -1;
    }
    printf("DB file length reported by stat: %lld\n", dbStat.st_size);
    char *mydata = "hello there file!\n";
    write(fd, mydata, strlen(mydata));
}