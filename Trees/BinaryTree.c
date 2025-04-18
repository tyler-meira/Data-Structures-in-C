#include <stdio.h>
#include <stdlib.h>


typedef struct treeNode {
    int value; 
    struct treeNode *left;
    struct treeNode *right;
}treeNode;

treeNode* startTree(int value){

    treeNode *newNode = (treeNode*) malloc(sizeof(treeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}


treeNode* insertNode(treeNode *headNode, int value){

    if(headNode == NULL){
        return startTree(value);
    }

    if(headNode->value == value){
        return headNode;
    }

    if(headNode->value > value){
        headNode->left = insertNode(headNode->left,value);
    }else{
        headNode->right = insertNode(headNode->right,value);
    }

    return headNode;

}

void printTree(treeNode *node){
    if(node != NULL){
        printTree(node->left);
        printf("%d ", node->value);
        printTree(node->right);
    }
}


int main(void){

    treeNode *headNode = startTree(80);

    headNode = insertNode(headNode, 30);
    headNode = insertNode(headNode, 20);

    printTree(headNode);


    printf("Success");
    return 0;
}