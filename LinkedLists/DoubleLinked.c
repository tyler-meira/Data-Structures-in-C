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
void addEnd(doubleLinked *head, int value);
void printNodesReverse(doubleLinked *head);

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
  
  addEnd(head, 1);
  addEnd(head, 2);

  printf("Forward Iteration \n");
  printNodes(head);
  printf("\n\n");

  printf("Backwards Iteration \n");
  printNodesReverse(head);

  return 0;
}

void printNodes(doubleLinked *head){

  doubleLinked *current = head;

  while(current != NULL){
    printf("%d, ",current->value);
    current = current->next;
  }
}

void printNodesReverse(doubleLinked *head){

  doubleLinked *current = head;
  
  //Sets our current pointer to last node.
  while(current != NULL){
    current = current->next;
  }

  while(current != NULL){
    printf("%d, ",current->value);
    current = current->last;
  }
}

void addEnd(doubleLinked *head, int value){
  doubleLinked *current = head;
  
  //Parse to the end of linked the linked list.
  while(current->next != NULL){
    current = current->next;
  }

  current->next = (doubleLinked*) malloc(sizeof(doubleLinked));
  current->next->value = value;
  current->next->next = NULL;
  current->next->last = current;

}

