#include <stdio.h>
#define DIM 9

void sort (int *a, int p, int u);
void merge (int *a, int p, int m, int u);
void print (int v[], int d);
void swap (int *a, int *b);

int main(){
    int a[DIM] = {10, 9, 0, 1, -5, -1, 23, 14, -2};
    printf("Original array is:\n");
    print(a, DIM);
    sort(a, 0, DIM-1);
    printf("Ordered array is:\n");
    print(a, DIM);
    return 0;
}

void print(int v[], int d){
    int i;
    for(i=0; i<DIM; i++){
        printf("%3d", v[i]);
    }
    printf("\n");
}

void swap (int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


void sort (int a[], int p, int u){
    if((p==u-1) && (a[p]>a[u])){
        swap(a+p, a+u);
    }
    else if (p<u-1){
        sort (a, p, (u+p)/2);
        sort (a, (u+p)/2+1, u);
        merge (a, p, (u+p)/2, u);
    }
}


void merge (int a[], int p, int m, int u){
    while(p<=m){
        if(a[p]>a[m+1]){
            swap (a+p, a+m+1);
            sort (a, m+1, u);
        }
        p++;
    }
}

