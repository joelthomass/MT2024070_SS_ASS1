#include <stdio.h>
#include <sched.h>
#include <stdlib.h>

int main() {
    int mxpriority, mnpriority;

    mxpriority = sched_get_priority_max(SCHED_FIFO);
    if (mxpriority == -1) {
        perror("Failed to get priority");
        exit(1);
    }

    mnpriority = sched_get_priority_min(SCHED_FIFO);
    if (mnpriority == -1) {
        perror("Failed to get priority");
        exit(1);
    }

    printf("Max. priority: %d\n", mxpriority);
    printf("Min. priority: %d\n", mnpriority);

    return 0;
}
/*
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/Process_Management$ touch 28.c
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/Process_Management$ nano 28.c
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/Process_Management$ gcc -o 28 28.c
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/Process_Management$ ./28
Max. priority: 99
Min. priority: 1
*/
