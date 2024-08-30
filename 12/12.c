#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

void print_file_mode(int fd) {
    int flags = fcntl(fd, F_GETFL); 
    if (flags == -1) {
        perror("fcntl");
        return;
    }

    int access_mode = flags & O_ACCMODE; 

    if (access_mode == O_RDONLY) {
        printf("read-only mode\n");
    } else if (access_mode == O_WRONLY) {
        printf("write-only mode.\n");
    } else if (access_mode == O_RDWR) {
        printf("read-write mode.\n");
    } else {
        printf("Unknown file mode.\n");
    }
}

int main() {
    int fd = open("12.txt", O_RDWR);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    print_file_mode(fd);

    close(fd);
    return 0;
}
/*
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/12$ gcc -o 12 12.c
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/12$ ./12
read-write mode.
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/12$ 
*/
