#include <stdio.h>
#include <stdlib.h>

/*

To access members of a struct use the dot operator,
to access members of a strcut through a pointer use the arrow operator.

*/

//Linked List Structure
    typedef struct LinkedList{
        int value;
        int *next;
    }linkedlist;

    //Creates the structure object 
    linkedlist one;
    linkedlist two;

int main(void){

    //Creates a ptr that points the structure object
    linkedlist *ptr = &one;
    linkedlist *ptr2 = &two;
    
    ptr->value = 5;

    printf("%d",ptr->value);






}