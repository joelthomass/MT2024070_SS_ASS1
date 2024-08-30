#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd;
    ssize_t bytes_written;
    off_t offset;
    
    fd = open("10.txt", O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
    
    bytes_written = write(fd, "1234567890", 10);
    if (bytes_written != 10) {
        perror("Error writing to file");
        close(fd);
        return 1;
    }
    
    offset = lseek(fd, 10, SEEK_CUR);
    if (offset == -1) {
        perror("Error with lseek");
        close(fd);
        return 1;
    } else {
        printf("lseek returned: %ld\n", offset);
    }
    
    bytes_written = write(fd, "ABCDEFGHIJ", 10);
    if (bytes_written != 10) {
        perror("Error writing to file");
        close(fd);
        return 1;
    }

    close(fd);

    return 0;
}
/*
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/10$ touch 10.c
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/10$ nano 10.c
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/10$ gcc -o 10 10.c
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/10$ ./10
lseek returned: 20
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/10$ 
*/
