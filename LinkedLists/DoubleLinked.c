#include <stdio.h>
#include <stdlib.h>

/* 
 *Double Linked List
*/

typedef struct node{

  int value;
  struct node *next;
  struct node *last;
}doubleLinked;

//Function Prototypes
void printNodes(doubleLinked *head);

int main(void){
  
  doubleLinked *head;

  //Allocate Memory for the node
  head = (doubleLinked*) malloc(sizeof(doubleLinked));
  
  //Initalizing head node
  //For the purpose of learning the data strucutre the 
  //value will just act like a index.
  head->next = NULL;
  head->last = NULL;
  head->value = 0;

  printNodes(head);

  return 0;
}

void printNodes(doubleLinked *head){

  doubleLinked *current = head;

  while(current != NULL){
    printf("%d",current->value);
    current = current->next;
  }
}


