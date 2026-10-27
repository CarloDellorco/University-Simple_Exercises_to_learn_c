#include <stdio.h>
#define DIM 5

void main(){
    char a[DIM];
    char b[DIM];
    char c[2*DIM];

    printf("Insert the first word\n");
    printf("Maximum number of letters allowed %d\n", DIM-1);
    scanf("%s", a);

    printf("Insert the second word\n");
    printf("Maximum number of letters allowed %d\n", DIM-1);
    scanf("%s", b);

    for(int i=0; i<DIM; i++){
        c[i]=a[i];
        c[i+DIM]=b[i];
    }

    c[DIM-1]=' ';
    c[2*DIM-1]='\0';
    printf("the joint string is: %s\n", c);
}
