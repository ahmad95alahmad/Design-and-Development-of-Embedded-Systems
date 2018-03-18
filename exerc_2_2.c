/* ====================================
File name: exerc_2_2.c 
Date: 2018-01-28
Group Number:3
Members that contributed:
Martin Chukaleski
Samer Daknache
Yazan Alsahhar
Demonstration code: [<46009>] 
====================================== */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50

//46009

void main()
{
    int i,j,numbers[MAX];
    
    srand(time(NULL));
    /*filling with random numbers from 1 to 100*/
    for(i=0;i<=MAX;i++){
        numbers[i] = ( rand() % 100 ) + 1;
    }
    /*********************************************************************/
    printf("The value of the label array (address) is:%d\n",&numbers);
    printf("First integer in the array is (array[0]) :%d\n",numbers[0]);
    printf("The size of an integer (number of bytes) is :%d\n", sizeof(numbers[0]));
    printf("The size of the whole array is :%d\n", sizeof(numbers));

    /*********************************************************************/
    for(j=0;j<=MAX;j++){
        printf("array[%d] = %d \t|| double value = %d \n",j,*(numbers + j),*(numbers + j)*2);
    }


}

