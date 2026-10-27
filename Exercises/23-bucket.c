#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int dim;
    int *v;
}bucket;

bucket newbucket(int);
int add(bucket, int);

int main(int argc, char* argv[]){
    int d, n=0;
    bucket bucket;
    d = atoi(argv[1]);
    bucket = newbucket(d);
    printf("write a list of integer numbers (terminate by writing a negative number)\n");
    do {
        while(n>=0){
            printf("write an int:");
            scanf(" %d\n", &n);
        }
    } while(add(bucket, n));
    return 0;
}

bucket newbucket(int d){
    bucket bucket;
    bucket.dim = d;
    bucket.v= (int*)calloc(d+1, sizeof(int));
    return bucket;
}

int add(bucket b, int num){
    int i=0;
    if(num<0){
        return 0;
    }
    for(i=0; i<b.dim; i++){
        if(b.v[i]==0){
            b.v[i] = num;
            return 1;
        }
    }
    return 0;
}

