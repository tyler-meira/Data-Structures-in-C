#include <stdio.h>
#include <stdlib.h>

/*

To access members of a struct use the dot operator,
to access members of a strcut through a pointer use the arrow operator.

*/

//Linked List Struct
    typedef struct node{
        int value;
        struct node * next;
    }node_t;


//Function Prototypes
void print_list(node_t * head);
void add(node_t * head, int val);

int main(void){

    //Creates pointers for the node struct
    node_t* head;
    node_t* one;

    //Assigns memory for those nodes, use size of function since it returns the amount of bytes something is.
    one = (node_t*) malloc(sizeof(node_t));
    head = (node_t*) malloc(sizeof(node_t));

    //Initialize head node, with arrow operator since head is a pointer.
    head->value = 1;
    head->next = NULL;

    
    //Create the next node after head, by assigning the next variable to a memory location of the next structure.
    head->next = (node_t*) malloc(sizeof(node_t));
    head->next->value = 2;

    //sets the new node's next value to null
    head->next->next = NULL;

    print_list(head);

    add(head, 5);
    add(head, 6);

    print_list(head);

    /*
    //updates the current postion of our main pointer to the new pointer just created.
    head = head->next;
    */

}

void print_list(node_t* head){
    node_t* current = head;

    while(current->next != NULL){
        //Prints the value at current postion
        printf("%d\n",current->value);
        //sets the current pointer to the next item in the linked list
        current = current->next;

    }

}

void add(node_t * head, int val){
    node_t* current = head;

    //if current is not at the end of the list, parse through till you find the last element.
    while(current->next != NULL){
        current = current->next;
    }
    //Creates and adds the new node.
    current->next = (node_t*) malloc(sizeof(node_t));
    current->next->value = val;
    current->next->next = NULL;
}

//void pop(node_t** head)