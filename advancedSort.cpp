#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

void randomArray (int array[], int size); 
void equalArray (int oldArray[], int newArray[], int size); 
void printArray (int array[], int size);
void insertionSort (int array[], int size);

#define smallSize 20
#define largeSize 100000

int main() {
    int insertArray[smallSize];
    int quickArray[smallSize];
    int shellArray[smallSize];

    randomArray(insertArray, smallSize);
    equalArray(insertArray, quickArray, smallSize);
    equalArray(insertArray, shellArray, smallSize);

    cout << "INSERTION SORT" << endl << endl << "Original array \n";
    printArray(insertArray, smallSize);
    cout << endl << endl;
    insertionSort(insertArray, smallSize);
    cout << "Array after sorting\n";
    printArray(insertArray, smallSize);
    cout << endl << endl << "------------------------------------------------------------------------------------------" << endl << endl;
    // clock_t start, end;
    // double insertTime;
    // start = clock();
    // insertionSort(insertArray, smallSize);
    // end = clock();
    // insertTime = 1000.0 * (end - start) / CLOCKS_PER_SEC;
    // cout << "Array after sorting" << endl;
    // printArray(insertArray, smallSize);
    // cout << endl << endl << "Time it took to sort: " << insertTime << "ms" << endl << "----------------------------------------" << endl << endl << endl;

    cout << "Original quick sort array \n";
    printArray(quickArray, smallSize);
    cout << endl << endl;

    cout << "Original shell sort array \n";
    printArray(shellArray, smallSize);
    cout << endl << endl;

    return 0;
}


void randomArray (int array[], int size) {
    int min = 0, max = 1000000;

    for (int i = 0; i < size; i++) {
        array[i] = rand()%(max+1 - min) + min;
    }
}


void equalArray (int oldArray[], int newArray[], int size) {
    int i = 0;

    for (i = 0 ; i < size ; ++i) {
        newArray[i] = oldArray[i];
    }
}

void printArray (int array[], int size) {
    int i = 0;

    for (i = 0 ; i < size ; ++i) {
        cout << array[i] << " ";
    }
}


void insertionSort (int array[], int size) {
    int current, hold, walker;

    for (current = 1; current < size; current++) {
        hold = array[current];

        for (walker = current - 1; walker >= 0 && hold < array[walker]; walker--) {
            array[walker+1] = array[walker];
        }

        array[walker+1] = hold;
    }
}