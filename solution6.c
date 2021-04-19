/*
    NB: This code is for an OS Windows
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main() {
    int i;
    char key;
    // We start the loop
    while (1) {
        // We wait a keypress
        if (kbhit()) {
            // We get the keypress
            key = getch();
            printf("You have pressed %x -> \\%i -> %c\n", key, key, key);
        };
    };
    return 0;
};