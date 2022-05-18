#include "head.h"
#include <iostream>

using namespace std;

Heap::Heap(int newHeapValue) {
    this->append(newHeapValue);
}

void Heap::append(int newHeapValue) {
    this->heapSize++;
    int *tmpArray = this->heapValues;
    this->heapValues = new int[this->heapSize];

    if (tmpArray == nullptr) {
        //dodana wartosc tworzy nową tablice i jest jego pierwszym elementem
        this->heapValues[0] = newHeapValue;
    } else {
        int tmpHepSize = this->heapSize - 1;
        //przypisanie wartosci do nowej tabeli
        for (int i = 0; i < tmpHepSize; i++) {
            this->heapValues[i] = tmpArray[i];
        }
        //Dodanie na koniec nowego elementu
        this->heapValues[tmpHepSize] = newHeapValue;

        //Magia mająca na celu zachowanie struktury po dodaniu nowego elementu
        while (tmpHepSize != 0 && this->heapValues[parent(tmpHepSize)] > this->heapValues[tmpHepSize]) {
            swap(this->heapValues[tmpHepSize], this->heapValues[parent(tmpHepSize)]);
            tmpHepSize = parent(tmpHepSize);
        }
    }

    delete[] tmpArray;
}

void Heap::showMin() {
    if (this->heapValues != nullptr) {
        cout << this->heapValues[0] << endl;
    } else {
        cout << "Kopiec jest pusty" << endl;
    }
}

int Heap::extractMin() {
    if (this->heapSize != 0) {
        if (this->heapSize == 1) {

            return this->heapValues[0];
        }

        int tmpHepSize = this->heapSize - 1;
        int root = this->heapValues[0];
        this->heapValues[0] = this->heapValues[tmpHepSize];
        this->heapSize--;
        --tmpHepSize;


        return root;
    } else {
        return -1;
    }
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

Heap::~Heap() {

}

int Heap::parent(int i) {
    return (i - 1) / 2;
}

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}


