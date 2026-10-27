#include <stdio.h>
#include <string.h>
#define DIM 15

void swap(char*, int);
int ugualioquasi(char*,char*);

//check weather 2 string can be the same by reordering their characters
int main(){
    char stringa1[DIM];
    char stringa2[DIM];

    printf("insert the first word\n");
    scanf("%s", stringa1);
    printf("insert the second word\n");
    scanf("%s", stringa2);

    if(ugualioquasi(stringa1,stringa2)) {
        printf("%s and %s are almost equals\n", stringa1, stringa2);
    }
    else
        printf("%s and %s are not almost equals\n", stringa1, stringa2);
}


int ugualioquasi(char*a,char*b){
    int responso=0, i=0;
    if(!strcmp(a,b)){
        return 1;
    }
    while(*(a+i) == *(b+i)){
        i++;
    }
    swap(b,i);
    if(!strcmp(a,b)){
        responso=1;
    }
    swap(b,i);
    return responso;
}

void swap(char*c, int i){
    char tmp;
    tmp=*(c+i);
    *(c+i)=*(c+i+1);
    *(c+i+1)=tmp;
}
