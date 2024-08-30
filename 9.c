#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

void print_file_info(const char *file_path) {
    struct stat file_stat;
    if (stat(file_path, &file_stat) == -1) {
        perror("Coundn't get the file status");
        exit(EXIT_FAILURE);
    }

    printf("File: %s\n", file_path);
    printf("Inode: %ld\n", (long)file_stat.st_ino);
    printf("Number of hard links: %ld\n", (long)file_stat.st_nlink);
    printf("UID: %d\n", file_stat.st_uid);
    printf("GID: %d\n", file_stat.st_gid);
    printf("Size: %ld bytes\n", (long)file_stat.st_size);
    printf("Block size: %ld bytes\n", (long)file_stat.st_blksize);
    printf("Number of blocks: %ld\n", (long)file_stat.st_blocks);
    printf("Time of last access: %s", ctime(&file_stat.st_atime));
    printf("Time of last modification: %s", ctime(&file_stat.st_mtime));
    printf("Time of last change: %s", ctime(&file_stat.st_ctime));
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    print_file_info(argv[1]);

    return 0;
}
/*
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions$ pwd
/home/joelthomas/Desktop/IIITB/SS/handsonlist1solutions
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions$ gcc -o 9 9.c
joelthomas@joelthomas-82EY:~/Desktop/IIITB/SS/handsonlist1solutions$ ./9 /home/joelthomas/Desktop/IIITB/SS/handsonlist1solutions/1a.txt
File: /home/joelthomas/Desktop/IIITB/SS/handsonlist1solutions/1a.txt
Inode: 3287152
Number of hard links: 1
UID: 1000
GID: 1000
Size: 71 bytes
Block size: 4096 bytes
Number of blocks: 8
Time of last access: Thu Aug 29 13:54:42 2024
Time of last modification: Thu Aug 29 13:54:39 2024
Time of last change: Thu Aug 29 13:54:39 2024
*/
