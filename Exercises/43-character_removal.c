
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 70

char *rimuovi(char *, char);

int main(void) {
    char frase[DIM], *nuova;
    char c;

    printf("Enter the sentence from which you want to remove a character (letters and spaces only):\n");
    if (fgets(frase, DIM, stdin) == NULL) {
        return 1;
    }
    printf("Enter the character to remove:\n");

    if (scanf("%c", &c) != 1) {
        return 1;
    }
    nuova = rimuovi(frase, c);

    if (nuova == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("The resulting sentence is: %s", nuova);
    free(nuova);
    return 0;
}



char *rimuovi(char *s, char c) {
    int len = (int)strlen(s);
    int i, j = 0;
    char *ns = malloc((len + 1) * sizeof(char));

    if (ns == NULL) {
        return NULL;
    }

    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] != c) {
            ns[j] = s[i];
            j++;
        }
    }

    ns[j] = '\0';
    return ns;
}
