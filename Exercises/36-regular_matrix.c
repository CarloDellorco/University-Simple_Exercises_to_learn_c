
#include <stdio.h>
#include <math.h>

#define N 3

typedef struct {
    float x;
    float y;
} punto;

float distance(punto a, punto b);
int reg(punto m[N][N]);

int main(void) {
    punto m[N][N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("Insert the coordinates of point [%d][%d] (x y)\n: ", i, j);
            if (scanf("%f %f", &m[i][j].x, &m[i][j].y) != 2) {
                printf("Invalid input.\n");
                return 1;
            }
        }
    }

    if (reg(m)) {
        printf("The matrix is regular.\n");
    } else {
        printf("The matrix is not regular.\n");
    }

    return 0;
}



float distance(punto a, punto b) {
    float dx = a.x - b.x;
    float dy = a.y - b.y;

    return sqrtf(dx * dx + dy * dy);
}



int reg(punto m[N][N]) {
    float distdiag = 0.0f;
    float distmax = 0.0f;
    float distanza;

    for (int i = 0; i < N - 1; i++) {
        distdiag += distance(m[i][i], m[i + 1][i + 1]);
    }

    for (int i = 0; i < N; i++) {
        distanza = 0.0f;

        for (int j = 0; j < N - 1; j++) {
            distanza += distance(m[i][j], m[i][j + 1]);
        }
        if (distanza > distmax) {
            distmax = distanza;
        }
    }

    // Lunghezze totali delle colonne
    for (int j = 0; j < N; j++) {
        distanza = 0.0f;

        for (int i = 0; i < N - 1; i++) {
            distanza += distance(m[i][j], m[i + 1][j]);
        }
        if (distanza > distmax) {
            distmax = distanza;
        }
    }
    return distdiag > distmax;
}
