#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[]) {
    time_t t;
    /* Intializes random number generator */
    srand((unsigned) time(&t));

    int num_to_found = rand() % 10;
    int entry, try;

    printf("Found the number\n");

    for (try = 5; try > 0; --try){
        printf("> ");
        scanf("%i", &entry);
        if (entry < num_to_found) {
            printf("It's hot.\n");
        } else if (entry > num_to_found) {
            printf("It's cold.\n");
        } else {
            break;
        }
    };
    printf(try ? "You won\n." : "You lost\n.");
    // We wait an enter to exit
    getchar();
    return 0;
};