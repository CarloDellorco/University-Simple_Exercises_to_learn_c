#include <stdio.h>

int main(void) {
    int int1, int2, int3;

    printf("\n insert the first integer:\n");
    scanf("%d", &int1);

    printf("\ninsert the second integer:\n");
    scanf("%d", &int2); //inserisco la seconda variabile

    printf("\ninsert the third integer\n");
    scanf("%d", &int3); //inserisco la terza variabile

    int sum= int1+ int2+ int3; //eseguo la somma
    int med= (int1+ int2+ int3)/3; //eseguo la media
    printf("\n the sum is: %d.\n", sum);
    printf("\n the average of the numbers is: %d.\n", med); //risultato a schermo
    return 0;
}
