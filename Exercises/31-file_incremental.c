
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 314

int* arraynumerico(void);
char* incremento(char*, int*);

int main(void) {
    FILE *fp_in, *fp_out;
    char testo[MAX];
    char *testo_out;
    int *arr_int;

    fp_in = fopen("C:/Users/carlo/CLionProjects/Simple_c_exercises/Files/PS.txt", "r");

    if (fp_in == NULL) {
        printf("Error opening PS.txt\n");
        return 1;
    }
    fp_out = fopen("C:/Users/carlo/CLionProjects/Simple_c_exercises/Files/PS_out.txt", "w");
    if (fp_out == NULL) {
        printf("Error opening PS_out.txt\n");
        fclose(fp_in);
        return 1;
    }

    if (fgets(testo, MAX, fp_in) == NULL) {
        printf("Error reading the text\n");
        fclose(fp_in);
        fclose(fp_out);
        return 1;
    }

    testo[strcspn(testo, "\n")] = '\0';

    arr_int = arraynumerico();

    if (arr_int == NULL) {
        printf("Error acquiring the numbers\n");
        fclose(fp_in);
        fclose(fp_out);
        return 1;
    }

    testo_out = incremento(testo, arr_int);

    if (testo_out == NULL) {
        printf("Error allocating memory\n");
        free(arr_int);
        fclose(fp_in);
        fclose(fp_out);
        return 1;
    }

    fprintf(fp_out, "%s\n", testo_out);

    free(arr_int);
    free(testo_out);
    fclose(fp_in);
    fclose(fp_out);

    return 0;
}




int* arraynumerico(void) {
    int *seq = NULL;
    int n;
    int i = 0;
    int *temp;

    printf("Insert a sequence of number and terminate with a negative one\n");
    while (1) {
        printf("Next number: ");

        if (scanf("%d", &n) != 1) {
            free(seq);
            return NULL;
        }

        temp = realloc(seq, (i + 1) * sizeof(int));

        if (temp == NULL) {
            free(seq);
            return NULL;
        }
        seq = temp;
        seq[i] = n;
        i++;

        if (n < 0) {
            return seq;
        }
    }
}



char* incremento(char *s, int *n) {
    int num = 0;
    int i = 0;
    int j = 0;
    int count = 0;
    int len = (int)strlen(s);
    char *ns;

    while (n[count] >= 0) {
        count++;
    }
    ns = malloc((count + 1) * sizeof(char));
    if (ns == NULL) {
        return NULL;
    }
    while (n[i] >= 0 && num < len) {
        num += n[i];

        if (num >= len) {
            break;
        }
        ns[j] = s[num];
        j++;
        i++;
    }
    ns[j] = '\0';
    return ns;
}
