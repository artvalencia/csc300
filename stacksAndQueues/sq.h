#ifndef LL_H
#define LL_H

struct node {
    int data;
    struct node *next;
};

void push(node*& head, int d);
void pop(node*& head);
void enqueue(node*& head, int d);
void dequeue(node*& head);
void printList(node* head);

#endif
