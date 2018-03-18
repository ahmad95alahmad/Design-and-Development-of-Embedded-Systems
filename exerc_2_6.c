/* ====================================
File name: exerc_2_6.c 
Date: 2018-01-28
Group Number:3
Members that contributed:
Martin Chukaleski
Samer Daknache
Yazan Alsahhar
Demonstration code: [<42406>] 
====================================== */

#include <stdio.h>

#define MAX 10
//42406

int main() {
    int list[MAX];

    initQue(list,5);
    printList(list,5);
    int res = input(list,1,5);
    printf("\n %d \n",res);
    input(list,2,5);
    input(list,3,5);
    printList(list,5);
    output(list,5);
    printList(list,5);

    return 0;
}
void initQue (int list[], int max ){
    //fill the array with max -1's
    for(int i=0;i<max;i++){
        list[i] = -1;
    }
}
int input(int list[], int number, int max){
    int i,result = 0;
    //check if there is free space and add the number if there is
    for (i=0; i < max; i++)
    {
        if(list[i] == -1 && result == 0)
        {
            list[i] = number;
            result = 1;
        }
    }
    return result;
}
int output( int list[], int max){
    //if the first element is -1 that means the list is empty
    if(list[0]==-1){
        return 0;
    }else{
        //save the first element so we can return it
        int res = list[1];
        //shift all other elements to the left
        for(int i=0;i<max-1;i++){
            list[i] = list[i+1];
        }
        //add a -1 on the last place
        list[max-1] = -1;
        return res;
    }
}
//used to print the list
void printList(int list[],int max){
    for(int i=0;i<max;i++){
        printf("%d ",list[i]);
    }
    printf("\n");
}