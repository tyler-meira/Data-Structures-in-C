#include <stdio.h>
#include <stdlib.h>

/*
-- Bugs Found --
addEnd Function wont add a second value after adding a value to the linked list.

*/

/*
    ** DISCLAIMER **
Used https://www.learn-c.org/en/Linked_lists to learn linked list's from
*/

//Linked List Struct
    typedef struct node{
        int value;
        struct node * next;
    }node_t;


//Function Prototypes
void print_list(node_t * head);
void addEnd(node_t * head, int val);
void addStart(node_t** head, int val);
int removeStart(node_t ** head);

int main(void){

    //Creates pointers for the node struct
    node_t* head;

    //Assigns memory for those nodes, use size of function since it returns the amount of bytes something is.
    head = (node_t*) malloc(sizeof(node_t));

    //Initialize head node, with arrow operator since head is a pointer.
    head->value = 2;
    head->next = NULL;

    print_list(head);

    addEnd(head, 6);
    addStart(&head, 1);
    addStart(&head, 0);
    
    print_list(head);
    printf("\n");

    removeStart(&head);

    print_list(head);
    

    /* Code Below Was Test Code For the Structure's before implementing the functions */
    
    //Create the next node after head, by assigning the next variable to a memory location of the next structure.
    //head->next = (node_t*) malloc(sizeof(node_t));
    //head->next->value = 2;

    //sets the new node's next value to null
    //head->next->next = NULL;

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

void addEnd(node_t* head, int val) {
    node_t * current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    /* now we can add a new variable */
    current->next = (node_t *) malloc(sizeof(node_t));
    current->next->value = val;
    current->next->next = NULL;
}

void addStart(node_t ** head, int val) {
    node_t * new_node;
    new_node = (node_t *) malloc(sizeof(node_t));

    new_node->value = val;
    new_node->next = *head;
    *head = new_node;
}

int removeStart(node_t ** head) {
    int retval = 1;
    node_t * next_node = NULL;

    if(*head == NULL) {
        return -1;
    }

    next_node = (*head)->next;
    retval = (*head)->value;
    free(*head);
   *head = next_node;

    return retval;
}