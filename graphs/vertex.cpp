#include "vertex.h"
#include <iostream>
using namespace std;


void addVertex(Vertex*& vHead, char label) {
    Vertex* newVertex = new Vertex;
    newVertex->data = label;
    newVertex->vNext = nullptr;
    newVertex->aHead = nullptr;
    
    if (vHead == nullptr) {
        vHead = newVertex;
        return;
    }

    if (vHead->data > label) {
        newVertex->vNext = vHead;
        vHead = newVertex;
        return;
    }

    Vertex* curVer = vHead;

    while (curVer->vNext != nullptr && curVer->vNext->data < label) {
        curVer = curVer->vNext;
    }

    // Determine if curVer is null or not
    if (curVer->vNext == nullptr) {
        curVer->vNext = newVertex;
    }
    else {
        newVertex->vNext = curVer->vNext;
        curVer->vNext = newVertex;
    }



}

void printGraph(Vertex* vHead) {
    Vertex* curVer = vHead;
    Arc* curArc;

    while (curVer != nullptr) {
        cout << curVer->data;
        if (curVer->aHead != nullptr) {
            cout << "  -> " ;
        }
        curArc = curVer->aHead;
        while (curArc != nullptr) {
            cout << curArc->dest->data;

            if (curArc->aNext != nullptr) {
                cout << " -> ";
            }

            curArc = curArc->aNext;
        }

        curVer = curVer->vNext;
        cout << endl;
    }
    cout << endl;
}

void addArc(Vertex* vHead, char from, char to) {
    // First step: Traverse to the "from" Vertex

    Vertex* fromVer = findVertex(vHead, from);
    if (fromVer == nullptr) {
        cout << "from vertex is not in the list\n";
        return;
    }

    //while (fromVer != nullptr && fromVer->data < from) {
    //    fromVer = fromVer->vNext;
    //}

    //if (fromVer == nullptr || fromVer->data > from) {
    //    cout << "Starting vertex is not in the list.\n";
    //    return;
    //}

    //Vertex* toVer = vHead;
    Vertex* toVer = findVertex(vHead, to);
    if (toVer == nullptr) {
        cout << "to vertex is not in the list\n";
        return;
    }

    //while (toVer != nullptr && toVer->data < to) {
    //    toVer = toVer->vNext;
    //}

    //if (toVer == nullptr || toVer->data > to) {
    //    cout << "Destination vertex is not in the list.\n";
    //    return;
    //}

    Arc* newArc = new Arc;
    newArc->dest = toVer;
    newArc->aNext = nullptr;

    
    if (fromVer->aHead == nullptr) {
        fromVer->aHead = newArc;
        return;
    }

    if (fromVer->aHead->dest->data > to) {
        newArc->aNext = fromVer->aHead;
        fromVer->aHead = newArc;
        return;
    }

    Arc* curArc = fromVer->aHead;

    while (curArc->aNext != nullptr && curArc->aNext->dest->data < to) {
        curArc = curArc->aNext;
    }

    // Determine if curArc is null or not
    if (curArc->aNext == nullptr) {
        curArc->aNext = newArc;
    }
    else {
        newArc->aNext = curArc->aNext;
        curArc->aNext = newArc;
    }



}


void remArc(Vertex* vHead, char from, char to) {
    // First Step: Find the "from Vertex
    Vertex* fromVer = vHead;


    while (fromVer != nullptr && fromVer->data < from) {
        fromVer = fromVer->vNext;
    }

    if (fromVer == nullptr || fromVer->data > from) {
        cout << "Starting vertex is not in the list.\n";
        return;
    }


    Arc* curArc = fromVer->aHead;
    if (curArc == nullptr) {
        cout << "Arc head is null. There is no connection between these vertices\n";
        return;
    }

    if (curArc->dest->data == to) {
        Arc* dltPtr = curArc;
        fromVer->aHead = curArc->aNext;
        delete dltPtr;
        return;
    }

    while (curArc->aNext != nullptr && curArc->aNext->dest->data < to) {
        curArc = curArc->aNext;
    }

    if (curArc->aNext == nullptr || curArc->aNext->dest->data > to) {
        cout << "There is no connection between these vertices\n";
        return;
    }
    else {
        Arc* dltPtr = curArc->aNext;
        curArc->aNext = curArc->aNext->aNext;
        delete dltPtr;
    }


}


Vertex* findVertex(Vertex* vHead, char key) {
    Vertex* findVer = vHead;


    while (findVer != nullptr && findVer->data < key) {
        findVer = findVer->vNext;
    }

    if (findVer == nullptr || findVer->data > key) {
        return nullptr;
    }
    else {
        return findVer;
    }
}


void remVertex(Vertex*& vHead, char label) {
    Vertex* findVer = findVertex(vHead, label);
    if (findVer == nullptr) {
        cout << "Vertex not in the list.\n";
        return;
    }

    Vertex* vTmp = vHead;
    Arc* aTmp = nullptr; 

    //deleting all arcs first, have to go back and delete vertex
    while (vTmp != nullptr) {
        aTmp = vTmp->aHead;
        while (aTmp != nullptr) {
            if (aTmp->dest->data == label) {
                remArc(vHead, vTmp->data, label);
                aTmp = nullptr;
            }
            if (aTmp != nullptr) {
                aTmp = aTmp->aNext;
            }
        }
        vTmp = vTmp->vNext;
    }
}
