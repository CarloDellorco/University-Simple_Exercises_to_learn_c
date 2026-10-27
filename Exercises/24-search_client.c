
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 30
#define LEN_TARGA 8
#define PREZZO 2.50f

#define CLIENTI_FILE "C:/Users/carlo/CLionProjects/Simple_c_exercises/Files/clienti.txt"
#define TEMP_FILE    "C:/Users/carlo/CLionProjects/Simple_c_exercises/Files/clienti.tmp"

typedef struct {
    char targa[LEN_TARGA];
    float credito;
    char nome[MAX];
    char cognome[MAX];
} cliente;

int cerca_cliente(FILE *, const char *, cliente *);
int update_status(cliente *);

int main(void) {
    FILE *fp;
    char targa[LEN_TARGA];
    cliente attuale;

    fp = fopen(CLIENTI_FILE, "r");

    if (fp == NULL) {
        perror("Cannot open clienti.txt.txt");
        return 1;
    }

    printf("Enter the license plate to search for:\n");

    if (scanf("%7s", targa) != 1) {
        fclose(fp);
        return 1;
    }

    if (!cerca_cliente(fp, targa, &attuale)) {
        printf("Client not found.\n");
        fclose(fp);
        return 1;
    }

    fclose(fp);

    printf("\nClient found:\n");
    printf("Plate: %s\n", attuale.targa);
    printf("Credit: %.2f EUR\n", attuale.credito);
    printf("Name: %s\n", attuale.nome);
    printf("Surname: %s\n", attuale.cognome);

    if (update_status(&attuale)) {
        printf("\nHello %s %s!\n", attuale.nome, attuale.cognome);
        printf("Access granted.\n");
        printf("Remaining credit: %.2f EUR\n", attuale.credito);
    } else {
        printf("\nAccess denied: insufficient credit or file update failed.\n");
    }

    return 0;
}

int cerca_cliente(FILE *fp, const char *targa, cliente *c) {
    rewind(fp);

    while (fscanf(fp, "%7s %f %29s %29s",
                  c->targa,
                  &c->credito,
                  c->nome,
                  c->cognome) == 4) {

        if (strcmp(c->targa, targa) == 0) {
            return 1;
        }
    }

    return 0;
}

int update_status(cliente *attuale) {
    FILE *fp;
    FILE *temp;
    cliente c;
    int trovato = 0;
    float nuovo_credito = 0.0f;

    fp = fopen(CLIENTI_FILE, "r");

    if (fp == NULL) {
        perror("Cannot open client file");
        return 0;
    }

    temp = fopen(TEMP_FILE, "w");

    if (temp == NULL) {
        perror("Cannot create temporary file");
        fclose(fp);
        return 0;
    }

    while (fscanf(fp, "%7s %f %29s %29s",
                  c.targa,
                  &c.credito,
                  c.nome,
                  c.cognome) == 4) {

        if (strcmp(c.targa, attuale->targa) == 0) {
            trovato = 1;

            if (c.credito < PREZZO) {
                fclose(fp);
                fclose(temp);
                remove(TEMP_FILE);
                return 0;
            }

            c.credito -= PREZZO;
            nuovo_credito = c.credito;
        }

        if (fprintf(temp, "%s %.2f %s %s\n",
                    c.targa,
                    c.credito,
                    c.nome,
                    c.cognome) < 0) {

            fclose(fp);
            fclose(temp);
            remove(TEMP_FILE);
            return 0;
        }
    }

    if (ferror(fp) || !trovato) {
        fclose(fp);
        fclose(temp);
        remove(TEMP_FILE);
        return 0;
    }

    if (fclose(fp) != 0) {
        fclose(temp);
        remove(TEMP_FILE);
        return 0;
    }

    if (fclose(temp) != 0) {
        remove(TEMP_FILE);
        return 0;
    }


    if (remove(CLIENTI_FILE) != 0) {
        perror("Cannot remove original client file");
        remove(TEMP_FILE);
        return 0;
    }

    if (rename(TEMP_FILE, CLIENTI_FILE) != 0) {
        perror("Cannot rename temporary file");
        return 0;
    }

    attuale->credito = nuovo_credito;
    return 1;
}
