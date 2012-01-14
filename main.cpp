
#include "BinomialTree.h"
#include "BinomialHeap.h"
#include <iostream>
using namespace integered;

int main() {
	
	Leaf a(1), b(2), c(5), d(2), e(6);

	Heap heap, heap2;

	heap.merge(a);
	heap.merge(b);
	heap.merge(c);
	heap.merge(d);
	heap.merge(e);

    heap2.merge(Leaf(10));
    heap2.merge(Leaf(15));
    heap2.merge(Leaf(12));
    heap2.merge(Leaf(19));
    heap2.merge(Leaf(10));
    heap2.merge(Leaf(11));

    std::cout << "chicken\n";

    heap += heap2;

    heap.print();

    return 0;
}
