# Instructions
Add the following functions to the bst.h/bst.cpp files:

**Already done in class, but please include:**

* Insert a node given an integer into the tree.
* Delete the node in the tree given an integer. If the node does not exist in the tree, then let the user know.
* Print the values in the tree in ascending order.

**You need to add: (Please use exact spelling and parameters so I can include it in my test program.)**

```c++
void printParenthetical(node* root); // Print the tree using parenthetical notation.
node* searchNode(node* root, int key); // Given an integer, return the node pointer for the node that has that integer as an attribute.
int findSmallest(node* root); // returns the smallest value in the BST.
int findLargest(node* root); // returns the smallest value in the BST. You'll want to write your own main function to test your functions, but make sure it's in a separate file or commented out when you're done so I can include these files in my own test program. I'll write my own mainbst.cpp file that includes bst.cpp.
```
When you submit, I'll want the bst.h and bst.cpp files. If you write your own main program, you can submit it optionally.
