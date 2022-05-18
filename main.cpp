#include <iostream>
#include "head.h"
using namespace std;

int main() {
    Heap test = Heap(1);
    test.append(2);
    test.append(3);
    test.append(4);
    test.append(5);
    test.append(7);
    test.append(2);
    test.append(1);
    test.append(6);
    test.append(11);
    test.append(1);
    test.append(4);
    test.append(1);
    test.append(5);
    test.append(1);
    test.append(7);

    test.showArray();
    test.extractMin();
    test.showArray();

    return 0;
}
