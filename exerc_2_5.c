#include <stdlib.h>
/* ====================================
File name: exerc_2_5.c 
Date: 2018-01-28
Group Number:3
Members that contributed:
Martin Chukaleski
Samer Daknache
Yazan Alsahhar
Demonstration code: [<40735>] 
====================================== */

#include <stdio.h>
#include <time.h>
#include <memory.h>
#include <string.h>

#define MAX 100
#define MAXNUMBER 20

//40735

// ------ Function declaration ----------
void create_random(int *tab); // Use pointer to fill the table
void count_frequency(int *tab, int *freq); // Use pointer
void draw_histogram(int *freq); // Use pointer

// -------------- Functions  ---------------//

void create_random(int *tab) {
    srand(time(NULL)); //used for generating RANDOM numbers according to the time
    for (int i = 0; i < MAX; i++) {
        *(tab + i) = (rand() % (MAXNUMBER + 1)); //random numbers from 0 to 20
    }
}

void helper(int *freq, int *freQ) {
    int track = 0;
    for (int i = 0; i < MAX; i++) {
        if (*(freq + i) != 0) {
            *(freQ + track) = *(freq + i);
            track++;
        }
    }
    /*printf("HELPER FREQ\n");
    for(int i =0;i<21;i++){
        printf("%d,",freQ[i]);
    }
    printf("\n");
     */

}

void count_frequency(int *tab, int *freq) {
    for (int i = 0; i < MAX; i++) {

        int count = 1;
        for (int j = i + 1; j <= MAX - 1; j++) {
            /* If duplicate element is found increase counter */
            if (*(tab + i) == *(tab + j)) {
                count++;
                /* Replace it with 0 so that we know we have counted that element */
                *(tab + j) = -1;
            }
        }
        /* Insert the count of the specific element in the freq array on index where the
         * tab[i] was spotted so later it can be used to retrieve the count for every element
         */
        if (*(tab + i) != -1) {
            *(freq + i) = count;
        }
    }
}

void sort(int *tab) { //sorting method
    int temp;
    for (int i = 0; i < MAX; i++) {
        for (int j = i + 1; j < MAX; j++) {
            if (*(tab + j) < *(tab + i)) {
                //swapping elements
                temp = *(tab + i);
                *(tab + i) = *(tab + j);
                *(tab + j) = temp;
            }
        }
    }

}


void draw_histogram(int *freq) {
    char Xs[100];

    for (int i = 0; i <= MAXNUMBER; i++) {

        int count = *(freq + i);
        memset(Xs, 0, sizeof(Xs)); //clear the array from all previous Xs

        for (int i = 0; i < count; i++) {
            //depending on the count for every element append X's
            strcat(Xs, "X");
        }
        printf("%d: %s\n", i, Xs);
    }
}

int main(int argc, char **argv) {
    int table[MAX];
    int frequency[MAX] = {0};
    int freQ[20];

    // table with 100 random integers from 0 to 20
    create_random(table);

    printf("\n-------------------RANDOM ARRAY---------------------\n");
    for (int i = 0; i < MAX; i++) {
        if (i + 1 == MAX) {
            printf("%d.", table[i]);
        } else {
            printf("%d,", table[i]);
        }

    }

    printf("\n\n-------------------SORTED---------------------\n");

    /*
     * Sorting and displaying the array
     */
    sort(table);
    for (int i = 0; i < MAX; i++) {
        if (i + 1 == MAX) {
            printf("%d.", table[i]);
        } else {
            printf("%d,", table[i]);
        }

    }
    printf("\n\n");

    /*
     * Count duplicates and draw the histogram
     */
    printf("-------------------HISTOGRAM---------------------\n");
    count_frequency(table, frequency);

    /*
    printf("\n");
    for (int i = 0; i < MAX; i++) {
        printf("%d,", frequency[i]);
    }*/
    printf("\n");

    helper(frequency, freQ);

    printf("\n");
    draw_histogram(freQ);

    return 0;
}
