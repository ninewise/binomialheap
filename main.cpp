
#include "BinomialHeap.h"
#include <iostream>
using namespace Template;

int main() {
	
    Heap<int> heap;

    heap.push(1);
    heap.push(4);
    heap.push(2);
    heap.push(8);
    heap.push(9);
    heap.push(6);

    for(int i = 0; i < 6; i++) std::cout << heap.pop() << " ";
    std::cout << std::endl;

    return 0;
}
