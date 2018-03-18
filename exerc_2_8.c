/* ====================================
File name: exerc_2_8.c 
Date: 2018-01-28
Group Number:3
Members that contributed:
Martin Chukaleski
Samer Daknache
Yazan Alsahhar
Demonstration code: [<47954>] 
====================================== */
 
 //47954

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>


#define MAX_COINS 13

const int HUMAN = 0;
const int COMPUTER = 1;

/* ------------- IO --------------- */

/*
 * human_choice
 * Get human choce as an int from stdin.
 * Clears stdin.
 * in: pile
 * out: int-value in range 1-3 (and also less than pile)
 */
int human_choice(int pile);

/*
 * write_winner
 * Write winner as a string on stdout.
 * in: Values HUMAN or COMPUTER.
 * out:
 */
void write_winner(int player);

/*
 * play_again
 * Ask human if he/she wants to play
 * another round. If 'n' or 'N' selected
 * (single char) return false else true.
 * Clears stdin.
 * in:
 * out: true or false
 */
int play_again();

/* ---------------- Logic ----------------*/

/*
 * computer_choice
 * Get computers choice (including some AI,
 * if 4 coins or less left, function makes a
 * smart choice else random).
 * in: pile
 * out: int-value in range 1-3 (and also less than pile)
 */
int computer_choice(int pile);


/*
 * toggle
 * Switches player, if HUMAN in COMPUTER out
 * etc.
 * in:  actual player
 * out: next player
 */
int toggle(int player);

/* --------------------- Utilities -------------*/
void clear_stdin();

/***************************************************
 *
 *    MAIN
 *
 ***************************************************/
int main() {
    int pile,            /* This is how many coins we have */
            player,            /* Who is playing? */
            n_coins,            /* Number of coins taken */
            state = 1;   /*do we wanna play again */

    srand(time(0));        /* Setup random */

    printf("Valkommen till NIM by Group 3\n");


    pile = MAX_COINS;        /* Set start values (= init) */
    player = HUMAN;

    /*
     *  Program main loop
     */
    while (state) {

        printf("There are %d  coins left !\n", pile);
        if (player == HUMAN) {
            n_coins = human_choice(pile);
        } else {
            n_coins = computer_choice(pile);
            printf("- I took  %d\n", n_coins);
        }
        pile -= n_coins;

        if (pile <= 1) {
            write_winner(player);
            pile = MAX_COINS;
            player = HUMAN;
            state = play_again();
            if (state == 0) {
                break;
            }
        } else {
            player = toggle(player);
        }
    }
    /*
     * end main loop
     */

    printf("Termination\n");

    return 0;
}

/******************************************************
 *
 *  DEFINITIONS
 *
 ******************************************************/


void clear_stdin() {
    while (getchar() != '\n') { ;
    }
}

int human_choice(int pile) {

    int hmn_choice, flag = 1;
    while (flag) {
        printf("Enter a number from 1 to 3 !!!\n");
        scanf("%d", &hmn_choice);
        if (hmn_choice <= pile && (hmn_choice > 0 && hmn_choice < 4)) {
            flag = 0;
        } else {
            continue;
        }
    }
    return hmn_choice;
}

int computer_choice(int pile) {

    int random_choice = (rand() % 3) + 1; // from 1 - 3
    if (pile < 4) {
        if (pile == 3) {
            return (rand() % 2) + 1; // from 1 - 2
        }
        if (pile == 2) {
            return 1;
        }
    } else {
        return random_choice;
    }
}

void write_winner(int player) {

    if (player == COMPUTER)
        printf("Computer WON !!!\n");
    else
        printf("Human WON !!!\n");

}

int play_again() {

    char answer;
    printf("You wanna play again ? \n Enter 'Y' to play again or 'X' to exit the app\n");
    clear_stdin();
    while (answer = getchar()) {
        printf("Please choose between Y or X !!! \n");
        if (answer == 'Y' || answer == 'y') {
            return 1;
        } else if (answer == 'X' || answer == 'x') {
            return 0;
        } else {
            play_again();
        }
    }
}

int toggle(int player) {

    if (player == COMPUTER)
        return HUMAN;
    else
        return COMPUTER;

}
