
#ifndef BINOMIAL_HEAP_H
#define BINOMIAL_HEAP_H

#include "BinomialTree.h"

namespace integered {

    class Heap {

      public:

        Heap();
        ~Heap();

        // Print each tree in the heap.
        void print() const;

        // Merge a single tree into this heap.
        void merge(const Tree& tree);

        // Merge another heap with this one.
        Heap& operator+=(const Heap& heap);

      private:

        int size;
        Tree* trees;
        bool* used;

        // Grow the number of trees this heap holds.
        void grow(const int min_size);

    };

}
#endif
