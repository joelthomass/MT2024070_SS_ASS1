#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid;
    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }

    if (pid == 0) {
        sleep(1);  
        printf("Child process (PID: %d) initial Parent PID: %d\n", getpid(), getppid());

        sleep(10); 
        printf("Child process (PID: %d) after reparenting, Parent PID: %d\n", getpid(), getppid());
    } else {
        printf("Parent process (PID: %d) is terminating.\n", getpid());
        exit(0);  
    }

    return 0;
}
/*
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/Process_Management$ nano 24.c
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/Process_Management$ gcc -o 24 24.c
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/Process_Management$ ./24
Parent process (PID: 5490) is terminating.
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/Process_Management$ Child process (PID: 5491) initial Parent PID: 1617
Child process (PID: 5491) after reparenting, Parent PID: 1617
*/
