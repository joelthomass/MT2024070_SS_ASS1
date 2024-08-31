#include <stdio.h>
#include <unistd.h>

int main() {
    char *args[] = {"ls", "-Rl", NULL};
    
    execv("/bin/ls", args);

    perror("execv system call failed");
    return 1;
}
/*
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/Process_Management/27$ gcc -o 27d 27d.c
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/Process_Management/27$ ./27d
.:
total 80
-rwxrwxr-x 1 joelthomas joelthomas 15992 Aug 31 12:21 27a
-rw-rw-r-- 1 joelthomas joelthomas   500 Aug 31 12:21 27a.c
-rwxrwxr-x 1 joelthomas joelthomas 15992 Aug 31 12:25 27b
-rw-rw-r-- 1 joelthomas joelthomas   615 Aug 31 12:25 27b.c
-rwxrwxr-x 1 joelthomas joelthomas 16064 Aug 31 12:32 27c
-rw-rw-r-- 1 joelthomas joelthomas   779 Aug 31 12:32 27c.c
-rwxrwxr-x 1 joelthomas joelthomas 16048 Aug 31 12:35 27d
-rw-rw-r-- 1 joelthomas joelthomas   183 Aug 31 12:34 27d.c
*/
