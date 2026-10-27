#include <stdio.h>
#define DIM 3

void main(){
    int a[DIM];
    int b[DIM];
    int c[2*DIM];
    int i;

    printf("Insert %d numbers\n", DIM);

    for(i=0;i<DIM;i++){
        printf("number at the i-th position %d:",i);
        scanf("%d", &c[i]);
    }

    printf("Insert %d numbers\n", DIM);
    for(i=0;i<DIM;i++){
        printf("number at the i-th position %d:",i);
        scanf("%d", &c[i+DIM]);
    }

    printf("concatenated array is:");
    for(i=0; i<2*DIM;i++)
        printf("%d ", c[i]);
}