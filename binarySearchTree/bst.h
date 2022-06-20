#ifndef BST_H
#define BST_H

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

void insertNode(node*& root, int key);
void deleteNode(node*& root, int key);
void printAscending(node* root);

// Next functions are required for homework and weren't covered in video
void printParenthetical(node* root);
node* searchNode(node* root, int key);
int findSmallest(node* root);
int findLargest(node* root);


#endif