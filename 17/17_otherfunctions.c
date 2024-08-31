#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

void apply_file_lock(int file_desc, int operation, short lock_type) {
    struct flock file_lock;
    memset(&file_lock, 0, sizeof(file_lock));

    file_lock.l_type = lock_type;    
    file_lock.l_whence = SEEK_SET;   
    file_lock.l_start = 0;           
    file_lock.l_len = 0;      

    if (fcntl(file_desc, operation, &file_lock) == -1) {
        perror("Failed to apply file lock");
        exit(EXIT_FAILURE);
    }
}

int main() {
    int file_desc;
    const char *file_path = "ticket_storing_file.txt";
    char buffer[12]; 
    int ticket_num;

    file_desc = open(file_path, O_RDWR);
    if (file_desc < 0) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    apply_file_lock(file_desc, F_SETLKW, F_WRLCK);

    ssize_t bytes_read = read(file_desc, buffer, sizeof(buffer) - 1);
    if (bytes_read < 0) {
        perror("Error reading file");
        close(file_desc);
        return EXIT_FAILURE;
    }

    buffer[bytes_read] = '\0'; 
    ticket_num = atoi(buffer);  

    ticket_num++;
    printf("Updated ticket number: %d\n", ticket_num);

    if (lseek(file_desc, 0, SEEK_SET) < 0) {
        perror("Error seeking file");
        close(file_desc);
        return EXIT_FAILURE;
    }

    snprintf(buffer, sizeof(buffer), "%d", ticket_num);
    if (write(file_desc, buffer, strlen(buffer)) < 0) {
        perror("Error writing file");
        close(file_desc);
        return EXIT_FAILURE;
    }

    apply_file_lock(file_desc, F_SETLKW, F_UNLCK);

    if (close(file_desc) < 0) {
        perror("Error closing file");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
/*
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/17$ gcc -o 17_storage 17_storage.c
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/17$ gcc -o 17_otherfunctions 17_otherfunctions.c
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/17$ ./17_storage
Ticket number 100 has been written to ticket_storing_file.txt
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/17$ ./17_otherfunctions
Updated ticket number: 101
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/17$ 
*/
