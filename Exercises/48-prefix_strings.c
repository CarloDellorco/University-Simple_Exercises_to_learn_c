
#include <stdio.h>
#include <string.h>

int pref(char *a, char *b);
void shift(char *s, char c);

int main(void) {
    char a[100], b[100], s[100], c;

    printf("Enter the first string: ");
    if (scanf("%99s", a) != 1) {
        return 1;
    }

    printf("Enter the second string: ");
    if (scanf("%99s", b) != 1) {
        return 1;
    }

    if (pref(a, b)) {
        printf("The first string is a prefix of the second string.\n");
    } else {
        printf("The first string is not a prefix of the second string.\n");
    }

    printf("Enter a string to shift: ");
    if (scanf("%99s", s) != 1) {
        return 1;
    }

    printf("Enter the character to append: ");
    if (scanf(" %c", &c) != 1) {
        return 1;
    }

    shift(s, c);
    printf("Result: %s\n", s);
    return 0;
}



int pref(char *a, char *b) {
    if (*a == '\0') {
        return 1;
    }

    if (*b == '\0') {
        return 0;
    }

    if (*a != *b) {
        return 0;
    }
    return pref(a + 1, b + 1);
}



void shift(char *s, char c) {
    int l = (int)strlen(s);

    if (l == 0) {
        s[0] = c;
        s[1] = '\0';
        return;
    }

    for (int i = 0; i < l - 1; i++) {
        s[i] = s[i + 1];
    }
    s[l - 1] = c;
    s[l] = '\0';
}

