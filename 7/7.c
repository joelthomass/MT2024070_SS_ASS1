#include <fcntl.h>   
#include <unistd.h>  
#include <stdio.h>  

#define BUFFER_SIZE 1024 

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "No proper arguments given.Proper use: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    int src_fd = open(argv[1], O_RDONLY);
    if (src_fd == -1) {
        perror("Could not open source file");
        return 1;
    }

    int dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd == -1) {
        perror("Could not open destination file");
        close(src_fd); 
        return 1;
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;

    while ((bytesRead = read(src_fd, buffer, BUFFER_SIZE)) > 0) {
        if (write(dest_fd, buffer, bytesRead) != bytesRead) {
            perror("Writing process failed");
            close(src_fd);
            close(dest_fd);
            return 1;
        }
    }

    if (bytesRead == -1) {
        perror("Error reading from source file");
    }

    close(src_fd);
    close(dest_fd);

    return 0;
}
/*
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions$ mkdir 7
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions$ cd 7
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/7$ touch 7.c
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/7$ nano 7.c
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/7$ touch first.txt
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/7$ nano first.txt
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/7$ touch second.txt
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/7$ gcc -o 7 7.c
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/7$ ./7 first.txt second.txt
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/7$ nano second.txt
*/
