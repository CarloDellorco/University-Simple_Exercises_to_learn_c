
#include <stdio.h>
#include <stdlib.h>

typedef struct nd {
    int n1, n2;
    struct nd *next;
} nodo;

typedef nodo *lista;


lista inserimento_in_testa(lista lis, int i, int j);
lista scomponi(int n);
void stampa(lista lis);
void dealloca(lista lis);


int main(void) {
    int n;
    lista lis;

    printf("Enter an integer greater than 2: ");

    if (scanf("%d", &n) != 1 || n <= 2) {
        printf("Invalid input.\n");
        return 1;
    }

    lis = scomponi(n);

    if (lis == NULL) {
        printf("No decompositions found.\n");
    } else {
        printf("Decompositions of %d:\n", n);
        stampa(lis);
    }

    dealloca(lis);
    return 0;
}



lista scomponi(int n) {
    lista lis = NULL;
    int i, j;

    for (i = 1; i < n; i++) {
        for (j = n - 1; j > i; j--) {
            if (i + j == n) {
                lis = inserimento_in_testa(lis, i, j);
            }
        }
    }
    return lis;
}



lista inserimento_in_testa(lista lis, int i, int j) {
    lista punt = malloc(sizeof(nodo));

    if (punt == NULL) {
        return lis;
    }

    punt->n1 = i;
    punt->n2 = j;
    punt->next = lis;
    return punt;
}



void stampa(lista lis) {
    while (lis != NULL) {
        printf("%d + %d = %d\n", lis->n1, lis->n2, lis->n1 + lis->n2);
        lis = lis->next;
    }
}



void dealloca(lista lis) {
    while (lis != NULL) {
        lista temp = lis;
        lis = lis->next;
        free(temp);
    }
}

