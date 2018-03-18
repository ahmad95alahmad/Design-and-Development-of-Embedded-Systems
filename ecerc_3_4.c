/*====================================
File name: exerc_3_4.c (or cpp)
Date: 2018-02-09
Group Number: 3
Members that contributed: Samer Daknache, Martin Chukaleski, Yazan Alsahhar
Demonstration code: 43447
======================================*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h> 
// -----Typedefs -------
typedef struct
{
    char firstname[20];
    char famnamne[20];
    char pers_number[13];
} PERSON;
FILE *fileptr;

// Function declaration (to be extend)
PERSON input_record(PERSON person, char *firstName, char *lastName, char *personalNumber); // Reads in a person record.
void write_new_file( PERSON *inrecord); //Creats a file and write a first record
void print_file(void); // print out all persons in the file
void search_by_firstname( char *name);// print out person if in list
void append_file(PERSON *inrecord);// appends a new person to the file
void flushBuffer(void);



void flushBuffer()
{
    fseek(stdin, 0, SEEK_END); //flush the input
    fflush(stdin);
}



PERSON input_record(PERSON person, char *firstName, char *lastName, char *personalNumber)
{
    strcpy(person.firstname, firstName);
    strcpy(person.famnamne, lastName);
    strcpy(person.pers_number, personalNumber);

    return person;
}

void print_file()
{
    int i = 0;
    FILE *fileptr;
    PERSON post;
    if ((fileptr = fopen("file.dat", "rb")) == NULL)
    {
        printf("Can't open file. \n");
        exit(1);
    }
    while (!feof(fileptr))
    {
        if (fread(&post, sizeof(PERSON), 1, fileptr))
        {
            printf("\n PERSON #%d: Name: %s Last Name: %s personal number %s\n", i, post.firstname, post.famnamne,
                   post.pers_number);
            i++;
        }
    }
    fclose(fileptr);
}

void write_new_file(PERSON *inrecord)
{
    FILE *fileptr;

    if ((fileptr = fopen("file.dat", "wb")) == NULL)
    {
        printf("Can't create new file \n");
        exit(1);
    }
    else
    {
        fwrite(inrecord, sizeof(PERSON), 1, fileptr);
        fclose(fileptr);
        printf("File Created\n");
    }


}

void search_by_firstname(char *name)
{

    char *searchf;
    searchf = name;
    PERSON *person = (PERSON *)malloc(sizeof(PERSON));



    if ((fileptr = fopen("file.dat", "rb")) == NULL)
    {
        printf("\n Can't open file. \n");
        exit(1);
    }

    searchf[strlen(searchf) - 1] = '\0';

    while(!feof(fileptr))
    {
        if(fread(person, sizeof(PERSON), 1, fileptr))
        {
            if((strcmp(person -> firstname, searchf)) == 0 || (strcmp(person -> famnamne, searchf))== 0)
            {
                printf("\n Name: %s, Last Name: %s, personal number: %s \n", person -> firstname, person -> famnamne,
                       person -> pers_number);
            }


        }
    }

printf("\n There is no match! please try again! \n");
    fclose(fileptr);
    free(person);
}


void append_file(PERSON *inrecord)
{
    FILE *fileptr;

    if ((fileptr = fopen("file.dat", "ab")) == NULL)
    {
        printf("Can't  open file. \n");
        exit(1);
    }

    fwrite(inrecord, sizeof(PERSON), 1, fileptr);
    fclose(fileptr);
    flushBuffer();
}

int main(void)
{

    PERSON person;
    PERSON tmp;
    int c;
    char fname[20], lname[20], pNumber[13];

    do
    {
        printf("\n1. Create a new and delete the old file \n");
        printf("2. Add a new person to the file \n");
        printf("3. Search for a person in the file \n");
        printf("4. Print out all in the file \n");
        printf("5. Exit the program \n");

        scanf(" %d", &c);

        switch(c)
        {

        case 1:
            flushBuffer();
            person = input_record(person, "Martin", "Chukaleski", "199510255335");
            write_new_file(&person);
            break;

        case 2:
            flushBuffer();
            printf("Please enter the first name: ");
            scanf(" %20s", fname);
            printf("Please enter the last name: ");
            scanf(" %20s", lname);
            printf("Please enter the personal number: ");
            scanf(" %13s", pNumber);
            tmp = input_record(tmp, fname, lname, pNumber);
            printf("\n New member has been added!\n");
            append_file(&tmp);
            break;

        case 3:
            flushBuffer();
            printf("\n Please enter a first/last name to be searched: ");

            char search[20];
            fgets(search, 20, stdin);
            search_by_firstname(search);
            break;

        case 4:
            flushBuffer();
            print_file();
            break;

        case 5:
            exit(1);
            break;

        default:
            printf("\n Wrong input! please try again! \n");
            break;

        }


    }
    while(c != 5);
}



