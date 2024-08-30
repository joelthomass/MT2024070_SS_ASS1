#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int i = 0;
    char filename[25];
    int fd;

    while (1) {
        for (int j = 0; j < 5; j++) {
            snprintf(filename, sizeof(filename), "file_%d.txt", i++);
 
            fd = open(filename, O_RDWR | O_CREAT, 0644);
            if (fd == -1) {
                perror("Error creating file");
                exit(1);
            }

            printf("Created file: %s with file descriptor: %d\n", filename, fd);
            close(fd);
        }
        sleep(2); 
    }

    return 0;
}

/*
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions$ ls -l /proc/7643/fd
total 0
lrwx------ 1 joelthomas joelthomas 64 Aug 30 13:58 0 -> /dev/pts/0
lrwx------ 1 joelthomas joelthomas 64 Aug 30 13:58 1 -> /dev/pts/0
lrwx------ 1 joelthomas joelthomas 64 Aug 30 13:58 2 -> /dev/pts/0
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions$ kill 7643
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions$ 
*/
