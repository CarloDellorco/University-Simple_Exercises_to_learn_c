#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nd {
    char *word;
    struct nd *next;
} nodo;

typedef nodo *lista;

typedef struct {
    lista a;
    lista b;
} CdL;


int cercanodiric(lista lis, char *k);
CdL split(CdL c);
lista inserimento_in_testa(lista lis, char *s);
lista inserimento_ordinato(lista lis, const char *s);
lista cancellanodo(lista lis, const char *k);
void stampa(lista lis);
void libera(lista lis);
lista crea_lista(const char *parole[], int n);



int cercanodiric(lista lis, char *k) {
    if (lis == NULL) {
        return 0;
    }
    if (strcmp(lis->word, k) == 0) {
        return 1;
    }
    return cercanodiric(lis->next, k);
}



lista inserimento_in_testa(lista lis, char *s) {
    lista punt = malloc(sizeof(nodo));

    if (punt == NULL) {
        return lis;
    }
    punt->word = malloc(strlen(s) + 1);

    if (punt->word == NULL) {
        free(punt);
        return lis;
    }

    strcpy(punt->word, s);
    punt->next = lis;
    return punt;
}



lista inserimento_ordinato(lista lis, const char *s) {
    lista punt = malloc(sizeof(nodo));

    if (punt == NULL) {
        return lis;
    }
    punt->word = malloc(strlen(s) + 1);

    if (punt->word == NULL) {
        free(punt);
        return lis;
    }

    strcpy(punt->word, s);

    if (lis == NULL || strcmp(s, lis->word) < 0) {
        punt->next = lis;
        return punt;
    }
    lista cur = lis;

    while (cur->next != NULL && strcmp(cur->next->word, s) <= 0) {
        cur = cur->next;
    }
    punt->next = cur->next;
    cur->next = punt;
    return lis;
}




lista cancellanodo(lista lis, const char *k) {
    if (lis == NULL) {
        return NULL;
    }

    if (strcmp(lis->word, k) == 0) {
        lista punt = lis->next;
        free(lis->word);
        free(lis);
        return punt;
    }
    lis->next = cancellanodo(lis->next, k);
    return lis;
}




CdL split(CdL c) {
    CdL risultato = {NULL, NULL};
    lista rimanenti = NULL;
    lista cur = c.b;

    while (cur != NULL) {
        rimanenti = inserimento_in_testa(rimanenti, cur->word);
        cur = cur->next;
    }

    cur = c.a;
    while (cur != NULL) {
        if (cercanodiric(rimanenti, cur->word)) {
            risultato.a = inserimento_ordinato(risultato.a, cur->word);
            rimanenti = cancellanodo(rimanenti, cur->word);
        } else {
            risultato.b = inserimento_ordinato(risultato.b, cur->word);
        }
        cur = cur->next;
    }

    cur = rimanenti;
    while (cur != NULL) {
        risultato.b = inserimento_ordinato(risultato.b, cur->word);
        cur = cur->next;
    }

    libera(rimanenti);
    return risultato;
}




lista crea_lista(const char *parole[], int n) {
    lista lis = NULL;
    for (int i = n - 1; i >= 0; i--) {
        lista nuovo = malloc(sizeof(nodo));

        if (nuovo == NULL) {
            libera(lis);
            return NULL;
        }
        nuovo->word = malloc(strlen(parole[i]) + 1);

        if (nuovo->word == NULL) {
            free(nuovo);
            libera(lis);
            return NULL;
        }
        strcpy(nuovo->word, parole[i]);
        nuovo->next = lis;
        lis = nuovo;
    }
    return lis;
}




void stampa(lista lis) {
    while (lis != NULL) {
        printf("%s", lis->word);

        if (lis->next != NULL) {
            printf(" -> ");
        }
        lis = lis->next;
    }
    printf("\n");
}



void libera(lista lis) {
    while (lis != NULL) {
        lista temp = lis;
        lis = lis->next;
        free(temp->word);
        free(temp);
    }
}



int main(void) {
    const char *parole_a[] = {"apple", "banana", "cherry", "orange"};
    const char *parole_b[] = {"banana", "grape", "orange", "pear"};

    CdL c;
    CdL risultato;

    c.a = crea_lista(parole_a, 4);
    c.b = crea_lista(parole_b, 4);

    if (c.a == NULL || c.b == NULL) {
        libera(c.a);
        libera(c.b);
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("First list:\n");
    stampa(c.a);

    printf("Second list:\n");
    stampa(c.b);

    risultato = split(c);

    printf("Common words:\n");
    stampa(risultato.a);

    printf("Words present in only one list:\n");
    stampa(risultato.b);

    libera(c.a);
    libera(c.b);
    libera(risultato.a);
    libera(risultato.b);

    return 0;
}

