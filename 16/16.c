#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

void set_lock(int fd, int cmd, short type) {
    struct flock lock;
    memset(&lock, 0, sizeof(lock));

    lock.l_type = type;    
    lock.l_whence = SEEK_SET; 
    lock.l_start = 0;       
    lock.l_len = 0;        

    if (fcntl(fd, cmd, &lock) == -1) {
        perror("fcntl");
        exit(EXIT_FAILURE);
    }
}

void test_write_lock(int fd) {
    printf("Acquiring write lock...\n");
    set_lock(fd, F_SETLKW, F_WRLCK); 

    printf("Write lock acquired. Press Enter to release...\n");
    getchar(); 

    printf("Releasing write lock...\n");
    set_lock(fd, F_SETLKW, F_UNLCK); 
}

void test_read_lock(int fd) {
    printf("Acquiring read lock...\n");
    set_lock(fd, F_SETLKW, F_RDLCK); 

    printf("Read lock acquired. Press Enter to release...\n");
    getchar(); 

    printf("Releasing read lock...\n");
    set_lock(fd, F_SETLKW, F_UNLCK); 
}

int main() {
    int fd;
    const char *filename = "16.txt";

    fd = open(filename, O_RDWR | O_CREAT, 0666);
    if (fd < 0) {
        perror("open");
        return EXIT_FAILURE;
    }

    test_write_lock(fd);

    test_read_lock(fd);

    close(fd);

    return EXIT_SUCCESS;
}
/*
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/16$ nano 16.c
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/16$ gcc -o 16 16.c
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/16$ ./16
Acquiring write lock...
Write lock acquired. Press Enter to release...

Releasing write lock...
Acquiring read lock...
Read lock acquired. Press Enter to release...

Releasing read lock...
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/16$ 
*/
