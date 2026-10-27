
#include <stdio.h>

#define N 5

int conta(int m[N][N]);
int check(int m[N][N], int i, int j);

int main(void) {
    int k;
    int m[N][N] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    k = conta(m);
    printf("The matrix has %d dominant elements\n", k);
    return 0;
}



int conta(int m[N][N]) {
    int i, j;
    int count = 0;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (check(m, i, j)) {
                count++;
            }
        }
    }

    return count;
}



int check(int m[N][N], int i, int j) {
    int y, z;

    for (y = i; y < N; y++) {
        for (z = j + 1; z < N; z++) {
            if (m[y][z] >= m[i][j]) {
                return 0;
            }
        }
    }

    for (y = i + 1; y < N; y++) {
        for (z = 0; z < N; z++) {
            if (m[y][z] >= m[i][j]) {
                return 0;
            }
        }
    }

    return 1;
}
