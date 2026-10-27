
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 20

char* replace(char*, char*, char);

int main(void) {
    char originale[DIM], sostituire[DIM];
    char *output;
    char c;

    printf("Insert the original word:\n");
    scanf("%19s", originale);

    printf("insert the substitute word:\n");
    scanf("%19s", sostituire);

    printf("at which character do you want the substitution to happen?\n");
    scanf(" %c", &c);

    output = replace(originale, sostituire, c);

    if (output == NULL) {
        printf("Error allocating memory.\n");
        return 1;
    }

    printf("the word obtained from %s substituting %s at each %c is: %s\n", originale, sostituire, c, output);
    free(output);
    return 0;
}




char* replace(char* originale, char* sostituire, char c) {
    char *output;
    int i, j = 0, k;
    int numc = 0;
    int len_originale = strlen(originale);
    int len_sostituire = strlen(sostituire);
    int dim_output;

    for (i = 0; i < len_originale; i++) {
        if (originale[i] == c) {
            numc++;
        }
    }

    dim_output = len_originale + 1 - numc + numc * len_sostituire;
    output = malloc(dim_output * sizeof(char));

    if (output == NULL) {
        return NULL;
    }
    i = 0;

    while (i < len_originale) {
        if (originale[i] == c) {
            for (k = 0; k < len_sostituire; k++) {
                output[j] = sostituire[k];
                j++;
            }
        }
        else {
            output[j] = originale[i];
            j++;
        }
        i++;
    }
    output[j] = '\0';
    return output;
}
