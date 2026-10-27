
#include <stdio.h>
#include <stdlib.h>

typedef struct nd {
    int n;
    struct nd *next;
} nodo;

typedef nodo *lista;

typedef struct it {
    lista sublist;
    struct it *next;
} item;

typedef item *LdL;



lista inserimento_in_coda(lista lis, int k);
LdL inserimento_in_codaLdL(LdL s, lista lis);
LdL rampe(lista lis);
LdL crearampe(lista lis);
void stampa_lista(lista lis);
void stampa_LdL(LdL s);
void libera_lista(lista lis);
void libera_LdL(LdL s);
lista crea_lista(void);



lista inserimento_in_coda(lista lis, int k) {
    lista punt = malloc(sizeof(nodo));
    lista cur = lis;

    if (punt == NULL) {
        return lis;
    }
    punt->n = k;
    punt->next = NULL;

    if (lis == NULL) {
        return punt;
    }

    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = punt;
    return lis;
}



LdL inserimento_in_codaLdL(LdL s, lista lis) {
    LdL punt = malloc(sizeof(item));
    LdL cur = s;

    if (punt == NULL) {
        return s;
    }
    punt->sublist = lis;
    punt->next = NULL;

    if (s == NULL) {
        return punt;
    }

    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = punt;
    return s;
}



LdL rampe(lista lis) {
    return crearampe(lis);
}



LdL crearampe(lista lis) {
    LdL testa = NULL;
    LdL ultima = NULL;
    lista corrente = lis;

    while (corrente != NULL) {
        LdL nuova = malloc(sizeof(item));

        if (nuova == NULL) {
            libera_LdL(testa);
            return NULL;
        }

        nuova->sublist = NULL;
        nuova->next = NULL;
        nuova->sublist = inserimento_in_coda(nuova->sublist, corrente->n);

        if (nuova->sublist == NULL) {
            free(nuova);
            libera_LdL(testa);
            return NULL;
        }

        if (testa == NULL) {
            testa = nuova;
        } else {
            ultima->next = nuova;
        }

        ultima = nuova;
        int precedente = corrente->n;
        corrente = corrente->next;

        while (corrente != NULL && corrente->n > precedente) {
            lista aggiornata = inserimento_in_coda(nuova->sublist, corrente->n);

            if (aggiornata == nuova->sublist) {
                lista ultimo = nuova->sublist;

                while (ultimo->next != NULL) {
                    ultimo = ultimo->next;
                }

                if (ultimo->n != corrente->n) {
                    libera_LdL(testa);
                    return NULL;
                }
            }
            nuova->sublist = aggiornata;
            precedente = corrente->n;
            corrente = corrente->next;
        }
    }
    return testa;
}



lista crea_lista(void) {
    int valori[] = {1, 3, 5, 2, 4, 7, 1};
    int n = sizeof(valori) / sizeof(valori[0]);
    lista lis = NULL;

    for (int i = n - 1; i >= 0; i--) {
        lista nuovo = malloc(sizeof(nodo));

        if (nuovo == NULL) {
            libera_lista(lis);
            return NULL;
        }
        nuovo->n = valori[i];
        nuovo->next = lis;
        lis = nuovo;
    }
    return lis;
}



void stampa_lista(lista lis) {
    while (lis != NULL) {
        printf("%d", lis->n);

        if (lis->next != NULL) {
            printf(" -> ");
        }
        lis = lis->next;
    }
    printf("\n");
}



void stampa_LdL(LdL s) {
    while (s != NULL) {
        stampa_lista(s->sublist);
        s = s->next;
    }
}



void libera_lista(lista lis) {
    while (lis != NULL) {
        lista temp = lis;
        lis = lis->next;
        free(temp);
    }
}



void libera_LdL(LdL s) {
    while (s != NULL) {
        LdL temp = s;
        s = s->next;
        libera_lista(temp->sublist);
        free(temp);
    }
}



int main(void) {
    lista lis = crea_lista();

    if (lis == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Original list:\n");
    stampa_lista(lis);
    LdL risultato = rampe(lis);

    if (risultato == NULL) {
        printf("Unable to create the increasing runs.\n");
        libera_lista(lis);
        return 1;
    }

    printf("\nIncreasing runs:\n");
    stampa_LdL(risultato);

    libera_lista(lis);
    libera_LdL(risultato);
    return 0;
}
