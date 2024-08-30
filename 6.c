#include <unistd.h> 
#include <stdio.h> 

#define BUFFER_SIZE 1024 

int main() {
    char buffer[BUFFER_SIZE]; 
    ssize_t bytesRead;

    while ((bytesRead = read(STDIN_FILENO, buffer, BUFFER_SIZE)) > 0) {
        if (write(STDOUT_FILENO, buffer, bytesRead) == -1) {
            perror("Error writing to STDOUT");
            return 1;
        }
    }

    if (bytesRead == -1) {
        perror("Error reading from STDIN");
        return 1;
    }

    return 0;
}
/*
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions$ gcc -o 6 6.c
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions$ ./6
mera 6th question ka input
mera 6th question ka input


l
l
joel
*/
