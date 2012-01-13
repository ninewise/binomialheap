
#include "BinomialTree.h"
using namespace integered;

int main() {
    
    Tree a(0, 7), b(0, 2);

    a.print();
    b.print();

    (a+b).print();
    (b+a).print();

    ((b+a) + (a+b)).print();

    return 0;
}
