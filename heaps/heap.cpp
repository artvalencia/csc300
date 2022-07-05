#include "heap.h"
#include <iostream>
using namespace std;


void insertHeap(int heap[], int key, int &lastIndex) {
    lastIndex++;
    heap[lastIndex] = key;
    reheapUp(heap, lastIndex);


}





void reheapUp(int heap[], int locIndex) {
    if (locIndex == 0) {
        return;
    } //Indicates we're at the root. Exit recursion.
    
    int parentIndex = (locIndex - 1)/2;

    if (heap[parentIndex] > heap[locIndex]) {
        swap(heap[parentIndex], heap[locIndex]);
        
        reheapUp(heap, parentIndex);
    }
}


void deleteHeap(int heap[], int &lastIndex) {
    if(lastIndex < 0) {
        cout << "heap is empty\n";
    }

    heap[0] = heap[lastIndex];
    lastIndex--;
    reheapDown(heap, 0, lastIndex);    

}
void reheapDown(int heap[], int locIndex, int lastIndex) {
   int leftIndex, rightIndex, smallestIndex, leftValue, rightValue;

   leftIndex = 2*locIndex + 1;
   if (leftIndex <= lastIndex) { //means left child exists
       leftValue = heap[leftIndex];
        rightIndex = leftIndex + 1;
        if (rightIndex <= lastIndex) {
            rightValue = heap[rightIndex];
        }
        else {
            // Have left child but no right child
            rightValue = leftValue + 1; //always less than leftValue
        }

        if (leftValue < rightValue) {
            smallestIndex = leftIndex;
        }
        else {
            smallestIndex = rightIndex;
        }

        //Check if should swap
        if (heap[smallestIndex] < heap[locIndex]) {
            swap(heap[smallestIndex], heap[locIndex]);
            reheapDown(heap, smallestIndex, lastIndex);
        }
    }
}

int main() {
    int heap[10];
    int size =10;
    int min =0, max = 100;
    int newValue;
    int lastIndex = -1;

    srand(time(0));
    for (int i = 0 ; i < size ; i++) {
        newValue = rand() % (max+1 - min) + min;
        cout << newValue << "  ";
        insertHeap(heap, newValue, lastIndex);
    }

    cout << endl << endl;

    for (int i = 0 ; i < size ; i++) {
        cout << heap[0] << "  ";
        deleteHeap(heap, lastIndex);
    }



    return 0;
}