#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h> 

int main() {
    int fd;
    pid_t pid;

    fd = open("22_output.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd < 0) {
        perror("Failed to open the file");
        return 1;
    }

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        close(fd);
        return 1;
    }

    if (pid == 0) {
        const char *child_msg = "Child process writing data.\n";
        write(fd, child_msg, strlen(child_msg));  
    } else {
        const char *parent_msg = "Parent process writing data.\n";
        write(fd, parent_msg, strlen(parent_msg));  
    }

    close(fd);

    return 0;
}

