#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[]){
    FILE *fp=fopen(argv[1], "r");
    int count[5]={0};
    int c;

    if(fp!=NULL && argc>1){
        while((c=fgetc(fp)) != EOF){
            if(c == '0'){
                count[0]++;
            }
            else if(c == '2'){
                count[1]++;
            }
            else if(c == '4'){
                count[2]++;
            }
            else if(c == '6'){
                count[3]++;
            }
            else if(c == '8'){
                count[4]++;
            }
        }
        fclose(fp);
        for(int i=1; i<5; i++){
            if(count[0]!=count[i]){
                printf("even figures don't have an omogeneous frequency\n");
            }
        }
        printf("even figures have an omogeneous frequency\n");
    }
    printf("error occurred while reading the input\n");
}
