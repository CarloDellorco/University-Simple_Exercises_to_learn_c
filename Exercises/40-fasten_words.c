
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 15
#define OVERLAPMINIMO 1

typedef struct nd {
    char *word;
    struct nd *next;
} parola;

typedef parola *sequenza;

char *allaccia(char *, char *);
sequenza shrink(sequenza);
sequenza aggiungi(sequenza, char *);
void print(sequenza);
int misuraoverlap(char *, char *);
int stringhecompatibili(char *, char *, int);


int main(void) {
    char parola_1[DIM], parola_2[DIM];
    char *risultato;
    sequenza s = NULL;

    printf("Insert words to fasten:\n");

    if (scanf("%14s %14s", parola_1, parola_2) != 2) {
        return 1;
    }

    risultato = allaccia(parola_1, parola_2);

    if (risultato != NULL) {
        printf("the two words fasten are: %s\n\n", risultato);
        free(risultato);
    } else {
        printf("The two words are not joinable.\n");
    }

    s = aggiungi(s, "rio");
    s = aggiungi(s, "tori");
    s = aggiungi(s, "dato");
    s = aggiungi(s, "timida");

    print(s);
    s = shrink(s);

    printf("La sequenza diventa:\n");
    print(s);

    while (s != NULL) {
        sequenza temp = s;
        s = s->next;
        free(temp->word);
        free(temp);
    }
    return 0;
}



char *allaccia(char *p, char *q) {
    int ov = misuraoverlap(p, q);

    if (ov < OVERLAPMINIMO) {
        return NULL;
    }

    char *risultato = malloc(strlen(p) + strlen(q) - ov + 1);

    if (risultato == NULL) {
        return NULL;
    }

    strcpy(risultato, p);
    strcat(risultato, q + ov);

    return risultato;
}



sequenza shrink(sequenza seq) {
    if (seq == NULL || seq->next == NULL) {
        return seq;
    }

    if (misuraoverlap(seq->word, seq->next->word) >= OVERLAPMINIMO) {
        char *w = allaccia(seq->word, seq->next->word);

        if (w == NULL) {
            seq->next = shrink(seq->next);
            return seq;
        }

        sequenza del = seq;
        sequenza successivo = seq->next;

        free(del->word);
        free(successivo->word);

        successivo->word = w;
        del->next = NULL;
        free(del);

        return shrink(successivo);
    }

    seq->next = shrink(seq->next);
    return seq;
}



sequenza aggiungi(sequenza s, char *p) {
    sequenza n = malloc(sizeof(parola));

    if (n == NULL) {
        return s;
    }

    n->word = malloc(strlen(p) + 1);

    if (n->word == NULL) {
        free(n);
        return s;
    }

    strcpy(n->word, p);
    n->next = s;

    return n;
}



void print(sequenza s) {
    if (s == NULL) {
        printf("--|\n");
        return;
    }

    printf("%s\n", s->word);

    if (s->next != NULL) {
        printf("-->\n");
    }

    print(s->next);
}



int misuraoverlap(char *p, char *q) {
    int max_ov = (int)strlen(p);
    int len_q = (int)strlen(q);

    if (max_ov > len_q) {
        max_ov = len_q;
    }

    for (; max_ov >= OVERLAPMINIMO; max_ov--) {
        if (stringhecompatibili(p, q, max_ov)) {
            return max_ov;
        }
    }
    return 0;
}



int stringhecompatibili(char *p, char *q, int n) {
    int len_p = (int)strlen(p);

    for (int i = 0; i < n; i++) {
        if (p[len_p + i - n] != q[i]) {
            return 0;
        }
    }

    return 1;
}
