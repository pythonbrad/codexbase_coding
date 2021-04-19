#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORD_LENGTH 20
#define MAX_NUM_WORDS 200

int main(int argc, char const *argv[]) {
    time_t t;
    /* Intializes random number generator */
    srand((unsigned) time(&t));

    // We init the list of words
    char words[MAX_NUM_WORDS][MAX_WORD_LENGTH] = {
        "absent", "accent", "action", "adder", "address", "advocate", "agape", "alternate", "analyses", "ash", "back", "balance", "ball", "balls", "bank", "bar", "bark", "bass", "bat", "battery", "bay", "bow", "brace", "brilliant", "buck", "buffet", "building", "can", "capital", "carp", "certain", "character", "chest", "cleave", "clip", "close", "club", "combat", "combine", "commune", "console", "contact", "content", "contest", "contract", "converse", "convert", "cool", "crane", "dab", "damper", "date", "dear", "decrease", "default", "degree", "deliberate", "desert", "die", "discharge", "discount", "dismiss", "dismount", "display", "djibouti", "does", "doing", "dove", "down", "drain", "drawer", "dub", "duck", "duplicate", "effect", "engage", "entrance", "even", "evening", "excuse", "exploit", "extract", "fall", "fan", "fairly", "file", "finance", "fine", "firm", "float", "flush", "fly", "float", "foot", "football", "field", "funny", "gas", "gay", "georgia", "go", "gorge", "grave", "gyro", "harbor", "hard", "hew", "hive", "hoe", "impact", "implant", "import", "impound", "incline", "inclined", "increase", "insert", "insult", "intercept", "interchange", "intestine", "intimate", "into", "intrigue", "invalid", "invite", "jam", "just", "kind", "land", "lead", "learned", "leave", "leaves", "lebanon", "left", "letter", "lie", "light", "lighter", "lit", "live", "lose", "lumber", "luxembourg", "manifest", "mark", "mass", "match", "may", "mean", "median", "mind", "mint", "minute", "mode", "model", "moped", "mortar", "mouse", "murder", "nail", "notice", "novel", "number", "nut", "obituary", "object", "objective", "obtuse", "odd", "offense", "one", "ought", "overcount", "overlay", "overlook", "palm", "park", "patient", "perfect", "perfume", "permit", "pervert", "pitch", "pin", "plain", "plaster", "play", "polish", "pop", "portmanteau", "pound", "predate", "present", "pretty", "proceeds", "progress", "project", "protest"
    };

    char word_to_found[MAX_WORD_LENGTH];
    char indice[MAX_WORD_LENGTH] = "";
    char entry;
    int try;
    int id;
    int fail;

    // We assign a random word 
    strcpy(word_to_found, words[rand() % MAX_NUM_WORDS]);

    printf("Found the word\n");
    // The player has 75% of success
    try = strlen(word_to_found) / 0.75;

    while (try) {
        // We show the indiee
        printf("Indice (%i): ", try);
        for (id = 0; id < strlen(word_to_found); ++id) {
            printf("%c ", indice[id] != 0 ? indice[id] : '_');
        };
        
        printf("\n");
        printf("> ");
        entry = getchar();
        // This instruction permit to clean the stream when the user press enter
        getchar();

        // We verify if the entry is present in the word
        fail = 1;
        for (id = 0; id < strlen(word_to_found); ++id) {
            if (word_to_found[id] == entry) {
                indice[id] = word_to_found[id];
                fail = 0;
            };
        };
        if (fail) {
            --try;
        };

        // We verify if the word is found
        if (strcmp(indice, word_to_found) == 0) {
            break;
        };
    };
    printf("The word is %s\n", word_to_found);
    printf("You %s.\n", try ? "won" : "lost");
    // We wait a enter to exit
    getchar();
    return 0;
};