#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Syntax: ./first.out <name>\n");
        return 1;
    }

    printf("Hi, %s! This message is from first.out.\n", argv[1]);
    return 0;
}
