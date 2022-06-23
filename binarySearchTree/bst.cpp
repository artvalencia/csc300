#include "bst.h"
#include <iostream>
using namespace std;

void insertNode(node*& root, int key) {
    if (root == nullptr) {
        root = new node;
        root->data = key;
        root->right = nullptr;
        root->left = nullptr;
    }
    else {
        if (root->data > key) {
            insertNode(root->left, key);
        }
        else {
            insertNode(root->right, key);
        }
    }
}

void deleteNode(node*& root, int key) {
    if (root == nullptr) { //Key is not in the tree
        cout << key << " Was not found in the tree. \n\n";
        return;
    }
    else {
        if (key < root->data) {
            deleteNode(root->left, key);
        }
        else if (key > root->data) {
            deleteNode(root->right, key);
        }
        else { //Key == root->data 
            if (root->left == nullptr) {
                //First, handle where both children are null
                if (root->right == nullptr) {
                    delete root;
                    root = nullptr;
                }
                //Second: left is null, right is not null
                else {
                    node *dltPtr = root;
                    root = root->right;
                    delete dltPtr;
                }
            }
            //Here if left pointer is not null
            else {
                //Third: Left is not null, but right is null
                if (root->right == nullptr) {
                    node* dltPtr = root;
                    root = root->left;
                    delete dltPtr;
                }
                else { //Fourth: Node has two children
                    node* largestLeft = root->left; //Taking a step left
                    while (largestLeft->right != nullptr) {
                        largestLeft = largestLeft->right;
                    }

                    root->data = largestLeft->data;
                    deleteNode(root->left, largestLeft->data);
                }
            }
        }
    }
}


void printAscending(node* root) {
    if (root != nullptr) {
        printAscending(root->left);
        cout << root->data << " ";
        printAscending(root->right);
    }
}


void printParenthetical(node* root) {
    if (root != nullptr) {
        cout << root->data << " ";

        if (root->left != nullptr || root->right != nullptr) {
            cout << "( ";
        }

        printParenthetical(root->left);
        printParenthetical(root->right);
        if (root->left != nullptr || root->right != nullptr) {
            cout << ") ";
        }
    }
}


node* searchNode(node* root, int key) {
    if (root == nullptr) {
        cout << "Key not in tree, returning nullptr\n";
        return nullptr;
    }
    else if (root->data == key) {
        return root;
    }
    else {
        if (root->data > key) {
            searchNode(root->left, key);
        }
        else {
            searchNode(root->right, key);
        }
    }
}


int findSmallest(node* root) {
    if (root->left == nullptr) {
        return root->data;
    }
    
    findSmallest(root->left);
}


int findLargest(node* root) {
    if (root->right == nullptr) {
        return root->data;
    }
    
    findLargest(root->right);
}