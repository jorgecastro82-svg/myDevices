#ifndef STRUCTURES_H
#define STRUCTURES_H

struct Node{
    int data;
    Node *next;
    Node();
    Node(int data);
};

struct LinkedList{
    Node *head;

    void print();
    void insert(int data);
    LinkedList();
};

struct Queue{
    Node *front;
    Node *rear;
    Queue();
    void enQueue(int data);
    int deQueue();
    bool isEmpty();

};


struct Bintree{
    int data;
    Bintree *left;
    Bintree *right;
    Bintree(int data);
    void insert(int data);
    void print();
    void printBackwards();
};

//-------------------------------once we know about generic templates or stuff this should be removed
struct NodeTree{
    Bintree *data;
    NodeTree *next;
    NodeTree();
    NodeTree(Bintree *data);
};
struct QueueTree{
    NodeTree *front;
    NodeTree *rear;
    QueueTree();
    void enQueue(Bintree *tree);
    Bintree *deQueue();
    Bintree *peekTop();
    bool isEmpty();
};
//-------------------------------once we know about generic templates or stuff this should be removed
#endif