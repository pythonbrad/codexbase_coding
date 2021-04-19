#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TEXT_LENGTH 2048
#define PAS 4

char encrypt(char character, char pas) {
    char data[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int id;
    // If the character is know, we return the corresponding encrypted character
    for (id = 0; id < strlen(data); ++id) {
        if (character == data[id]) {
            return data[(id + pas) % strlen(data)];
        };
    };
    // else we return the same character
    return character;
};

int main() {
    FILE *file;
    char character;
    char text[MAX_TEXT_LENGTH] = "";
    char filename[255];
    char error = 0;

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
            text[strlen(text)] = encrypt(character, PAS);
        } else {
            fprintf(stderr, "Error: This file exceed the maximun text length (%i)\n", MAX_TEXT_LENGTH);
            error = 1;
            break;
        };
    };
    fclose(file);

    // If not error
    if (!error) {
        // We save the encrypted contains
        file = fopen(filename, "w");
        fputs(text, file);
        fclose(file);
    };
    return 0;
};