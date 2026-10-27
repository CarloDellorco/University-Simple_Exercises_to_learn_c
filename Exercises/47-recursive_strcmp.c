#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int strecursivecmp(char *s1, char *s2);

int main(){
    char s1[MAX], s2[MAX];
    int n;
    printf("\nInsert the first string (max 99 characters):");
    fgets(s1, MAX-1, stdin);
    fflush(stdin);
    printf("\nInsert the second string(max 99 characters):");
    fgets(s2, MAX-1, stdin);

    for(n=0; n<MAX; n++){ //pongo tutte le stringe in carattere minuscolo
        if(isupper(s1[n])){
            s1[n]=s1[n]+32;
        }
        if(isupper(s2[n])){
            s2[n]=s2[n]+32;
        }
    }

    if (strecursivecmp(s1, s2) == 0) {
        printf("\nThe two strings are the same");
    }
    if (strecursivecmp(s1, s2) == 1) {
        printf("\n%s preceded %s in alphabetic order", s2, s1);
    }
    if (strecursivecmp(s1, s2) == -1){
        printf("\n%s preceded %s in alphabetic order", s1, s2);
    }
}



int strecursivecmp(char *s1, char *s2){
    if(*s1<*s2){
        return -1;
    }
    if(*s1>*s2){
        return 1;
    }
    if(*s1=='\0'){
        return 0;
    }
    return strecursivecmp(s1+1, s2+1);
}

