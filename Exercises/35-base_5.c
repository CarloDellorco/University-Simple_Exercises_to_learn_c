
#include <stdio.h>
#include <string.h>

#define NUM 10
#define CIFRE_FILE "C:/Users/carlo/CLionProjects/Simple_c_exercises/Files/cifre.txt"

// Prototipi
void inverti(int *, int);
int converti(char *);

int main(void) {
    FILE *fp;
    char cifre[NUM];
    int num[NUM];
    int i = 0, j;
    int somma = 0, avg_count = 0;
    int valore, numero;
    float media;

    fp = fopen(CIFRE_FILE, "r");

    if (fp == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    while (fscanf(fp, "%9s", cifre) == 1) {
        if (strcmp(cifre, "***") == 0) {
            if (i > 0) {
                inverti(num, i);

                numero = 0;
                valore = 1;

                for (j = 0; j < i; j++) {
                    numero += num[j] * valore;
                    valore *= 5;
                }

                printf("converted number: %d\n", numero);
                somma += numero;
                avg_count++;
                i = 0;
            }
        }
        else {
            valore = converti(cifre);

            if (valore == -1) {
                printf("unknown figure: %s\n", cifre);
                fclose(fp);
                return 1;
            }

            if (i >= NUM) {
                printf("Error: too many figures.\n");
                fclose(fp);
                return 1;
            }

            num[i] = valore;
            i++;
        }
    }

    /* Gestisce anche un ultimo numero senza *** finale */
    if (i > 0) {
        inverti(num, i);

        numero = 0;
        valore = 1;

        for (j = 0; j < i; j++) {
            numero += num[j] * valore;
            valore *= 5;
        }

        printf("converted number: %d\n", numero);
        somma += numero;
        avg_count++;
    }

    fclose(fp);

    if (avg_count == 0) {
        printf("No number found in file.\n");
        return 1;
    }

    media = (float)somma / avg_count;

    printf("sum of the numbers is decimal is: %d\n", somma);
    printf("average of the numbers is decimal is: %.2f\n", media);
    return 0;
}




int converti(char *cifra) {
    if (strcmp(cifra, "uno") == 0) {
        return 1;
    }
    else if (strcmp(cifra, "due") == 0) {
        return 2;
    }
    else if (strcmp(cifra, "tre") == 0) {
        return 3;
    }
    else if (strcmp(cifra, "quattro") == 0) {
        return 4;
    }
    else if (strcmp(cifra, "cinque") == 0) {
        return 5;
    }
    return -1;
}



void inverti(int *n, int len) {
    int i, temp;

    for (i = 0; i < len / 2; i++) {
        temp = n[i];
        n[i] = n[len - 1 - i];
        n[len - 1 - i] = temp;
    }
}
