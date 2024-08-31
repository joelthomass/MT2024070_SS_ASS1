#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define RECORD_SIZE 50 

void apply_lock(int fd, int record_num, int lock_type) {
    struct flock lock;
    memset(&lock, 0, sizeof(lock));
    
    lock.l_type = lock_type;   
    lock.l_whence = SEEK_SET;    
    lock.l_start = record_num * RECORD_SIZE; 
    lock.l_len = RECORD_SIZE;     
    
    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("Failed to apply lock");
        exit(EXIT_FAILURE);
    }
}

void release_lock(int fd, int record_num) {
    struct flock lock;
    memset(&lock, 0, sizeof(lock));
    
    lock.l_type = F_UNLCK;      
    lock.l_whence = SEEK_SET;
    lock.l_start = record_num * RECORD_SIZE;
    lock.l_len = RECORD_SIZE;
    
    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("Failed to release lock");
        exit(EXIT_FAILURE);
    }
}

void read_record(int fd, int record_num) {
    char buffer[RECORD_SIZE + 1]; 

    apply_lock(fd, record_num, F_RDLCK);

    lseek(fd, record_num * RECORD_SIZE, SEEK_SET);
    if (read(fd, buffer, RECORD_SIZE) < 0) {
        perror("Failed to read the record");
        exit(EXIT_FAILURE);
    }

    buffer[RECORD_SIZE] = '\0'; 
    printf("Read Record %d: %s", record_num + 1, buffer);

    release_lock(fd, record_num);
}

void write_record(int fd, int record_num, const char *data) {
    apply_lock(fd, record_num, F_WRLCK);

    lseek(fd, record_num * RECORD_SIZE, SEEK_SET);
    if (write(fd, data, strlen(data)) < 0) {
        perror("Failed to write to the record");
        exit(EXIT_FAILURE);
    }

    printf("Written to Record %d: %s", record_num + 1, data);

    release_lock(fd, record_num);
}

int main() {
    int fd;
    const char *filename = "18_records.txt";

    fd = open(filename, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the file");
        return EXIT_FAILURE;
    }

    read_record(fd, 0);

    write_record(fd, 1, "Record 2: Updated data\n");

    read_record(fd, 1);

    close(fd);

    return EXIT_SUCCESS;
}
/*
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/18$ gcc -o 18_create 18_create.c
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/18$ gcc -o 18_operations 18_operations.c
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/18$ ./18_create
Three records have been written to 18_records.txt
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/18$ ./18_operations
Read Record 1: Record 1: Initial data
Written to Record 2: Record 2: Updated data
Read Record 2: Record 2: Updated data
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/18$ 
*/
