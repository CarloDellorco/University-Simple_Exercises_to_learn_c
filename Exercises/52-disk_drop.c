#include <stdio.h>
#include <stdlib.h>

#define MOSSE 5

typedef struct {
    int d;
    int p;
} foro;


typedef struct {
    int numero_fori;
    foro *superficie_forata;
} trappolino;



trappolino load_mytrappolino(FILE *fp);
int dindon(trappolino mytr);



int main(void) {
    FILE *fp;
    trappolino mytrappolino;
    int count;

    fp = fopen("C:/Users/carlo/CLionProjects/Simple_c_exercises/Files/trap.txt", "r");

    if (fp == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    mytrappolino = load_mytrappolino(fp);
    fclose(fp);

    if (mytrappolino.numero_fori <= 0 || mytrappolino.superficie_forata == NULL) {
        printf("Error loading game data.\n");
        return 1;
    }

    count = dindon(mytrappolino);

    if (count > 0) {
        printf("You won in %d moves!\n", count);
    } else if (count == 0) {
        printf("Game over! You lost.\n");
    } else {
        printf("You gave up! See you next time.\n");
    }
    free(mytrappolino.superficie_forata);
    return 0;
}



trappolino load_mytrappolino(FILE *fp) {
    trappolino mytr;
    int i;
    mytr.numero_fori = 0;
    mytr.superficie_forata = NULL;

    if (fscanf(fp, "%d", &mytr.numero_fori) != 1 || mytr.numero_fori <= 0) {
        mytr.numero_fori = 0;
        return mytr;
    }

    mytr.superficie_forata = malloc(mytr.numero_fori * sizeof(foro));

    if (mytr.superficie_forata == NULL) {
        mytr.numero_fori = 0;
        return mytr;
    }

    for (i = 0; i < mytr.numero_fori; i++) {
        if (fscanf(fp, "%d %d",
                   &mytr.superficie_forata[i].d,
                   &mytr.superficie_forata[i].p) != 2) {
            free(mytr.superficie_forata);
            mytr.superficie_forata = NULL;
            mytr.numero_fori = 0;
            return mytr;
        }
    }
    return mytr;
}



int dindon(trappolino mytr) {
    int miarrendo = 0;
    int mosse = MOSSE;
    int diametro;
    int i, pluf;
    int count = 0;

    printf("Welcome to Disc Drop!\n");
    while (!miarrendo && mosse > 0) {
        printf("You have %d moves left.\n", mosse);
        printf("Enter the diameter of the disk you want to throw:\n");

        if (scanf("%d", &diametro) != 1 || diametro <= 0) {
            printf("Invalid diameter.\n");
            return -1;
        }

        i = 0;
        pluf = 0;

        while (i < mytr.numero_fori && !pluf) {
            if (diametro <= mytr.superficie_forata[i].d &&
                mytr.superficie_forata[i].p > 0) {
                mytr.superficie_forata[i].p--;
                pluf = 1;
            }
            i++;
        }
        if (!pluf) {
            return count;
        }

        printf("The disk fell into a hole!\n");
        printf("Do you want to give up? (0 = no, 1 = yes)\n");

        if (scanf("%d", &miarrendo) != 1 || (miarrendo != 0 && miarrendo != 1)) {
            return -1;
        }
        count++;
        mosse--;
    }
    if (miarrendo) {
        return -1;
    }
    return 0;
}
