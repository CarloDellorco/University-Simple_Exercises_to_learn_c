#include <stdio.h>
#include <ctype.h>
#include <string.h>


#define MAX 81

int tautogramma(char*);


void main(){
    char str[MAX]={"¿Qué queso quieres?..Qu..quar..quartirolo"};
    if(tautogramma(str)){
        printf("string is tautogram\n");
    }
    else{
        printf("stringa is not a tautogram\n");
    }
}



int tautogramma(char *s){
    int i, l=strlen(s), count=0;
    char d, a;

    while (!isalpha(s[count])) {
        count++;
    }
    a = s[count];
    for(i=count; i<l; i++){
        if(!isalpha(s[i])){
            if(isalpha(s[i+1])){
                d = s[i+1];
                if(tolower(a) != tolower(d)){
                    return 0;
                }
            }
        }
    }
    return 1;
}

