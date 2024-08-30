#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

void print_file_type(const char *path) {
    struct stat file_stat;

    if (stat(path, &file_stat) == -1) {
        perror("stat"); 
        return;
    }

    if (S_ISREG(file_stat.st_mode)) {
        printf(" '%s'-regular file.\n", path);
    } else if (S_ISDIR(file_stat.st_mode)) {
        printf(" '%s'-directory.\n", path);
    } else if (S_ISLNK(file_stat.st_mode)) {
        printf(" '%s'-symbolic link.\n", path);
    } else if (S_ISSOCK(file_stat.st_mode)) {
        printf(" '%s'-socket.\n", path);
    } else if (S_ISBLK(file_stat.st_mode)) {
        printf(" '%s'-block device.\n", path);
    } else if (S_ISCHR(file_stat.st_mode)) {
        printf(" '%s'-character device.\n", path);
    } else if (S_ISFIFO(file_stat.st_mode)) {
        printf(" '%s'-FIFO\n", path);
    } else {
        printf(" '%s'-unknown type.\n", path);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    print_file_type(argv[1]);

    return 0;
}
/*
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/14$ gcc -o 14 14.c
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/14$ ./14 /home/joelthomas/Desktop/IIITB/SS/pipe
stat: No such file or directory
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions/14$ ./14 /home/joelthomas/Desktop/IIITB/SS/handsonlist1solutions/pipe
 '/home/joelthomas/Desktop/IIITB/SS/handsonlist1solutions/pipe'-FIFO
*/
