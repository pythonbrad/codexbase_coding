#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(int argc, char const *argv[]) {
    time_t t;
    /* Intializes random number generator */
    srand((unsigned) time(&t));

    // We init datas
    char ascii_lower_case[26] = "abcdefghijklmnopqrstuvwxyz";
    char ascii_upper_case[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char digits[10] = "0123456789";
    char special_char[36] = "!\"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~ ";

    char password[256] = "";

    // We init params
    int num_alc, num_auc, num_d, num_sc;
    printf("Password Generator\n");
    printf("Enter the number of lower letters: ");
    scanf("%i", &num_alc);
    printf("Enter the number of upper letters: ");
    scanf("%i", &num_auc);
    printf("Enter the number of digits: ");
    scanf("%i", &num_d);
    printf("Enter the number of special characters: ");
    scanf("%i", &num_sc);
    
    // We verify if the password can be generate
    if (num_alc + num_auc + num_d + num_sc > sizeof(password)) {
        printf("Error: The max length should be %li\n", sizeof(password));
        return -1;
    };

    // We generate the password
    while (num_alc + num_auc + num_d + num_sc > 0) {
        switch (rand() % 4) {
            case 0:
                if(num_alc > 0) {
                    password[strlen(password)] = ascii_lower_case[rand() % strlen(ascii_lower_case)];
                    num_alc--;
                };
                break;
            case 1:
                if(num_auc > 0) {
                    password[strlen(password)] = ascii_upper_case[rand() % strlen(ascii_upper_case)];
                    num_auc--;
                };
                break;
            case 2:
                if(num_d > 0) {
                    password[strlen(password)] = digits[rand() % strlen(digits)];
                    num_d--;
                };
                break;
            case 3:
                if(num_sc > 0) {
                    password[strlen(password)] = special_char[rand() % strlen(special_char)];
                    num_sc--;
                };
                break;
            default:
                break;
        };
    };
    printf("Password: %s\n", password);
    // We wait an enter to exit
    getchar();
    return 0;
};