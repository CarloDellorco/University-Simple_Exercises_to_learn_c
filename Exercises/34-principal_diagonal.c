
#include <stdio.h>

#define N 5

int controlla(char m[][N]);

int main(void) {
    char matrix[N][N] = {
        {'E', 'N', 'E', 'A', 'S'},
        {'E', 'S', 'S', 'O', 'R'},
        {'X', 'I', 'A', 'A', 'D'},
        {'G', 'O', 'M', 'M', 'A'},
        {'B', 'R', 'E', 'V', 'E'}
    };

    if (controlla(matrix)) {
        printf("the word in the principal diagonal is present also in a row or column.\n");
    } else {
        printf("the word in the principal diagonal is not present also in a row or column.\n");
    }
    return 0;
}




int controlla(char m[][N]) {
    int i, j;
    int orizzL, orizzD, vertU, vertD;

    for (i = 0; i < N; i++) {
        orizzL = orizzD = vertU = vertD = 0;

        for (j = 0; j < N; j++) {
            if (m[i][j] == m[j][j]) {
                orizzL++;
            }
            if (m[i][N - 1 - j] == m[j][j]) {
                orizzD++;
            }
            if (m[j][i] == m[j][j]) {
                vertU++;
            }
            if (m[N - 1 - j][i] == m[j][j]) {
                vertD++;
            }
        }

        if (orizzL == N || orizzD == N ||
            vertU == N || vertD == N) {
            return 1;
            }
    }
    return 0;
}
