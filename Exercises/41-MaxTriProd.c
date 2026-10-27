
#include <stdio.h>
#include <stdlib.h>

#define DIM 50

int maxtripod(int *, int);
int *sommeprefisse(int *, int);

int main(void) {
    int a[DIM];
    int n, i;
    int *sp;

    do {
        printf("How many elements do you want to enter?\n");
        printf("The maximum number of elements is %d.\n", DIM);
        if (scanf("%d", &n) != 1) {
            return 1;
        }
    } while (n < 1 || n > DIM);

    for (i = 0; i < n; i++) {
        printf("Enter the next integer:\n");

        if (scanf("%d", &a[i]) != 1) {
            return 1;
        }
    }

    if (n < 3) {
        printf("At least three elements are required.\n");
        return 1;
    }

    printf("The maximum product of three elements is: %d\n", maxtripod(a, n));
    sp = sommeprefisse(a, n);
    if (sp == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("The prefix sums are: ");
    for (i = 0; i < n; i++) {
        printf("%d ", sp[i]);
    }

    printf("\n");
    free(sp);
    return 0;
}



int maxtripod(int *a, int n) {
    int t, f, l;
    int max = a[0] * a[1] * a[2];

    for (t = 0; t < n; t++) {
        for (f = t + 1; f < n; f++) {
            for (l = f + 1; l < n; l++) {
                int prodotto = a[t] * a[f] * a[l];

                if (prodotto > max) {
                    max = prodotto;
                }
            }
        }
    }

    return max;
}



int *sommeprefisse(int *a, int n) {
    int i;
    int *sp = malloc(n * sizeof(int));

    if (sp == NULL) {
        return NULL;
    }

    sp[0] = a[0];

    for (i = 1; i < n; i++) {
        sp[i] = a[i] + sp[i - 1];
    }
    return sp;
}
