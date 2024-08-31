#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *executable = "./first.out";  
    char *arg1 = "Joel";           
    char *const args[] = {executable, arg1, NULL}; 

    if (execvp(executable, args) == -1) {
        perror("Execution failed");
        return 1;
    }

    printf(" execvp is not successful.\n");

    return 0;
}
/*
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/Process_Management$ mkdir 26
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/Process_Management$ cd 26
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/Process_Management/26$ touch 26_a.c
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/Process_Management/26$ nano 26_a.c
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/Process_Management/26$ nano 26_a.c
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/Process_Management/26$ gcc -o first.out 26_a.c
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/Process_Management/26$ touch 26_b.c
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/Process_Management/26$ nano 26_b.c
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/Process_Management/26$ gcc -o 26_b 26_b.c
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/Process_Management/26$ ./26_b
Hi, Joel! This message is from first.out.
*/
