#include <stdio.h>
#define DIM 50

int main(){
    char frase[DIM*3];
    char lettera='a';
    int i=0, j=0;

    printf("---Distorted Repetitor---\nInsert a sentence, use only lowercase characters.\n(max %d chars)\n", DIM);

    while( lettera!='\n' && i<DIM ){
        scanf("%c", &lettera);

        if ((lettera=='a') || (lettera=='e') || (lettera=='i') || (lettera=='o')|| (lettera=='u')){
            frase[j]=lettera;
            frase[j+1]='f';
            frase[j+2]=lettera;
            j+=3;
        }
        else{
            frase[j]=lettera;
            j++;
        }
        i++;
    }
    frase[j]='\0';

    printf("%s\n", frase);
    return 0;
}
