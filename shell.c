#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int line_length = 1024;
    char command_line[line_length];

    while (1) {
        printf("custom_shell> ");
        fgets(command_line, line_length, stdin);

        if (!(strcmp(command_line, "exit\n")) || !(strcmp(command_line, "quit\n"))) {
            printf("exiting custom shell...\n");
            break;
        }

        printf("Line entered: %s", command_line);
    }

    return 0;
}