#include <stdio.h>
#define MAX 50

void stampa (char *s);
void ribalta (char *s);

int main(){
    char parola[MAX];

    printf("Insert a word\n");
    scanf("%s", parola);

    printf("you inserted: ");
    stampa(parola);

    printf("\ninverted is: ");
    ribalta(parola);
    return 0;
}


void stampa (char *s){
    //se incontro il terminatore fine
    if(*s!='\0'){ //senno caso induttivo
        printf("%c",*s);
        stampa(s+1); //stampa le lettere di una parola nel giusto ordine
    }
}


void ribalta(char *s){
    if(*s!='\0'){
        ribalta(s+1);
        printf("%c",*s); //va a ritroso a prendere le lettere dall'ultima alla prima di una parola
    }
}

