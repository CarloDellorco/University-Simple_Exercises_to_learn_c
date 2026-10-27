#include <stdio.h>

int main (){
    int n, i=0;
    int ultimo=1, penultimo=1, nuovo;

    printf("how many numbers of the sequence do you want to see:\n");
    scanf("%d", &n);

    while(i<n){
        if(i == 0){
            ultimo=1;
            printf("%d ", ultimo);
        }
        else if(i==1){
            penultimo=1;
            printf("%d ",penultimo);
        }
        else{
            nuovo = penultimo + ultimo;
            ultimo=penultimo;
            penultimo=nuovo;

            printf("%d ",nuovo);
        }
        i++;
    }
}
