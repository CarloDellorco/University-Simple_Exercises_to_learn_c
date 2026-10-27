#include <stdio.h>

int main() {
    int i;
    int k;
    printf("How many numbers of the sequence do you want to see?\n");
    scanf("%d", &k);

    int a[k];
    if(k<0){
        printf("You inserted a negative number\n");
    } else{
        for(i=0; i<k; i++){
            a[i]=1;
        }
        for(i=3; i<k; i++){
            a[i]=a[i-2]+a[i-3];
        }
    }
    for(i=0; i<k; i++){
        printf("%d ", a[i]);
    }
}
