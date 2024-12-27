#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    int line_length = 1024;
    char command_line[line_length];
    command_line[strcspn(command_line, "\n")] = '\0';
    char path[] = "custom_shell";

    while (1) {
        printf("%s> ", path);
        fgets(command_line, line_length, stdin);

        if (!(strcmp(command_line, "exit\n")) || !(strcmp(command_line, "quit\n"))) {
            printf("exiting custom shell...\n");
            break;
        }

        // cd
        if (!(strcmp(command_line, "cd\n"))) {
            printf("resetting path...\n");
            strcpy(path, "custom_shell");
        }
        else if (strstr(command_line, "cd ") != NULL) {
            printf("changing directory...\n");
            char path_sub[line_length];
            strncpy(path_sub, command_line + 3, strlen(command_line));

            strcat(path, "/");
            strcat(path, path_sub);

            // if (chdir((char *)path) != 0) {
            //     perror("cd");
            // }
        }

        printf("Line entered: %s", command_line);
    }

    return 0;
}