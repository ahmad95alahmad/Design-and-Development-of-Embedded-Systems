/*====================================
File name: exerc_3_2.c (or cpp)
Date: 2018-02-06
Group Number: 3
Members that contributed: Samer Daknache, Martin Chukaleski, Yazan Alsahhar
Demonstration code: [<47587>]
======================================*/
#include <stdio.h>

#define MAX 10

//47587

int search_number(int number, int tab[], int size);

void sort(int number, int tab[]);

int main() {

    int test[] = {1, 2, 34, 5, 67, 3, 23, 12, 13, 10};
    int num;

    printf("TEST ARRAY ELEMENTS:\n");
    printArray(test, MAX);

    printf("Enter the number you want to get the index for:\n");
    scanf("%d", &num);

    printf("Result for the number : %d\n", search_number(num, test, 10));
    printf("Sorting the array\n");
    sort(MAX, test);
}

int search_number(int number, int tab[], int size) {
    for (int i = 0; i < size; i++) {
        if (tab[i] == number) {
            return i;
        }
    }
    return -1;
}

void sort(int number, int tab[]) {
    int temp, minIndex;

    for (int i = 0; i < number - 1; i++) {
        minIndex = i;
        // find the minimum number
        for (int j = i + 1; j < number; j++) {
            if (tab[j] < tab[minIndex])
                minIndex = j;
        }
        temp = tab[i];
        tab[i] = tab[minIndex];
        tab[minIndex] = temp;
    }
    printArray(tab, MAX);
}

void printArray(int arr[], int length) {
    for (int i = 0; i < length - 1; i++) {
        printf("%d,", arr[i]);
    }
    printf("%d.\n", arr[length - 1]);
}


//47587
