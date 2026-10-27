
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 200

char* shrink(char*);
char* eliminacaratteri(char*, char);
char* shrink2(char*);

int main(void) {
    char stringa[MAX];

    printf("Insert a sentence: only the first occurrence of each character will be retained.\n");

    if (fgets(stringa, MAX, stdin) == NULL) {
        return 1;
    }

    stringa[strcspn(stringa, "\n")] = '\0';

    char* metodo1 = shrink(stringa);
    char* metodo2 = shrink2(stringa);

    if (metodo1 == NULL || metodo2 == NULL) {
        printf("Memory allocation error.\n");
        free(metodo1);
        free(metodo2);
        return 1;
    }

    printf("Method 1: %s\n", metodo1);
    printf("Method 2: %s\n", metodo2);

    free(metodo1);
    free(metodo2);

    return 0;
}

char* shrink(char* s) {
    char* risultato = malloc(strlen(s) + 1);

    if (risultato == NULL) {
        return NULL;
    }

    strcpy(risultato, s);

    int i = 0;

    while (risultato[i] != '\0') {
        int trovato = 0;

        for (int j = 0; j < i; j++) {
            if (risultato[i] == risultato[j]) {
                trovato = 1;
                break;
            }
        }

        if (trovato) {
            char* temp = eliminacaratteri(risultato, risultato[i]);

            if (temp == NULL) {
                free(risultato);
                return NULL;
            }

            free(risultato);
            risultato = temp;
        } else {
            i++;
        }
    }

    return risultato;
}

char* eliminacaratteri(char* str, char c) {
    int len = strlen(str);
    char* ns = malloc(len + 1);

    if (ns == NULL) {
        return NULL;
    }

    int i, j = 0;
    int primo = 1;

    for (i = 0; i < len; i++) {
        if (str[i] == c) {
            if (primo) {
                ns[j++] = str[i];
                primo = 0;
            }
        } else {
            ns[j++] = str[i];
        }
    }

    ns[j] = '\0';

    return ns;
}

char* shrink2(char* s) {
    int i, j, k = 0;
    int len = strlen(s);

    char* snew = malloc(len + 1);

    if (snew == NULL) {
        return NULL;
    }

    for (i = 0; i < len; i++) {
        int trovato = 0;

        for (j = 0; j < k; j++) {
            if (s[i] == snew[j]) {
                trovato = 1;
                break;
            }
        }

        if (!trovato) {
            snew[k++] = s[i];
        }
    }

    snew[k] = '\0';

    return snew;
}


