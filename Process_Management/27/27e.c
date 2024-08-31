#include <stdio.h>
#include <unistd.h>

int main() {
    char *args[] = {"ls", "-Rl", NULL};
  
    execvp("ls", args);
  
    perror("execvp system call failed");
    return 1;
}
/*
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/Process_Management/27$ gcc -o 27e 27e.c
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/Process_Management/27$ ./27e
.:
total 100
-rwxrwxr-x 1 joelthomas joelthomas 15992 Aug 31 12:21 27a
-rw-rw-r-- 1 joelthomas joelthomas   500 Aug 31 12:21 27a.c
-rwxrwxr-x 1 joelthomas joelthomas 15992 Aug 31 12:25 27b
-rw-rw-r-- 1 joelthomas joelthomas   615 Aug 31 12:25 27b.c
-rwxrwxr-x 1 joelthomas joelthomas 16064 Aug 31 12:32 27c
-rw-rw-r-- 1 joelthomas joelthomas   779 Aug 31 12:32 27c.c
-rwxrwxr-x 1 joelthomas joelthomas 16048 Aug 31 12:35 27d
-rw-rw-r-- 1 joelthomas joelthomas   878 Aug 31 12:36 27d.c
-rwxrwxr-x 1 joelthomas joelthomas 16048 Aug 31 12:38 27e
-rw-rw-r-- 1 joelthomas joelthomas   180 Aug 31 12:38 27e.c
*/
