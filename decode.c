#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/*====================================
File name: decode.c (or cpp)
Date: 2018-02-12
Group Number: 3
Members that contributed: Samer Daknache, Martin Chukaleski, Yazan Alsahhar
Demonstration code: [<40680>]
======================================*/
//40680

struct {
    unsigned char engine_on : 1;
    unsigned char gear_pos : 3;
    unsigned char key_pos : 2;
    unsigned char brake1 : 1;
    unsigned char brake2 : 1;
} s;


int main(int argc, char **argv ) {
    
    if(argc < 2 || argc > 2 ||(strlen(argv[1])>2)){
        printf("Error");
        exit(2);
    }
    
    unsigned int k=0;
	for(int i = 0;i<2;i++){
		if(*(argv[1]+i) <= 0x39 && *(argv[1]+i) >= 0x30){
			k += *(argv[1]+i) - '0';
		}else if(*(argv[1]+i) <= 0x46 && *(argv[1]+i) >= 0x41){
			k += *(argv[1]+i) - 'A'+10;
		}else if(*(argv[1]+i) <= 0x66 && *(argv[1]+i) >= 0x61){
			k += *(argv[1]+i) - 'a'+10;
		}
		if(!i){
			k<<=4;
		}
		
	}
	
   
    
    int flag = 0;
    s.engine_on = k>>7;
    
    s.gear_pos = k>>4;
    if(s.gear_pos > 3){
        printf("Error too big value");
        exit(1);
    }
    s.key_pos = k>>2;
    if(s.key_pos > 2){
        printf("Error too big value");
        exit(1);
    }
    s.brake1 = k>>1;
    
    s.brake2 = k>>0;
    
     
    printf("\nName   -----   Value \n");
    printf("---------------------");
    printf("\nengine_on is\t\t%d\n", s.engine_on);
    printf("gear_pos is\t\t%d\n", s.gear_pos);
    printf("key_pos is\t\t%d\n", s.key_pos);
    printf("brake1 is\t\t%d\n", s.brake1);
    printf("brake2 is\t\t%d\n", s.brake2);
    return 0;
}
