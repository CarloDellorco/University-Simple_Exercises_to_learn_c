#include <stdio.h>
#include <stdlib.h>

#define K 4


int contadiversi(int *v, int d);


int main(void) {
    int numero = 1;
    int i = 0;
    int numero_diversi;
    int *finestra = calloc(K, sizeof(int));

    if (finestra == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    while (i < K && numero != 0) {
        if (scanf("%d", &numero) != 1) {
            free(finestra);
            return 1;
        }

        if (numero != 0) {
            finestra[i++] = numero;
        }
    }

    if (numero == 0) {
        printf("The sequence ended correctly.\n");
        free(finestra);
        return 0;
    }

    numero_diversi = contadiversi(finestra, K);

    while (numero != 0 && numero_diversi > 1 && numero_diversi < K) {
        if (scanf("%d", &numero) != 1) {
            free(finestra);
            return 1;
        }

        if (numero != 0) {
            if (i == K) {
                i = 0;
            }

            finestra[i++] = numero;
            numero_diversi = contadiversi(finestra, K);
        }
    }

    if (numero == 0) {
        printf("The sequence ended correctly.\n");
    } else if (numero_diversi == K) {
        printf("%d consecutive values are all different.\n", K);
    } else {
        printf("%d consecutive values are all equal.\n", K);
    }

    free(finestra);
    return 0;
}



int contadiversi(int *v, int d) {
    int i, j;
    int counter = 0;
    int *copy = malloc(d * sizeof(int));

    if (copy == NULL) {
        return -1;
    }

    for (i = 0; i < d; i++) {
        copy[i] = v[i];
    }

    for (i = 0; i < d; i++) {
        if (copy[i] != 0) {
            counter++;

            for (j = i + 1; j < d; j++) {
                if (copy[i] == copy[j]) {
                    copy[j] = 0;
                }
            }
        }
    }

    free(copy);
    return counter;
}
