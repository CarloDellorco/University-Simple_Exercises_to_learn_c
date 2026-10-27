#include <stdio.h>
#include <string.h>
#define MAX 50

typedef struct{
    char carattere;
    int counter;
} occorrenza;

int main(){
    char stringa[MAX];
    occorrenza occorrenze[MAX];
    int i, j, counter_strutture=0;
    int posix;

    printf("insert a sentence with at most %d characters\n", MAX-1);
    fgets(stringa, MAX, stdin);
    stringa[strcspn(stringa, "\n")] = '\0';
    int const len_string = strlen(stringa);


    printf("insert position\n");
    scanf("%d", &posix);


        for(i=0; i<=posix; i++){
            int trovato=0;
            j=0;
            while((j<counter_strutture) && (!trovato)){
                if(stringa[i] == occorrenze[j].carattere){
                    occorrenze[j].counter++;
                    trovato=1;
                }
                j++;
            }
            if(!trovato){
                occorrenze[counter_strutture].carattere=stringa[i];
                occorrenze[counter_strutture++].counter=1;
            }
        }
    printf("occurencies up to %d are: \n", posix);
    for(i=0; i<counter_strutture; i++){
        printf("-- letter %c appear %d times",occorrenze[i].carattere, occorrenze[i].counter);
    }
}

