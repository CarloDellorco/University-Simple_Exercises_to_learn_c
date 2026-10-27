#include <stdio.h>
#define DIM 10

void main(){
    int a[DIM];
    int i, k=0, tmp, scambio=0; //k elementi ordinati

    printf("insert %d numbers\n", DIM);
    for(i=0; i<DIM; i++){
        printf("position number %d :", i);
        scanf("%d", &a[i]);
    }
    k=0;
    while((k<DIM-1) && (!scambio)){
        printf("iteration: %d\n", k);
        i=0;
        scambio=0;
        while(i<(DIM-k-1)){
            if(a[i]>a[i+1]){ //swap
                tmp=a[i+1];
                a[i+1]=a[i];
                a[i]=tmp;
                scambio=1;
            }
            i++;
        }
        k++; //numero di elementi ordinati
    }
    printf("the ordered array is:");
    for(i=0; i<DIM; i++) {
        printf("%d   ",a[i]);
    }
}
