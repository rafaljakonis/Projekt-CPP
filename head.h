#ifndef UNTITLED_HEAD_H
#define UNTITLED_HEAD_H

void test();
void swap(int &x, int &y);

class Heap {
    int heapSize = 0;
    int *heapValues = nullptr;

public:
    Heap(int newHeapValue);

    void append(int newHeapValue);
    void showArray();
    void showMin();
    int parent(int i);
    void sort(Heap heapCopy);
//    int left(int i);
//    int right(int i);
    int extractMin();

    ~Heap();
};
#endif
