
#include <stdio.h>
#include <stdlib.h>

int ramp10(int);

int main(int argc, char *argv[]) {
    int k, i, count = 0;

    if (argc < 2) {
        printf("Usage: %s <number>\n", argv[0]);
        return 1;
    }

    char *end;
    long input = strtol(argv[1], &end, 10);

    if (*end != '\0' || input < 1 || input > 1000000) {
        printf("Please provide a positive integer.\n");
        return 1;
    }

    k = (int)input;

    for (i = 10; count < k; i++) {
        if (ramp10(i)) {
            printf("%d\n", i);
            count++;
        }
    }

    return 0;
}

int ramp10(int x) {
    if (x < 10) {
        return 0;
    }

    if (x % 10 == 0) {
        return 0;
    }

    if ((x / 10) % (x % 10) != 0) {
        return 0;
    }

    if (x < 100) {
        return 1;
    }

    return ramp10(x / 10);
}
