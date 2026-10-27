#include <stdio.h>

int main(){
    //this program print the alphabet up to a point decided by the user
    int n, c=0;
    printf("dimmi quante lettere dell'alfabeto vuoi vedere\n");
    scanf("%d", &n);
    if (n <= 26) {
        while(c<n){
            printf("%c", 'a'+c);
            c++;
        }
    }
    else {
        printf("maximum allowed number is 26!\n");
        return 0;
    }
    return 0;
}
