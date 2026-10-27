
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define DIPENDENTI 500

typedef enum { SOPRA, SOTTO } status;

typedef struct {
    int ID;
    status soglia;
} lavoratore;

int main(void) {
    int days[DIPENDENTI];
    lavoratore output_check[DIPENDENTI];
    int counter = 0;
    int i, max_days = 221, min_days = 175;
    int tolleranza = 20;

    // Inizializzare days
    srand(time(NULL));

    for (i = 0; i < DIPENDENTI; i++) {
        days[i] = min_days - tolleranza
                  + rand() % (max_days - min_days
                  + 2 * tolleranza + 1);
    }

    for (i = 0; i < DIPENDENTI; i++) {
        // worked more than the max
        if (days[i] > max_days) {
            output_check[counter].ID = i;
            output_check[counter].soglia = SOPRA;
            counter++;
        }
        // worked less than the min
        else if (days[i] < min_days) {
            output_check[counter].ID = i;
            output_check[counter].soglia = SOTTO;
            counter++;
        }
    }

    printf("anormal workers are in total: %d\n", counter);
    printf("their datas are:\n");

    for (i = 0; i < counter; i++) {
        printf("ID: %d - ", output_check[i].ID);

        if (output_check[i].soglia == SOPRA) {
            printf("overworker\n");
        }
        else {
            printf("underworker\n");
        }
    }

    return 0;
}

