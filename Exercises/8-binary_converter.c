#include <stdio.h>

int main(){
    int n, d, r;
    printf("Insert an integer positive number:\n");
    scanf("%d", &n);

    while(n<0){
        printf("You inserted a negative number\n");
        printf("Please insert a integer positive number\n");
        scanf("%d", &n);
    }

    if(n<=1)
        printf("your number %d in binary is: %d\n", n, n);
    else{
        d=n;
        printf("your number %d in binary is:\n", n);
        while(d){
            r=d%2;
            d=d/2;
            printf("%d\n", r);
        }
        printf("conversion is from below to upward\n");
    }
}
