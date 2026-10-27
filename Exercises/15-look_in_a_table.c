#include <stdio.h>
#define R 3
#define C 5

typedef int mat[R][C];

typedef struct{
    int x;
    int y;
} coordinata;

typedef struct{
    int actualRow;
    int actualCol;
    mat contents;
} tabella;

static coordinata cerca(tabella,int);

int main(){
    int i, j, pos, val;
    coordinata trovato;
    tabella myTab;

    do{
        printf("How many rows in your table? (max %d)\n", R);
        scanf("%d", &myTab.actualRow);
        printf("How many columns in your table? (max %d)\n", C);
        scanf("%d", &myTab.actualCol);
    }	while((myTab.actualRow>R)||(myTab.actualCol>C));
    for(i=0; i<myTab.actualRow; i++){
        for(j=0; j<myTab.actualCol; j++){
            printf("element [%d][%d]\n", i,j);
            scanf("%d", &myTab.contents[i][j]);
        }
    }
    printf("what value do you want to look for?\n");
    scanf("%d", &val);

    trovato=cerca(myTab, val);

    if((trovato.x!=-1)&&(trovato.y!=-1))
        printf("value %d is at position [%d][%d]\n", val, trovato.x, trovato.y);
    else
        printf("value %d in not in the table\n", val);
}




coordinata cerca(tabella t, int val){
    int i,j;
    coordinata trovato;
    for(i=0; i<t.actualRow; i++){
        for(j=0; j<t.actualCol; j++){
            if(t.contents[i][j]==val){
                trovato.x =i;
                trovato.y =j;
                return trovato;
            }
        }
    }
    trovato.x=-1;
    trovato.y=-1;
    return trovato;
}
