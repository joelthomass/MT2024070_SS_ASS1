#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd, fd_dup, fd_dup2, fd_fcntl;
    ssize_t bytes_written;

    fd = open("11.txt", O_RDWR | O_CREAT | O_APPEND, 0644);
    if (fd == -1) {
        perror("Couldn't open the file");
        return 1;
    }

    fd_dup = dup(fd);
    if (fd_dup == -1) {
        perror("Error-dup");
        close(fd);
        return 1;
    }

    fd_dup2 = dup2(fd, 100);  
    if (fd_dup2 == -1) {
        perror("Error-dup2");
        close(fd);
        close(fd_dup);
        return 1;
    }

    fd_fcntl = fcntl(fd, F_DUPFD, 200);  
    if (fd_fcntl == -1) {
        perror("Error-fcntl");
        close(fd);
        close(fd_dup);
        close(fd_dup2);
        return 1;
    }

    bytes_written = write(fd, "Original FD\n", 12);
    if (bytes_written != 12) {
        perror("Error writing-fd");
    }

    bytes_written = write(fd_dup, "Dup FD\n", 7);
    if (bytes_written != 7) {
        perror("Error writing-dup fd");
    }

    bytes_written = write(fd_dup2, "Dup2 FD\n", 8);
    if (bytes_written != 8) {
        perror("Error writing-dup2 fd");
    }

    bytes_written = write(fd_fcntl, "Fcntl FD\n", 9);
    if (bytes_written != 9) {
        perror("Error writing-fcntl fd");
    }

    close(fd);
    close(fd_dup);
    close(fd_dup2);
    close(fd_fcntl);

    return 0;
}
