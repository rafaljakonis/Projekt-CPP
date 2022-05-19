#include <iostream>
#include "head.h"
using namespace std;

int main() {
    Heap minHeap = Heap();
    minHeap.append(8);
    minHeap.append(1);
    minHeap.append(5);
    minHeap.append(2);
    minHeap.append(9);
    minHeap.append(4);
    minHeap.append(2);
    minHeap.append(7);
    minHeap.append(1);

    cout << "Przykladowy kopiec" << endl;
    minHeap.showArray();

    int *test = heapSortArray(minHeap);

    cout << "Usuwanie po index'ie" << endl;
    minHeap.removeByIndex(2);
    minHeap.showArray();

    cout << "Posortowane dane ";
    heapSort(minHeap);
    cout << endl;

    cout <<"Ilosc elementow w kopcu " << minHeap.getHeapLength() << endl;

    cout <<"Czyszczenie kopca" << endl;
    minHeap.clear();



    return 0;
}
