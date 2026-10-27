#include <stdio.h>
typedef struct{
    int tipo;
    float a;
    float b;
} geometrical_shape;

void main(){
    geometrical_shape figura;
    float area, a, b;

    //define the shape
    printf("chose a shape: \n 0=rectangle;\n 1=triangle;\n 2=square\n");
    scanf("%d", &figura.tipo);

    //area calculation
    switch(figura.tipo){
        case 0:		//rectangle
            printf("insert the base\n");
            scanf("%f", &figura.a);
            printf("insert the height\n");
            scanf("%f", &figura.b);
            area=(a*b);
            printf("the area of the rectangle is: %f", area);
            break;

        case 1:		//triangle//
            printf("insert the base\n");
            scanf("%f", &figura.a);
            printf("insert the height\n");
            scanf("%f", &figura.b);
            area=(figura.a*figura.b)/2;
            printf("the area of the tringle is: %f", area);
            break;

        case 2:		//square
            printf("insert the square's size lenght\n");
            scanf("%f", &figura.a);
            area=(figura.a*figura.a);
            printf("the area of the square is: %f", area);
            break;

        default:
            printf("wrong input\n");
            break;
    }
}

