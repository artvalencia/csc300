#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

void randomArray (int array[], int size); 
void equalArray (int oldArray[], int newArray[], int size); 
void printArray (int array[], int size);
void insertionSort (int array[], int size);
void shellSort (int array[], int size);
void fillArraySorted (int array[], int size);

#define smallSize 20
#define largeSize 100000

int main() {
    int insertArray[smallSize];
    int quickArray[smallSize];
    int shellArray[smallSize];
    int insertArrayLG[largeSize];
    int quickArrayLG[largeSize];
    int shellArrayLG[largeSize];

    randomArray(insertArray, smallSize);
    equalArray(insertArray, quickArray, smallSize);
    equalArray(insertArray, shellArray, smallSize);
    randomArray(insertArrayLG, largeSize);
    equalArray(insertArrayLG, quickArrayLG, largeSize);
    equalArray(insertArrayLG, shellArrayLG, largeSize);

    cout << "INSERTION SORT" << endl << endl << "Original array \n";
    printArray(insertArray, smallSize);
    cout << endl << endl;
    insertionSort(insertArray, smallSize);
    cout << "Array after sorting\n";
    printArray(insertArray, smallSize);
    cout << endl << endl << "------------------------------------------------------------------------------------------" << endl << endl;

    cout << "SHELL SORT" << endl << endl << "Original array \n";
    printArray(shellArray, smallSize);
    cout << endl << endl;
    shellSort(shellArray, smallSize);
    cout << "Array after sorting\n";
    printArray(insertArray, smallSize);
    cout << endl << endl << "------------------------------------------------------------------------------------------" << endl << endl << "Sorting Arrays size 100000" << endl;

    clock_t start, end;
    double insertTime;
    start = clock();
    insertionSort(insertArrayLG, largeSize);
    end = clock();
    insertTime = 1000.0 * (end - start) / CLOCKS_PER_SEC;
    cout << "Time it took to sort using insertion: " << insertTime << " ms" << endl;

    start = clock();
    shellSort(shellArrayLG, largeSize);
    end = clock();
    insertTime = 1000.0 * (end - start) / CLOCKS_PER_SEC;
    cout << "Time it took to sort using shell: " << insertTime << " ms" << endl;

    fillArraySorted(insertArrayLG, largeSize);
    fillArraySorted(shellArrayLG, largeSize);
    cout << "Sorting arrays size 100000 where elements are 1, 2, 3...\n";

    start = clock();
    insertionSort(insertArrayLG, largeSize);
    end = clock();
    insertTime = 1000.0 * (end - start) / CLOCKS_PER_SEC;
    cout << "Time it took to sort using insertion: " << insertTime << " ms" << endl;

    start = clock();
    shellSort(shellArrayLG, largeSize);
    end = clock();
    insertTime = 1000.0 * (end - start) / CLOCKS_PER_SEC;
    cout << "Time it took to sort using shell: " << insertTime << " ms" << endl;


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


void shellSort (int array[], int size) {
    int current, hold, walker, incre, last;
    last = size - 1;
    incre = last/2;

    while (incre != 0) {
        current = incre;

        while (current <= last) {
            hold = array[current];
            walker = current - incre;

            while (walker >= 0 && hold < array[current]) {
                array[walker + incre] = array[walker];
                walker = walker - incre;
            }
            array[walker + incre] = hold;
            current = current + 1;
        }
        incre = incre/2;
    }
}


void fillArraySorted (int array[], int size) {
    int i = 0, fill = 1;

    for (i = 0 ; i < size ; ++i) {
        array[i] = fill;
        fill++;
    }
}