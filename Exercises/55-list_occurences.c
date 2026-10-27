#include <stdio.h>
#include <stdlib.h>

#define N 10


typedef struct nd {
    int n;
    struct nd *next;
} nodo;


typedef nodo *lista;


int fCons(lista lis, int num);
int fNonCons(lista lis, int num);
int quantiAlmenoTriplici(lista lis);
int almenoTre(lista lis, int num);
lista inserisciInCoda(lista lis, int valore);
void stampaLista(lista lis);
void liberaLista(lista lis);



int fCons(lista lis, int num) {
    while (lis != NULL && lis->next != NULL) {
        if (lis->n == num && lis->next->n == num) {
            return 1;
        }
        lis = lis->next;
    }
    return 0;
}



int fNonCons(lista lis, int num) {
    if (lis == NULL || lis->next == NULL) {
        return 0;
    }
    if (lis->n == num) {
        lista cur = lis->next->next;

        while (cur != NULL) {
            if (cur->n == num) {
                return 1;
            }
            cur = cur->next;
        }
    }
    return fNonCons(lis->next, num);
}




int almenoTre(lista lis, int num) {
    if (lis == NULL) {
        return 0;
    }
    int conto = 0;

    while (lis != NULL) {
        if (lis->n == num) {
            conto++;
            if (conto == 3) {
                return 1;
            }
        }
        lis = lis->next;
    }
    return 0;
}




int quantiAlmenoTriplici(lista lis) {
    int n = 0;
    for (int i = 1; i < N; i++) {
        n += almenoTre(lis, i);
    }
    return n;
}




lista inserisciInCoda(lista lis, int valore) {
    lista nuovo = malloc(sizeof(nodo));

    if (nuovo == NULL) {
        return lis;
    }
    nuovo->n = valore;
    nuovo->next = NULL;

    if (lis == NULL) {
        return nuovo;
    }

    lista cur = lis;
    while (cur->next != NULL) {
        cur = cur->next;
    }

    cur->next = nuovo;
    return lis;
}




void stampaLista(lista lis) {
    while (lis != NULL) {
        printf("%d", lis->n);

        if (lis->next != NULL) {
            printf(" -> ");
        }
        lis = lis->next;
    }
    printf("\n");
}




void liberaLista(lista lis) {
    while (lis != NULL) {
        lista temp = lis;
        lis = lis->next;
        free(temp);
    }
}




int main(void) {
    int valori[] = {2, 2, 5, 2, 3, 3, 3, 7, 7, 7, 7, 9};
    int dimensione = sizeof(valori) / sizeof(valori[0]);
    lista lis = NULL;

    for (int i = 0; i < dimensione; i++) {
        lista nuova = inserisciInCoda(lis, valori[i]);

        if (lis == NULL || nuova != lis) {
            lis = nuova;
        }
    }

    printf("List:\n");
    stampaLista(lis);

    printf("Two consecutive occurrences of 2: %s\n",
           fCons(lis, 2) ? "Yes" : "No");

    printf("Two non-consecutive occurrences of 5: %s\n",
           fNonCons(lis, 5) ? "Yes" : "No");

    printf("Number of values occurring at least three times: %d\n",
           quantiAlmenoTriplici(lis));

    liberaLista(lis);
    return 0;
}
