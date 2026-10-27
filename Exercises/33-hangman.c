
#include <stdio.h>
#include <string.h>

#define DIM 50


typedef enum {
    nascosto,
    nondisponibile,
    trovato
} stato;



typedef struct {
    char lettera;
    stato situazione;
} posizione;



int main(void) {
    char lettera, parola[DIM + 1];
    int i, len, tent = 6;
    posizione indovina[DIM];
    int fine = 0, iter = 0;

    printf("Insert the word to guess (max 50 characters):\n");

    if (scanf("%50s", parola) != 1) {
        return 1;
    }
    len = strlen(parola);

    for (i = 0; i < DIM; i++) {
        if (i < len) {
            indovina[i].situazione = nascosto;
            indovina[i].lettera = parola[i];
        }
        else {
            indovina[i].situazione = nondisponibile;
            indovina[i].lettera = '\0';
        }
    }
    while (!fine && iter < tent) {
        printf("\nWord: ");

        for (i = 0; i < len; i++) {
            if (indovina[i].situazione == trovato) {
                printf("%c", indovina[i].lettera);
            }
            else {
                printf("_");
            }
        }
        printf("\nTries remaining: ");

        for (i = iter; i < tent; i++) {
            printf("*");
        }

        printf("\nINSERT A LETTER:\n");

        if (scanf(" %c", &lettera) != 1) {
            break;
        }
        int corretta = 0;

        for (i = 0; i < len; i++) {
            if (lettera == indovina[i].lettera &&
                indovina[i].situazione == nascosto) {
                indovina[i].situazione = trovato;
                corretta = 1;
            }
        }

        if (!corretta) {
            iter++;
            printf("Wrong letter!\n");
        }
        fine = 1;

        for (i = 0; i < len; i++) {
            if (indovina[i].situazione == nascosto) {
                fine = 0;
                break;
            }
        }
    }

    if (fine) {
        printf("You win!!\n");
    }
    else {
        printf("You lose :(\n");
    }
    printf("The word was %s\n", parola);
    return 0;
}
