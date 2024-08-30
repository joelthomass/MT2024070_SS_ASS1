#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>
#include <unistd.h>

int main() {
    fd_set read_fds;              
    struct timeval timeout;    

    FD_ZERO(&read_fds);           
    FD_SET(STDIN_FILENO, &read_fds); 

    timeout.tv_sec = 10;        
    timeout.tv_usec = 0;        

    printf("Waiting-STDIN for 10 seconds...\n");

    int retval = select(STDIN_FILENO + 1, &read_fds, NULL, NULL, &timeout);

    if (retval == -1) {
        perror("select");    
        return 1;
    } else if (retval == 0) {
        printf("waited for 10 seconds and no data"); 
    } else {
        if (FD_ISSET(STDIN_FILENO, &read_fds)) {
            printf("data received\n"); 
        }
    }

    return 0;
}

/*
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/13$ gcc -o 13 13.c
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/13$ ./13
Waiting-STDIN for 10 seconds...
love
data received
*/
