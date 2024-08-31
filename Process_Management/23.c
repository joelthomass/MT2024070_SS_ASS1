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
        printf("Child process (PID: %d) is exiting...\n", getpid());
        exit(0); 
    } else {
        printf("Parent process (PID: %d) is sleeping...\n", getpid());
        sleep(30);

        printf("Parent process (PID: %d) woke up.\n", getpid());
    }

    return 0;
}
/*
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/Process_Management$ ./23
Parent process (PID: 5179) is sleeping...
Child process (PID: 5180) is exiting...
Parent process (PID: 5179) woke up.

joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/Process_Management$ ps aux | grep Z
USER         PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
joeltho+    5206  0.0  0.0      0     0 pts/0    Z+   11:09   0:00 [23] <defunct>
joeltho+    5208  0.0  0.0  17736  2304 pts/1    S+   11:09   0:00 grep --color=auto Z

*/
