Create a header file and accompanying code file that implement the functions for a stack and queue (push/pop and enqueue/dequeue respectively); and also a function for printing the stack/queue.

The header file should be called sq.h and the corresponding code file should be called sq.cpp.

While you should write your own main program to test your functions, I will write my own that will include your header files and test your functions. In order for me to do this, you must name your files and functions exactly as I've asked you too. Specifically for the functions, please use the following function signatures to build off of.

void push(node*& head, int d);    // 'd' is an integer to store in the data attribute of the node being pushed onto the stack.
void pop(node*& head);               // Simply removes the latest node pushed onto the stack.
void enqueue(node*& head, int d);   // 'd' is an integer to store in the data attribute of the node being enqueued.
void dequeue(node*& head);       // Simply removes the oldest node still in the queue.
void printList(node* head);          // Prints out the list on a single line (values separated by a space or two, and creates a newline after the list is printed).
