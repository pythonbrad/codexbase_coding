#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *file;
    char character;
    char filename[255];
    int num_lines, num_chars;

    num_chars = 0;
    // Because the first line
    num_lines = 1;

    // We ask to user to enter the file to edit
    printf("File: ");
    scanf("%s", filename);

    // We load the contains of this file and encrypt it
    file = fopen(filename, "r");
    while (1) {
        character = fgetc(file);
        if (character == -1) {
            break;
        };
        if (character == '\n') {
            num_lines++;
        };
        num_chars++;
    };
    fclose(file);
    
    // We show the result
    printf("The file contains %i lines and %i characters\n", num_lines, num_chars);
    return 0;
};