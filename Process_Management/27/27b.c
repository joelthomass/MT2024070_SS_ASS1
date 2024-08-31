#include <stdio.h>
#include <unistd.h>

int main() {
    execlp("ls", "ls", "-Rl", (char *)NULL);
    perror("execlp system call  failed");
    return 1;
}
/*
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/Process_Management/27$ gcc -o 27b 27b.c
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/Process_Management/27$ ./27b
.:
total 40
-rwxrwxr-x 1 joelthomas joelthomas 15992 Aug 31 12:21 27a
-rw-rw-r-- 1 joelthomas joelthomas   500 Aug 31 12:21 27a.c
-rwxrwxr-x 1 joelthomas joelthomas 15992 Aug 31 12:25 27b
-rw-rw-r-- 1 joelthomas joelthomas   156 Aug 31 12:24 27b.c
*/
