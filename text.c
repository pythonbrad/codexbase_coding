#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[]) {
    time_t t;
    /* Intializes random number generator */
    srand((unsigned) time(&t));
    // We show a random number
    printf("The random number genrated is: %d\n", rand() % 10);
    // We wait an enter to exit
    scanf("%*c");
    return 0;
};