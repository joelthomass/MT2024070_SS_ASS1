#include <stdio.h>
#include <unistd.h>

int main() {
    execl("/bin/ls", "ls", "-Rl", (char *) NULL);
    perror("execl system call failed");
    return 1;
}
/*
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/Process_Management/27$ gcc -o 27a 27a.c
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/Process_Management/27$ ./27a
.:
total 20
-rwxrwxr-x 1 joelthomas joelthomas 15992 Aug 31 12:21 27a
-rw-rw-r-- 1 joelthomas joelthomas   159 Aug 31 12:21 27a.c
*/
