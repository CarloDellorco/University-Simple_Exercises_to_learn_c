
#include <stdio.h>
#include <stdlib.h>

int max(int k);
int trovaMax(int *vec, int dim);

int main(void) {
    int k;
    printf("Enter the value of k: ");

    if (scanf("%d", &k) != 1 || k < 1) {
        printf("Invalid input.\n");
        return 1;
    }
    printf("The maximum value is: %d\n", max(k));
    return 0;
}



int max(int k) {
    int *s = calloc(k + 1, sizeof(int));

    if (s == NULL) {
        printf("Memory allocation failed.\n");
        return -1;
    }
    s[1] = 1;

    for (int n = 1; n <= k; n++) {
        if (2 * n <= k) {
            s[2 * n] = s[n];
        }

        if (2 * n + 1 <= k) {
            s[2 * n + 1] = s[n] + s[n + 1];
        }
    }

    int risultato = trovaMax(s, k + 1);
    free(s);
    return risultato;
}



int trovaMax(int *vec, int dim) {
    int massimo = vec[0];

    for (int i = 1; i < dim; i++) {
        if (vec[i] > massimo) {
            massimo = vec[i];
        }
    }
    return massimo;
}
