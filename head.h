#ifndef UNTITLED_HEAD_H
#define UNTITLED_HEAD_H

void test();


class Heap {
    int heapSize = 0;
    int *heapValues = nullptr;

    int parent(int i);
    int left(int i);
    int right(int i);
    void rebuildHeapAfterDeleteMin(int i);
    void rebuildHeapAfterInsert();
    void swap(int &x, int &y);
    void appendByConstruct(int *dataToSave);

public:
    Heap();
    Heap(int newHeapValue);
    Heap(const Heap &newHeapValue);
    ~Heap();

    int dropMin();
    void append(int newHeapValue);
    void showArray();
    int getHeapLength();
    void removeByIndex(int index);
    void clear();
};


void heapSort(Heap heap);
int * heapSortArray(Heap heap);
#endif
