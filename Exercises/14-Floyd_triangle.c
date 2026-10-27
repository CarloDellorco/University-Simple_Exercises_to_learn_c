#include <stdio.h>
int main() {

    int nrighe;
    int i=1, n=1, k=0;

    printf ("choose the number of rows:\n");
    scanf ("%d", &nrighe);

    while (i <= nrighe) {
        while (k < i){
            printf("%3d", n);
            ++k;
            ++n;
        }
        printf("\n");
        i++;
        k=0;
    }
    return 0;
}
