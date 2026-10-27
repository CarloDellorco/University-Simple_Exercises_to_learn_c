
#include <stdio.h>
#include <stdlib.h>

// Prototipo
int anomalie(int *, int);

int main(int argc, char *argv[]) {
    int k, n;
    int i, count = 0;
    int *seq, *finale = NULL;
    int nFinale = 0;

    if (argc < 2) {
        printf("Error: specify an argument for the code.\n");
        return 1;
    }

    k = atoi(argv[1]);

    if (k < 1) {
        printf("Error: k must be positive.\n");
        return 1;
    }

    seq = malloc(k * sizeof(int));

    if (seq == NULL) {
        printf("Error in memory allocation.\n");
        return 1;
    }

    printf("Insert a sequence of numbers (end by typing 0):\n");

    while (scanf("%d", &n) == 1 && n != 0) {
        seq[count] = n;
        count++;

        if (count == k) {
            if (anomalie(seq, k)) {
                printf("You inserted an anomaly sequence\n");
            }
            else {
                int *temp = realloc(finale,
                                    (nFinale + k) * sizeof(int));

                if (temp == NULL) {
                    printf("Error in memory allocation.\n");
                    free(seq);
                    free(finale);
                    return 1;
                }

                finale = temp;

                for (i = 0; i < k; i++) {
                    finale[nFinale] = seq[i];
                    nFinale++;
                }
            }

            count = 0;
        }
    }

    if (count > 0) {
        printf("Incomplete sequence: last %d numbers are ignored.\n", count);
    }

    printf("regular sequences are:\n");

    for (i = 0; i < nFinale; i++) {
        printf("%3d", finale[i]);
    }

    printf("\n");

    free(seq);
    free(finale);

    return 0;
}

int anomalie(int *vec, int dim) {
    int i, j;
    int tuttiUguali = 1;
    int tuttiDiversi = 1;

    for (i = 0; i < dim; i++) {
        for (j = i + 1; j < dim; j++) {
            if (vec[i] != vec[j]) {
                tuttiUguali = 0;
            }

            if (vec[i] == vec[j]) {
                tuttiDiversi = 0;
            }
        }
    }

    if (tuttiUguali) {
        printf("All sequence values are the same.\n");
        return 1;
    }

    if (tuttiDiversi) {
        printf("all sequence values are different.\n");
        return 1;
    }

    return 0;
}
