
#include <stdio.h>

#define N 7

int cobin(int n, int k);

int main(void) {
    int n, k;

    for (n = 0; n < N; n++) {
        for (k = 0; k <= n; k++) {
            printf("%5d", cobin(n, k));
        }
        printf("\n");
    }
    return 0;
}

int cobin(int n, int k) {
    if (k < 0 || k > n) {
        return 0;
    }

    if (k == 0 || k == n) {
        return 1;
    }
    return cobin(n - 1, k) + cobin(n - 1, k - 1);
}
