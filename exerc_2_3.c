/* ====================================
File name: exerc_2_3.c 
Date: 2018-01-28
Group Number:3
Members that contributed:
Martin Chukaleski
Samer Daknache
Yazan Alsahhar
Demonstration code: [<44094>] 
====================================== */

/* 44094 */

#include <stdio.h>
#include <mem.h>

int main(int argc, char *argv[]) {

    char *str1 = argv[1], *str2 = argv[2];
    int i = 0, flag = 0;

    printf("str1: %s\n", str1);

    printf("str2: %s\n", str2);

    int str1length = 0;
    int str2length = 0;

    //lenth of the strings
    str1length = strlen(str1);
    str2length = strlen(str2);

    //our function to check the strings
    if (str1length > str2length || str1length < str2length) {
        printf("Our result: The strings are different!\n");
    } else {
        while (str1[i] != '\0') {
            if ((str1[i] != str2[i]) && flag == 0) {
                flag = 1;
                break;
            }
            i++;
        }

        if (flag != 1) {
            printf("developed func - strings are equal\n");
        } else {
            printf("developed func - The strings are different\n");
        }
    }


    if (!strcmp(str1, str2)) {
        printf("strcmp - strings are equal\n");
    } else {
        printf("strcmp - strings are different\n");
    }


    return 0;
}
