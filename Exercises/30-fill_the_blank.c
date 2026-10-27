#include <stdio.h>


void espandi(char *);
int individua(char *);

int main(void) {
    char n[100];

    printf("Insert a string with some *, the code will find any combination by filling it with 0 and 1:\n");

    if (scanf("%99s", n) != 1) {
        return 1;
    }
    espandi(n);
    return 0;
}



void espandi(char *n) {
    int i = individua(n);
    if (i == -1) {
        printf("%s\n", n);
        return;
    }
    n[i] = '0';
    espandi(n);

    n[i] = '1';
    espandi(n);

    n[i] = '*';
}



int individua(char *str) {
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == '*') {
            return i;
        }
        i++;
    }
    return -1;
}

