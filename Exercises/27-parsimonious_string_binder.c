#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DIM 80

char *conc_pars(char* s1, char* s2); //mi serve un pointer in quanto finale arriverà nel main

void main(){
    char s1[DIM], s2[DIM];
    char *finale;

    printf("Insert the first string (maximum 79 characters)\n");
    fflush(stdin);
    fgets(s1, DIM-1, stdin); //otteniamo la prima stringa

    printf("Insert the second string (maximum 79 characters)\n");
    fflush(stdin);
    fgets(s2, DIM-1, stdin); //prendo la seconda stringa

    finale = conc_pars(s1, s2); //finale è il risultato della funzione
    printf("the two string joined gives:\n %s\n", finale);
    free(finale);
}


char *conc_pars(char* stringa1, char* stringa2){
    int lnuova;
    char *fl;

    lnuova= strlen(stringa1) + strlen(stringa2) + 1; //il +1 è per il terminatore

    fl = (char*)malloc(lnuova*sizeof(char)); //alloco esattamente la memoria necessaria

    strcpy(fl, stringa1); //uso due funzioni di string.h per copiate e tagliare le due stringhe (copia)
    strcat(fl, stringa2); //taglia ed incolla

    return fl; //ritorno il risultato
}
