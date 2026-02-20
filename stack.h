#ifndef STACK_H
#define STACK_H
#include <stdlib.h>

typedef struct node{
    void *data;
    struct node *next;
}Node;

typedef struct{
    Node *top;
    int size;
}Stack;

//node creation
Node *createNode(void*);

//stack operations
void push(Stack*,void*);
void* pop(Stack*);
void* peek(Stack* list);

#endif