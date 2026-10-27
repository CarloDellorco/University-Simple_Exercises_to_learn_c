#include <stdio.h>
#include <string.h>
#define DIM 15

typedef struct{
    char invertita[DIM];
} inv;

inv strinverter(char*);

int main(){
    char stringa[DIM]="converter";
    inv s;
    printf("original string is: %s\n", stringa);

    s = strinverter(stringa);

    printf("inverted string is %s\n", s.invertita);
}


inv strinverter(char* s){
    inv output;
    int len, i;
    len = strlen(s);
    for (i=0; i<len; i++){
        *(output.invertita+i)=*(s+len-1-i);
    }
    *(output.invertita+len)='\0';
    return output;
}
