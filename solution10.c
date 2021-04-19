#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TEXT_LENGTH 2048

int main() {
    FILE *file;
    char character;
    char text[MAX_TEXT_LENGTH] = "";
    char filename[255];
    char error = 0;
    int id;

    // We ask to user to enter the file to edit
    printf("File: ");
    scanf("%s", filename);

    // We load the contains of this file and encrypt it
    file = fopen(filename, "r");
    while (1) {
        character = fgetc(file);
        if (character == -1) {
            break;
        } else if (strlen(text) < MAX_TEXT_LENGTH) {
            text[strlen(text)] = character;
        } else {
            fprintf(stderr, "Error: This file exceed the maximun text length who is %i\n", MAX_TEXT_LENGTH);
            error = 1;
            break;
        };
    };
    fclose(file);

    // We not error
    if (!error) {
        // We save the encrypted contains
        file = fopen(filename, "w");
        for (id = 0; id < strlen(text); id++) {
            fprintf(file, "%x", text[id]);
        };
        fclose(file);
    };
    return 0;
};