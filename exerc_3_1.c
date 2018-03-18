/*====================================
File name: exerc_3_1.c (or cpp)
Date: 2018-02-06
Group Number: 3
Members that contributed: Samer Daknache, Martin Chukaleski, Yazan Alsahhar
Demonstration code: [<40444>]
======================================*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum DIRECTION { N, E, S, W };

typedef struct {
    int xpos;
    int ypos;
    enum DIRECTION dir;
}ROBOT;

void move(ROBOT *robot);
void turn(ROBOT *robot);

int main() {
    ROBOT rob;


    char option[20];
    rob.dir = N;

    do {
        printf("Input robots starting X position (Range 0-99)?\n");
        scanf("%d", &rob.xpos);
    } while (rob.xpos < 0 || rob.xpos > 99);
    do {
        printf("Input robots starting Y position (Range 0-99)?\n");
        scanf("%d", &rob.ypos);
    } while (rob.ypos < 0 || rob.ypos > 99);

    while (option[0]!='p') {


        printf("Press 'm' to MOVE, 't' to TURN or 'p' to exit the app\n");
        printf("m means  move a step in current direction and t means turn of direction \n");
        scanf("%s", &option);

        for (int i = 0; i < strlen(option); i++) {
            if (option[i] == 'm') {
                move(&rob);
                continue;
            }
            else if (option[i] == 't') {
                turn(&rob);
                continue;
            }
            else if (option[i] == 'p') {
                exit(0);
            }
            else {
                printf("INPUT ERROR\n");
                break;
            }
        }

        printf("Current posiotion: X: %d, Y: %d, Direction: ", rob.xpos, rob.ypos);

        switch (rob.dir) {
            case N:
                printf("North\n\n");
                break;
            case E:
                printf("East\n\n");
                break;
            case S:
                printf("South\n\n");
                break;
            case W:
                printf("West\n\n");
                break;
        }

        memset(option, 0, 20);
    }
}

void move(ROBOT* rob) {
    switch (rob->dir) {
        case N:
            if(rob->ypos < 99)
                rob->ypos++;
            break;
        case E:
            if(rob->xpos < 99)
                rob->xpos++;
            break;
        case S:
            if(rob->ypos > 0)
                rob->ypos--;
            break;
        case W:
            if(rob->xpos > 0)
                rob->xpos--;
            break;
    }
}

void turn(ROBOT* rob) {
    switch (rob->dir) {
        case N:
            rob->dir = E;
            break;
        case E:
            rob->dir = S;
            break;
        case S:
            rob->dir = W;
            break;
        case W:
            rob->dir = N;
            break;
    }
}

