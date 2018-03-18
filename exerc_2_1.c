/* ====================================
File name: exerc_2_1.c 
Date: 2018-01-28
Group Number:3
Members that contributed:
Martin Chukaleski
Samer Daknache
Yazan Alsahhar
Demonstration code: [<41181>] 
====================================== */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//41181

void copyString(char copiedString[], char anyString[]);

int main()
{

    // Declare two arrays of characters
    char anyString[20], copiedString[20], copyString2[20];
	int i, ch;

    printf("Please enter a string: \n");

    // Read a string from the keyboard with max 20 characters
	for (i = 0; (i < (sizeof(anyString)-1) && ((ch = fgetc(stdin)) != EOF) && (ch != '\n')); i++){
      anyString[i] = ch;
	}
	
    //scanf("%20s", anyString);

    // Copy a string to another using strcpy() function which belongs to C programming
    strcpy(copiedString, anyString);
	copyString(copyString2, anyString);

    // Print out the copied string
    printf("The copied string is: %s ", copiedString);
	  // Print out the copied string our method
	 printf("\n");
    printf("The copied string with our method is: %s ", copyString2);
	system("pause");

    return 0;
}
void copyString(char copiedString[], char anyString[]) {
   int count = 0;

   // \0 refers to the end of the string
   while (anyString[count] != '\0') {
      copiedString[count] = anyString[count];
      count++;
   }
   copiedString[count] = '\0';
}

