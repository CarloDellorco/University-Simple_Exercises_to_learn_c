
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_D 100
#define SIZE_V 10

typedef struct t_el {
    struct {
        int day;
        int month;
        int year;
    } data;
    float temperature;
    char description[SIZE_D];
    int vettore[SIZE_V];
} Tipo;

typedef struct elem {
    Tipo dato;
    struct elem *next;
} Nodo;

Nodo *InsCoda(Nodo *lista, Tipo t);
Nodo *loadlist(FILE *fp);
void savelist(Nodo *lista, FILE *fp);
void dealloca(Nodo *p);
void stampa(Tipo d, FILE *fp);
int leggi(FILE *fp, Tipo *d);

int main(void) {
    FILE *fp;
    Nodo *lista = NULL;

    fp = fopen("C:/Users/carlo/CLionProjects/Simple_c_exercises/Files/lista_su_file_input.txt", "r");

    if (fp == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    printf("Loading data from file...\n");
    lista = loadlist(fp);
    fclose(fp);
    printf("Data loaded.\n");
    fp = fopen("C:/Users/carlo/CLionProjects/Simple_c_exercises/Files/lista_su_file_output.txt", "w");

    if (fp == NULL) {
        printf("Error opening output file.\n");
        dealloca(lista);
        return 2;
    }

    savelist(lista, fp);
    fclose(fp);
    dealloca(lista);
    printf("Data saved successfully.\n");
    printf("Goodbye!\n");
    return 0;
}




Nodo *InsCoda(Nodo *lista, Tipo t) {
    if (lista == NULL) {
        Nodo *p = malloc(sizeof(Nodo));

        if (p == NULL) {
            return NULL;
        }

        p->dato = t;
        p->next = NULL;

        return p;
    }

    Nodo *nuovo = InsCoda(lista->next, t);

    if (lista->next == NULL && nuovo == NULL) {
        return lista;
    }
    lista->next = nuovo;
    return lista;
}



Nodo *loadlist(FILE *fp) {
    Nodo *lista = NULL;
    Tipo t;

    while (leggi(fp, &t)) {
        Nodo *nuova = InsCoda(lista, t);

        if (nuova == NULL) {
            dealloca(lista);
            return NULL;
        }

        lista = nuova;
    }

    return lista;
}



void savelist(Nodo *lista, FILE *fp) {
    if (lista == NULL) {
        printf("The list is empty. No data to save.\n");
        return;
    }

    while (lista != NULL) {
        stampa(lista->dato, fp);
        lista = lista->next;
    }
}




int leggi(FILE *fp, Tipo *d) {
    int ch;

    if (fscanf(fp, "%d %d %d",
               &d->data.day,
               &d->data.month,
               &d->data.year) != 3) {
        return 0;
    }

    if (fscanf(fp, "%f", &d->temperature) != 1) {
        return 0;
    }

    while ((ch = fgetc(fp)) != '\n' && ch != EOF) {
    }

    if (fgets(d->description, SIZE_D, fp) == NULL) {
        return 0;
    }
    d->description[strcspn(d->description, "\r\n")] = '\0';

    for (int i = 0; i < SIZE_V; i++) {
        if (fscanf(fp, "%d", &d->vettore[i]) != 1) {
            return 0;
        }
    }
    return 1;
}



void stampa(Tipo d, FILE *fp) {
    fprintf(fp, "%d %d %d\n", d.data.day, d.data.month, d.data.year);

    fprintf(fp, "%f\n", d.temperature);
    fprintf(fp, "%s\n", d.description);

    for (int i = 0; i < SIZE_V; i++) {
        fprintf(fp, "%d ", d.vettore[i]);
    }
    fprintf(fp, "\n");
}



void dealloca(Nodo *p) {
    while (p != NULL) {
        Nodo *temp = p;
        p = p->next;
        free(temp);
    }
}

