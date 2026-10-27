#include <stdio.h>
#include <stdlib.h>

#define V 13
#define S 4

int main(int argc, char *argv[]) {
    FILE *fp;
    int contatore[V][S] = {0};
    int valore, seme;
    int esito;
    int valido = 1;

    if (argc < 2) {
        printf("KO\n");
        return 1;
    }
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("KO\n");
        return 1;
    }

    while ((esito = fscanf(fp, " ( %d , %d )", &valore, &seme)) == 2) {
        if (valore < 1 || valore > V || seme < 1 || seme > S) {
            valido = 0;
            break;
        }
        contatore[valore - 1][seme - 1] = 1;
    }

    if (esito != EOF) {
        valido = 0;
    }
    fclose(fp);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < S; j++) {
            if (contatore[i][j] != 1) {
                valido = 0;
            }
        }
    }

    if (valido) {
        printf("OK\n");
    } else {
        printf("KO\n");
    }
    return 0;
}
