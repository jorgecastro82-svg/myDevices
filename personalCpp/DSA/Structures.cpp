#include "Structures.h"
#include <iostream>

Node::Node(int data)
    :data(data),next(nullptr){}

Node::Node()
    :data(0),next(nullptr){}

LinkedList::LinkedList()
    :head(nullptr) {}

void LinkedList::insert(int data){
    Node *newNode = new Node(data);
    if(!head){
        head = newNode;
    }
    else{
        for(Node *aux = head;aux != nullptr;aux = aux->next){
            if(aux->next == nullptr){
                aux->next = newNode;
                return;
            }
        }
    }
}

void LinkedList::print(){
    if(head){
        for(Node *aux = head;aux != nullptr;aux = aux->next){
            std::cout << "[" << aux->data << "] ";
        }
        std::cout << std::endl;
    }
    else{
        std::cout << "EMPTY LIST" << std::endl;
    }
}

Queue::Queue()
    :front(nullptr),rear(nullptr){}

void Queue::enQueue(int data){
    Node *newNode = new Node(data);
    if(!front)
        rear = front = newNode;
    else{
        rear->next = newNode;
        rear = newNode;
    }
}

int Queue::deQueue(){
    if(!front)
        return 0; //this should never happen because we have a function isEmpty() and that should be used before deQUeing
    int val = front->data;
    Node *temp = front;
    front = front->next;
    delete(temp);
    if(!front)
        rear = front;
    return val;
}

bool Queue::isEmpty(){
    return (front == nullptr);
}
//-------------------------------once we know about generic templates or stuff this should be removed
NodeTree::NodeTree(Bintree *data)
    :data(data),next(nullptr){}

NodeTree::NodeTree()
    :data(nullptr),next(nullptr){}

QueueTree::QueueTree()
    :front(nullptr),rear(nullptr){}

void QueueTree::enQueue(Bintree *data){
    NodeTree *newNode = new NodeTree(data);
    if(!front)
        rear = front = newNode;
    else{
        rear->next = newNode;
        rear = newNode;
    }
}

Bintree* QueueTree::deQueue(){
    if(!front)
        return nullptr; //this should never happen because we have a function isEmpty() and that should be used before deQUeing
    Bintree *val = front->data;
    NodeTree *temp = front;
    front = front->next;
    delete(temp);
    if(!front)
        rear = front;
    return val;
}

Bintree* QueueTree::peekTop(){
    if(!front)
        return nullptr; //this should never happen because we have a function isEmpty() and that should be used before deQUeing
    return front->data;
}

bool QueueTree::isEmpty(){
    return (front == nullptr);
}
//-------------------------------once we know about generic templates or stuff this should be removed

Bintree::Bintree(int data)
    :data(data),left(nullptr),right(nullptr){}

void Bintree::insert(int data){
    Bintree *newTree = new Bintree(data);

    QueueTree q;
    Bintree *aux = this;

    q.enQueue(aux);
    while(true){
        aux = q.deQueue();
        if(!aux->left){
            aux->left = newTree;
            break;
        }
        else if(!aux->right){
            aux->right = newTree;
            break;
        }
        else{
            q.enQueue(aux->left);
            q.enQueue(aux->right);
        }
    }
    while(!q.isEmpty()){
        q.deQueue();
    }
}


void Bintree::print(){

    QueueTree q;
    Bintree *aux = this;
    q.enQueue(aux);
    q.enQueue(nullptr);
    while(!q.isEmpty()){
        aux = q.deQueue();
        if(!aux){
            if(q.isEmpty() || !q.peekTop()){
                std::cout << "[" << "EMPTY SO LEABING" << "] " << std::endl;
                break;
            }
            std::cout << std::endl;
            q.enQueue(nullptr);
            continue;
        }
        std::cout << "[" << aux->data << "] ";
        q.enQueue(aux->left);
        q.enQueue(aux->right);
    }

    while(!q.isEmpty()){
        q.deQueue();
    }
}

void Bintree::printBackwards(){

    QueueTree q;
    Bintree *aux = this;
    q.enQueue(aux);
    q.enQueue(nullptr);
    while(!q.isEmpty()){
        aux = q.deQueue();
        if(!aux){
            if(q.isEmpty() || !q.peekTop()){
                std::cout << "[" << "EMPTY SO LEABING" << "] " << std::endl;
                break;
            }
            std::cout << std::endl;
            q.enQueue(nullptr);
            continue;
        }
        std::cout << "[" << aux->data << "] ";
        q.enQueue(aux->left);
        q.enQueue(aux->right);
    }

    while(!q.isEmpty()){
        q.deQueue();
    }
}