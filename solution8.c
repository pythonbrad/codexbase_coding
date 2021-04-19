/*
    NB: This code is for an OS Windows
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <sys/time.h>
#define MAX_TEXT_LENGTH 2048

void delay(int x) {
    int initial_clock = clock();
    while (clock() - initial_clock < x);
};

int main() {
    FILE *file;
    char key;
    char text[MAX_TEXT_LENGTH] = "";
    char filename[255];
    char saved = 0;
    char error = 0;

    // We ask to user to enter the file to edit
    printf("File: ");
    scanf("%s", filename);

    // We load the contains of this file
    file = fopen(filename, "r");
    // We get each character
    while (1) {
        key = fgetc(file);
        if (key == -1) {
            break;
        } else if (strlen(text) < MAX_TEXT_LENGTH) {
            text[strlen(text)] = key;
        } else {
            fprintf(stderr, "Error: This file exceed the maximun text length (%i)\n", MAX_TEXT_LENGTH);
            error = 1;
        };
    };
    fclose(file);

    printf("Press any key to begin the writting\n");
    
    // We start the mainloop if not error
    while (!error) {
        // We wait a keypress
        if (kbhit()) {
            // We reset the saved
            saved = 0;
            // We get the keychar
            key = getch();
            // We analyse each key
            switch (key) {
                // If backspace
                case '\b':
                    // We remove the last character
                    text[strlen(text)-1] = '\0';
                    break;
                // If ctrl+s
                case '':
                    file = fopen(filename, "w");
                    fputs(text, file);
                    fclose(file);
                    saved = 1;
                    break;
                case '\r':
                    text[strlen(text)] = '\n';
                    break;
                // If ctrl+q
                case '':
                    exit(0);
                default:
                    if (strlen(text) < MAX_TEXT_LENGTH) {
                        text[strlen(text)] = key;
                    } else {/*Do nothing*/};
            };
            // We clean the sceen
            system("cls");
            // We print the informations
            printf("\
--------------------\n\
| Little Editor in C.|\n\
--------------------\n\
CMD:\
\tctrl+s to save\n\
\tctrl+q to quit\n\
File: %s%c\n\
Text length: %i/%i\n\n", filename, (saved ? ' ' : '*'), strlen(text), MAX_TEXT_LENGTH);
            // We show the current text
            printf("%s", text);
        };
        // We wait a short moment
        delay(100);
    };
    printf("\nBye!\n");
    delay(1000);
    return 0;
};