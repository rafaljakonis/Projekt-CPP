#include <iostream>
#include "head.h"
using namespace std;

int main() {
    Heap test = Heap(9);
    test.append(8);
    test.append(1);
    test.append(1);
    test.append(1);
    test.showArray();

    test.showArray();

    return 0;
}
