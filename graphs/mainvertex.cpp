#include "vertex.h"
#include <iostream>
using namespace std;

int main () {
    Vertex* gHead = nullptr; // The first vertex in the graph

    addVertex (gHead, 'A');
    addVertex (gHead, 'B');
    addVertex (gHead, 'C');
    addVertex (gHead, 'D');
    addVertex (gHead, 'E');
    addVertex (gHead, 'F');

    addArc(gHead, 'A', 'B');
    addArc(gHead, 'B', 'C');
    addArc(gHead, 'B', 'E');
    addArc(gHead, 'C', 'E');
    addArc(gHead, 'C', 'D');
    addArc(gHead, 'E', 'D');
    addArc(gHead, 'E', 'F');

    printGraph(gHead);

    remVertex(gHead, 'A');
    remVertex(gHead, 'F');
   // printGraph(gHead);
   // remArc(gHead, 'C', 'E');
   // remArc(gHead, 'E', 'F');
    printGraph(gHead);
//
//    printGraph(gHead);


    return 0;
}
