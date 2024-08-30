#include <fcntl.h>    
#include <unistd.h>   
#include <stdio.h>    
#include <string.h>   

#define BUFFER_SIZE 1024 

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;
    char line[BUFFER_SIZE];
    int lineIndex = 0; 

    while ((bytesRead = read(fd, buffer, BUFFER_SIZE)) > 0) {
        for (int i = 0; i < bytesRead; i++) {
            if (buffer[i] == '\n') {
                sleep(2);
                line[lineIndex] = '\0';  
                printf("%s\n", line);   
                lineIndex = 0;        
            } else {
                line[lineIndex++] = buffer[i];

                if (lineIndex >= BUFFER_SIZE - 1) {
                    line[lineIndex] = '\0'; 
                    printf("%s\n", line);   
                    lineIndex = 0;        
                }
            }
        }
    }

    if (bytesRead == -1) {
        perror("Error reading from file");
        close(fd);
        return 1;
    }

    if (lineIndex > 0) {
        line[lineIndex] = '\0';
        printf("%s\n", line);
    }

    close(fd);

    return 0;
}
