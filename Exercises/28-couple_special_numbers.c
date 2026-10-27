#include <stdio.h>

int ddpqp(int a, int b);

//the moltiplication of 2 numbers of the sequence equals one the int squared
int main(void) {
    int counter = 0;
    int precedente = 0, attuale;

    printf("Insert a sequence of numbers separated by spaces(end with 0)\n");

    while (scanf("%d", &attuale) == 1 && attuale != 0) {
        if (precedente != 0) {
            counter += ddpqp(precedente, attuale);
        }

        precedente = attuale;
    }

    printf("couple of numbers that satisfy the prerequisites are: %d\n", counter);
    return 0;
}



int ddpqp(int a, int b) {
    int x = 0;
    int p = a * b;

    if (a == b || a % 2 != 0 || b % 2 != 0 || p < 0) {
        return 0;
    }
    while (x * x < p) {
        x++;
    }
    if (x * x == p) {
        return 1;
    }
    return 0;
}
