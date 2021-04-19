#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
    char text[255];
    int id, frame;

    // We get the text
    printf("Enter a text: ");
    fgets(text, sizeof(text), stdin);

    // We show the text
    for (id = 0; id < strlen(text); id++) {
        // We wait a moment
        for (frame = 0; frame < 100000000; ++frame) {};
        printf("%c", text[id]);
    };
    return 0;
};