/*====================================
File name: exerc_3_3.c (or cpp)
Date: 2018-02-06
Group Number: 3
Members that contributed: Samer Daknache, Martin Chukaleski, Yazan Alsahhar
Demonstration code: [<42597>]
======================================*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//42597

//#### Konstanter #####
#define MAX 5

// ##### Typedefs ####
typedef struct q{
    int number;
    struct q *next;
    struct q *prev;
} REGTYPE;

// ##### Function declarations #####
REGTYPE* random_list(void);
REGTYPE* add_first(REGTYPE* temp, int data);

//###### Main program #######
int main() {
    int nr=0;

    REGTYPE *akt_post, *head=NULL;
    srand(time(0));
    head=random_list();
    akt_post=head;
    while(akt_post!=NULL){
        printf("LinkedList element number %d : %d\n" , nr++, akt_post->number);
        akt_post=akt_post->next;
    }
    nr=0;

    //input from user for a new int
    int user_input;
    printf("Enter an new element for the new top:\n");
    scanf("%d", &user_input);

    //creating a  new element on the list
    akt_post = add_first(head, user_input);
    printf("New list after adding the new element:\n");
    while(akt_post!=NULL){
        printf("LinkedList element number %d : %d\n" , nr++, akt_post->number);
        akt_post=akt_post->next;
    }

    // --- Free of allocated memory ---
    while((akt_post=head)!=NULL){
        head=akt_post->next;
        free(akt_post);
    }

    return 0;
}

// ==== End of main ======================================
REGTYPE* random_list(void){
    int nr = rand() % (100), i=0;

    REGTYPE *top, *old, *item;

    top = (REGTYPE *) malloc( sizeof(REGTYPE) );
    top->number = nr;
    top->prev = NULL;
    old = (REGTYPE *) malloc( sizeof(REGTYPE) );
    old->prev = top;


    while(i<MAX-1){
        nr = rand() % (100);
        item = (REGTYPE *) malloc( sizeof(REGTYPE) );
        if(i==0){
            top->next = item;
        }
        old->next = item;
        item->number = nr;
        item->prev = old;
        old = item;
        old->next=NULL;
        i++;
    }
    return(top);
}

//==========================================================
REGTYPE* add_first(REGTYPE* temp, int data){
// Adds a record first in the list and sets the field number to data

    REGTYPE *new_first_node;
    new_first_node = (REGTYPE *) malloc( sizeof(REGTYPE) );
    new_first_node->number = data;
    new_first_node->prev = NULL;
    new_first_node->next = NULL;

    if(temp == NULL) {
        return new_first_node;
    }

    temp->prev = new_first_node;
    new_first_node->next = temp;
    return new_first_node;
}
