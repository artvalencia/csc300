#include "sq.h"
#include <iostream>
using namespace std;

void push(node*& head, int d) {
    node *newNode = new node;
    newNode->data = d;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    }
    else {
        newNode->next = head;
        head = newNode;
    }
}


void pop(node*& head) {
    if (head == nullptr) {
        cout << "Stack is empty. No more nodes to pop.\n";
    }
    else {
        node *tmp = head;
        head = head->next;
        delete tmp;
    }
}


void enqueue(node*& head, int d) {
    node *newNode = new node;
    newNode->data = d;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    }
    else {
        newNode->next = head;
        head = newNode;
    }

}


void dequeue(node*& head) {
    if (head == nullptr) {
        cout << "Queue is empty. No more nodes to dequeue.\n";
    }
    else {
        node *tmp1 = head;
        node *tmp2 = head;

        while (tmp1->next != nullptr) {
            tmp1 = tmp1->next;
        }
        while (tmp2->next != tmp1) {
            tmp2 = tmp2->next;
        }

        tmp2->next = nullptr;
        delete tmp1;
    }
}


void printList(node* head) {
    node *tmp = head;

    while (tmp != nullptr) {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}
