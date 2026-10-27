#include <stdio.h>
void main(){
    float a, b;
    int choice=0;
    printf("--CALCULATOR--\n");

    while(choice!=5) {
        printf("select an operation; 1:sum, 2:subtraction, 3:division, 4:product, 5:exit");
        scanf("%d", &choice);

        printf("insert the first number (period to add decimals): \n");
        scanf("%f", &a);
        printf("insert the second number (period to add decimals): \n");
        scanf("%f", &b);

        switch(choice){
            case 1:
                printf("sum: %f\n", a+b);
                break;
            case 2:
                printf("subtraction: %f\n", a-b);
                break;
            case 3:
                printf("division: %f\n", a/b);
                break;
            case 4:
                printf("product: %f\n", a*b);
                break;
            case 5:
                printf("goodbye\n");
                break;
            default:
                printf("wrong input please retry\n");
                break;
        }
    }
}
