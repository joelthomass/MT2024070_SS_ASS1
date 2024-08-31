#include <stdio.h>
#include <unistd.h>

int main() {
    extern char **environ;
    execle("/bin/ls", "ls", "-Rl", (char *)NULL, environ);
    
    perror("execle system call  failed");
    return 1;
}
/*
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/Process_Management/27$ gcc -o 27c 27c.c
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/Process_Management/27$ ./27c
.:
total 60
-rwxrwxr-x 1 joelthomas joelthomas 15992 Aug 31 12:21 27a
-rw-rw-r-- 1 joelthomas joelthomas   500 Aug 31 12:21 27a.c
-rwxrwxr-x 1 joelthomas joelthomas 15992 Aug 31 12:25 27b
-rw-rw-r-- 1 joelthomas joelthomas   615 Aug 31 12:25 27b.c
-rwxrwxr-x 1 joelthomas joelthomas 16064 Aug 31 12:32 27c
-rw-rw-r-- 1 joelthomas joelthomas   202 Aug 31 12:31 27c.c
*/
