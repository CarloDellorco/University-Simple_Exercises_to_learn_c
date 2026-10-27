#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 70

void Cesare(char string[], int k);

int main(void) {
    FILE *fp_in, *fp_out;
    char sentence[MAX];
    char *c;
    int k = -5;

    fp_in = fopen("C:/Users/carlo/CLionProjects/Simple_c_exercises/Files/cypher.txt", "r");

    if (fp_in == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    fp_out = fopen("C:/Users/carlo/CLionProjects/Simple_c_exercises/Files/cypher_out.txt", "w");

    if (fp_out == NULL) {
        printf("Error opening output file.\n");
        fclose(fp_in);
        return 1;
    }

    printf("\nOriginal document:\n");

    while ((c = fgets(sentence, MAX, fp_in)) != NULL) {
        printf("%s", sentence);
        Cesare(sentence, k);
        fprintf(fp_out, "%s", sentence);
    }

    fclose(fp_in);
    fclose(fp_out);

    printf("\nEncrypted document:\n");

    fp_out = fopen("C:/Users/carlo/CLionProjects/Simple_c_exercises/Files/cypher_out.txt", "r");

    if (fp_out == NULL) {
        printf("Error opening encrypted file.\n");
        return 1;
    }

    while ((c = fgets(sentence, MAX, fp_out)) != NULL) {
        printf("%s", sentence);
    }

    fclose(fp_out);

    return 0;
}



void Cesare(char string[], int k) {
    int i, l, base;

    l = strlen(string);

    for (i = 0; i < l; i++) {
        if (isalpha((unsigned char)string[i])) {
            base = isupper((unsigned char)string[i]) ? 'A' : 'a';
            string[i] = ((string[i] - base + k) % 26 + 26) % 26 + base;
        }
    }
}
