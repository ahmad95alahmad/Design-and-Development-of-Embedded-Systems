/* ====================================
File name: exerc_2_7.c 
Date: 2018-01-28
Group Number:3
Members that contributed:
Martin Chukaleski
Samer Daknache
Yazan Alsahhar
Demonstration code: [<46214>] 
====================================== */

#include <stdlib.h>
#include <stdio.h>
#define MAX 11

//46214

/*
 * read the personal number in string format
 */
void readPersnr(char *person){
    fgets(person, MAX, stdin);
}

/*
 * Luhn algorithm
 */
long controlDigit(const char* persnr) {
    int i,sum = 0,flag = 1,temp=0,controlDigit;
    for(i = 0;i<9;i++){
        if (flag){
            temp = (persnr[i]-'0') * 2;
            if(temp > 9){
                sum += temp%10 + temp/10;
            }else{
                sum += temp;
            }
            flag = 0;
        }else{
            sum += (persnr[i]-'0');
            flag = 1;
        }
    }
    controlDigit = (9 * sum) %10;
    return controlDigit;
}

/*
 *Check if the month is correct
 */
int checkMonth(char *person) {
    char dayString[2];
    int month,i,j=0;
    for (i = 2; i < 4; i ++) {
        dayString[j] = person[i];
        j++;
    }

    month = atoi(dayString);
    if(month>0 && month <13){
        return 1;
    }
    printf("The month you entered is not valid\n");
    return 0;
}

/*
 *Check if day is correct
 */
int checkDay(char *person) {
    char dayString[2];
    int day,i,j=0;
    for (i = 4; i < 6; i++) {
        dayString[j] = person[i];
        j++;
    }

    day = atoi(dayString);
    if(day>0 && day <32){
        return 1;
    }else{
        printf("the day you entered is not valid\n");
    }
    return 0;
}
/*--------------------------------------------------------------------*/

int main() {
    char personr[MAX];
    char *pPerson = personr;
    int controlNum,state=1;

    while(1) {
        if(state){
            printf("Enter a personal number:\n");
            state = 0;
        }else{
            printf("Enter a personal number or press 'q' to end the program:\n");
        }

        //input of personal number
        readPersnr(pPerson);
        if(personr[0] == 'q'){
            break;
        }

        controlNum = controlDigit(pPerson);
        printf("Control digit:%d\n", controlNum);
        printf("Personal number last digit:%c\n", *(pPerson + 9));

        //check if month and day are correct
        if(checkMonth(pPerson) && checkDay(pPerson)) {
            //check if the controlDigit is equal with the last digit of the personal number
            if (controlNum == (personr[9] - '0')) {
                printf("This is a valid personal number\n");
            }else{
                printf("This is not a valid personal number\n");
            }
        }

        fseek(stdin,0,SEEK_END);
        fflush(stdin);

    }

    return 0;
}
