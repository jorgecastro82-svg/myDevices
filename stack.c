#include "stack.h"

//node opertion
Node *createNode(void* data){
    Node *new = calloc(1,sizeof(Node));
    new->data = data;
    return new;
}

//stack operations
void push(Stack* list,void* data){
    //creation of newNode
    Node *newNode = createNode(data);

    newNode->next = list->top;
    list->top =newNode;
    list->size++;
}       

void* pop(Stack* list){
    if(!list->top)
        return NULL;
    Node *aux = list->top;
    list->top = list->top->next;
    void *data = aux->data;
    free(aux);
    list->size--;
    return data;
}

void* peek(Stack* list){
    if(list->top)
        return list->top->data;
    return NULL;
}
