#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define RECORD_SIZE 50

int main() {
    int fd;
    const char *filename = "18_records.txt";
    char *records[] = {
        "Record 1: Initial data\n",
        "Record 2: Initial data\n",
        "Record 3: Initial data\n"
    };

    fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0666);
    if (fd < 0) {
        perror("Failed to open or create the file");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < 3; i++) {
        if (write(fd, records[i], RECORD_SIZE) < 0) {
            perror("Failed to write to the file");
            close(fd);
            return EXIT_FAILURE;
        }
    }

    printf("Three records have been written to %s\n", filename);

    close(fd);

    return EXIT_SUCCESS;
}
