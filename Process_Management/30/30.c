
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>

int main()
{
    pid_t pid = 0;
    pid_t sid = 0;
    int fd = open("30_output.txt",O_WRONLY);
    pid = fork();
    if(pid < 0)
    {
        perror("Failed to create child process : ");
        exit(1);
    }
    
    if(pid > 0)
    {
        printf("The process id of the parent is %d \n",pid);
        exit(0);
    }
    
    sleep(5);
    
    umask(0);
    
    sid = setsid();
    
    if(sid < 0)
    {
        exit(0);
    }
    
    chdir("/home/kanishka/abc/30");
    close(0);
    close(1);
    close(2);
    
    while(1)
    {
        sleep(2);
        write(fd,"this is deamon\n",15);
    }
    
    
    return 0;
    
}
/*
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/Process_Management/30$ touch 30.c
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/Process_Management/30$ nano 30.c
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/Process_Management/30$ gcc -o 30 30.c
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/Process_Management/30$ ./30
The process id of the parent is 8227 
*/
