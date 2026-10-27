#include <stdio.h>

void main(){
    char c;

    printf("insert a char\n");
    scanf("%c", &c);

    //is it a letter?
    if(((c>='A') && (c<='Z')) || ((c>='a') && (c<='z'))){
        if((c>='A') && (c<='Z')) {
            c+=32; //conversion from uppercase to lowercase
        }

        if((c=='a')||(c=='e')||(c=='i')||(c=='o')||(c=='u'))
            printf("IT'S A VOWEL!!\n");
        else
            printf("we got a consonant\n");
    }
    else
        printf("i got you!! %c is not a letter\n", c);
}
