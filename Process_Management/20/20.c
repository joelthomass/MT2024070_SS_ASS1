#include <stdio.h>
#include <unistd.h>

int main() {
    printf("PID of this process: %d\n", getpid());
    while (1) {
    }
    return 0;
}
/*
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/Process_Management/20$ gcc -o 20 20.c
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/Process_Management/20$ ./20
PID of this process: 11647
*/
/*
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/Process_Management/20$ ps -o pid,ni,comm -p 11647
    PID  NI COMMAND
  11647   0 20
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/Process_Management/20$ renice -n 5 -p 11647
11647 (process ID) old priority 0, new priority 5
*/
