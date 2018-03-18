#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
/*====================================
File name: code.c (or cpp)
Date: 2018-02-12
Group Number: 3
Members that contributed: Samer Daknache, Martin Chukaleski, Yazan Alsahhar
Demonstration code: [<44331>]
======================================*/

//44331

struct {
    unsigned char engine_on : 1;
    unsigned char gear_pos : 3;
    unsigned char key_pos : 2;
    unsigned char brake1 : 1;
    unsigned char brake2 : 1;
} s;


int main(int argc, char **argv) {

    if (argc != 6 || isdigit((*argv[1] - '0')) || isdigit((*argv[2] - '0')) || isdigit((*argv[3] - '0'))
        || isdigit((*argv[4] - '0')) || isdigit((*argv[5] - '0'))) {
	
	printf("ARGC VAL :%d\n",argc);
        printf("INPUT ERROR IN ARGUMENTS\n");
        exit(0);

    }
     
    if (!(((*argv[1] - '0') >= 0 && (*argv[1] - '0') < 2) && ((*argv[2] - '0') >=0 && (*argv[1] - '0') < 5) &&
        ((*argv[3] - '0') >= 0 && (*argv[3] - '0') < 3) &&
        ((*argv[4] - '0') >= 0 && (*argv[4] - '0') < 2) && ((*argv[5] - '0') >= 0 && (*argv[5] - '0') < 2))) {
        printf("INPUT ERROR\n");
        exit(0);
    }

    s.engine_on = (unsigned char) (*argv[1] - '0');
    s.gear_pos = (unsigned char) (*argv[2] - '0');
    s.key_pos = (unsigned char) (*argv[3] - '0');
    s.brake1 = (unsigned char) (*argv[4] - '0');
    s.brake2 = (unsigned char) (*argv[5] - '0');

    unsigned char i = 0;

    i |= s.brake2;
    i |= (s.brake1 << 1);
    i |= (s.key_pos << 2);
    i |= (s.gear_pos << 4);
    i |= (s.engine_on << 7);

    printf("HEX VALUE : %02x\n", i);

    return 0;
}
