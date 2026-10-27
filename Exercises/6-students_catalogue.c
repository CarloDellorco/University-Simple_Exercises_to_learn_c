#include <stdio.h>
#define MAX 5

typedef struct{
    char nome[50];
    char cognome [50];
    int matricola;
    int voto;
} student;

void main(){
    int i, grade, search_sub, trovato=0;

    student class[MAX]={
        {"Harry", "Potter", 17593, 0},
        {"Hermione", "Granger", 27573, 0},
        {"Tony", "Stark", 16553, 0},
        {"Jhon", "Snow", 18595, 0},
        {"Frodo", "Beggins", 12715, 0}};

    //student search
    printf("insert the student's person code\n");
    scanf ("%d", &search_sub);

    i=0;
    while(!(trovato) && (i<MAX)){
        if(class[i].matricola==(search_sub))
            trovato=1;
        i++;
    }
    if(trovato){ //student found
        printf("insert student's grade:\n");
        scanf("%d", &class[i-1].voto);
        printf ("the student is: %s %s\n", class[i-1].nome, class[i-1].cognome);
        printf ("the inserted grade is: %d", class[i-1].voto);
    }
    else{ //student not found
        printf("no person code associated with a student has been found");
    }
}

