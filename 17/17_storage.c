// create_ticket_file.c
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int file_descriptor;
    const char *file_path = "ticket_storing_file.txt";
    const char *start_ticket_number = "100"; 

    file_descriptor = open(file_path, O_RDWR | O_CREAT | O_TRUNC, 0666);
    if (file_descriptor < 0) {
        perror("Failed to open or create the file");
        return EXIT_FAILURE;
    }

    ssize_t result = write(file_descriptor, start_ticket_number, strlen(start_ticket_number));
    if (result < 0) {
        perror("Failed to write to the file");
        close(file_descriptor);
        return EXIT_FAILURE;
    }

    printf("Ticket number %s has been written to %s\n", start_ticket_number, file_path);

    if (close(file_descriptor) < 0) {
        perror("Failed to close the file");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
