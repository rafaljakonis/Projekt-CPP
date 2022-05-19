#include "head.h"
#include <iostream>

using namespace std;

Heap::Heap(int newHeapValue) {
    this->append(newHeapValue);
}

Heap::Heap() {}

Heap::~Heap() {
    delete[] this->heapValues;
}

Heap::Heap(const Heap &newHeapValue) {
    this->heapSize = newHeapValue.heapSize;
    appendByConstruct(newHeapValue.heapValues);
}

void Heap::append(int newHeapValue) {
    this->heapSize++;
    int *tmpArray = this->heapValues;
    this->heapValues = new int[this->heapSize];

    if (tmpArray == nullptr) {
        this->heapValues[0] = newHeapValue;
    } else {
        int tmpHepSize = this->heapSize - 1;

        for (int i = 0; i < tmpHepSize; i++) {
            this->heapValues[i] = tmpArray[i];
        }

        this->heapValues[tmpHepSize] = newHeapValue;
        this->rebuildHeapAfterInsert();
    }

    delete[] tmpArray;
}

void Heap::appendByConstruct(int *dataToSave) {
    this->heapValues = new int[this->heapSize];

    for (int i = 0; i < this->heapSize; i++) {

        this->heapValues[i] = dataToSave[i];
    }
}

void Heap::rebuildHeapAfterInsert() {
    int tmpHepSize = this->heapSize - 1;

    while (tmpHepSize != 0 && this->heapValues[parent(tmpHepSize)] > this->heapValues[tmpHepSize]) {
        this->swap(this->heapValues[tmpHepSize], this->heapValues[parent(tmpHepSize)]);
        tmpHepSize = parent(tmpHepSize);
    }
}

void Heap::rebuildHeapAfterDeleteMin(int index) {
    int leftNodeValue = left(index);
    int rightNodeValue = right(index);
    int smallestValueInHeap = index;

    if (leftNodeValue < this->heapSize && this->heapValues[leftNodeValue] < this->heapValues[index]) {
        smallestValueInHeap = leftNodeValue;
    }

    if (rightNodeValue < this->heapSize && this->heapValues[rightNodeValue] < this->heapValues[smallestValueInHeap]) {
        smallestValueInHeap = rightNodeValue;
    }

    if (smallestValueInHeap != index) {
        this->swap(this->heapValues[index], this->heapValues[smallestValueInHeap]);
        rebuildHeapAfterDeleteMin(smallestValueInHeap);
    }
}

int Heap::dropMin() {

    if (this->heapSize != 0) {
        if (this->heapSize == 1) {

            return this->heapValues[0];
        }

        int tmpHepSize = this->heapSize - 1;
        int root = this->heapValues[0];
        this->heapValues[0] = this->heapValues[tmpHepSize];
        this->heapSize = tmpHepSize;
        this->rebuildHeapAfterDeleteMin(0);

        return root;
    } else {
        cout << "Kopiec jest pusty" << endl;

        return -1;
    }
}

void Heap::clear() {
    delete[] this->heapValues;
    this->heapValues = nullptr;
    this->heapSize = 0;
}

void Heap::showArray() {
    if (this->heapValues != nullptr) {
        cout << "Kopiec zawiera dane: { ";
        for (int i = 0; i < this->heapSize; i++) {
            cout << this->heapValues[i] << " ";
        }
        cout << "}" << endl;
    } else {
        cout << "Kopiec jest pusty" << endl;
    }
}

int Heap::getHeapLength() {
    return this->heapSize;
}

int Heap::parent(int i) {
    return (i - 1) / 2;
}

int Heap::left(int i) {

    return (2 * i + 1);
}

int Heap::right(int i) {

    return (2 * i + 2);
}

void Heap::swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

void Heap::removeByIndex(int index) {
    int tmpSize = this->heapSize - 1;
    if (tmpSize >= 0 && tmpSize >= index) {
        int *newTable = new int[tmpSize];
        int tmpIndex = 0;

        for (int i = 0; i < tmpSize; i++) {
            if (i == index) {
                ++tmpIndex;
            }

            newTable[i] = this->heapValues[tmpIndex];
            ++tmpIndex;
        }

        --this->heapSize;
        this->heapValues = newTable;
    } else {
        cout << "Podany index nie istnieje" << endl;
    }
}

void heapSort(Heap heap) {
    int tmpHeapSize = heap.getHeapLength();

    if (tmpHeapSize != 0) {
        for (int i = 0; i < tmpHeapSize; i++) {
            cout << heap.dropMin() << " ";
        }

        cout << endl;
    } else {
        cout << "Kopiec jest pusty";
    }
}

int *heapSortArray(Heap heap) {
    int tmpHeapSize = heap.getHeapLength();

    if (tmpHeapSize != 0) {
        int *array = new int[tmpHeapSize];
        for (int i = 0; i < tmpHeapSize; i++) {
            array[i] = heap.dropMin();
        }

        return array;
    }
}

