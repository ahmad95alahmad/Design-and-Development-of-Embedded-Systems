/* ====================================
File name: exerc_2_4.c 
Date: 2018-01-28
Group Number:3
Members that contributed:
Martin Chukaleski
Samer Daknache
Yazan Alsahhar
Demonstration code: [<47200>] 
====================================== */

#include <stdio.h>
#define MAX 25
//47200

void main()
{
    char string[MAX], reverse_string[MAX];
    int i, length = 0, flag = 0;

    printf("Enter a string \n");
    gets(string);
    /*  keep going through each character of the string till its end */
    for (i = 0; string[i] != '\0'; i++)
    {
        length++;
    }
    printf("The length of the string '%s' = %d\n", string, length);
    for (i = length - 1; i >= 0 ; i--)
    {
        reverse_string[length - i - 1] = string[i];
    }
    /*  Check if the string is a Palindrome */

    for (flag = 1, i = 0; i < length ; i++)
    {	
		// checking if they are different
        if (reverse_string[i] != string[i])
            flag = 0;
			break;
    }
    if (flag == 1)
        printf ("%s is a palindrome \n", string);
    else
        printf("%s is not a palindrome \n", string);
}