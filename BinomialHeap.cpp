
#include "BinomialHeap.h"
#include "BinomialTree.h"
#include <iostream>

#ifndef NULL
#define NULL 0
#endif

namespace integered {

    /* ===================================================================== *\
     *                             Constructors                              *
    \* ===================================================================== */

    Heap::Heap() : size(0) {}

    Heap::~Heap() {
        if(size > 0) {
            delete[] trees;
            delete[] used;
        }
    }

    /* ===================================================================== *\
     *                               Publics                                 *
    \* ===================================================================== */

    void Heap::print() const {
        std::cout << "Printing heap of order " << size << "." << std::endl;
        for(int i = 0; i < size; i++) if(used[i]) {
            std::cout << "order " << i << std::endl;
            trees[i].print();
        } else {
            std::cout << "order " << i << " is empty." << std::endl;
        }
        std::cout << std::endl;
    }

    /* ===================================================================== *\
     *                               Privates                                *
    \* ===================================================================== */

    void Heap::grow(const int min_size) {

        int new_size = 0;
        
        if(min_size < size) {
            new_size = size;
            if(used[size-1]) new_size++;
        } else {
            new_size = min_size + 1;
        }

        if(new_size != size) {
            Tree* treet = new Tree[new_size];
            bool* boolt = new bool[new_size];
            for(int i = 0; i < size; i++)
                if(used[i]) {
                    treet[i] = trees[i];
                    boolt[i] = true;
                } else {
                    boolt[i] = false;
                }
            for(int i = size; i < new_size; i++) boolt[i] = false;

            if(size > 0) {
                delete[] trees;
                delete[] used;
            }
            trees = treet;
            used  = boolt;
            size = new_size;
        }
    }

    void Heap::merge(const Tree& tree) {
        grow(tree.getSize());

        Tree hold;
        hold = tree;
        int order = hold.getSize();

        while(used[order]) {
            hold = hold + trees[order];
            used[order] = false;
            order++;
        }

        trees[order] = hold;
        used[order] = true;
    }

    Heap& Heap::operator+=(const Heap& heap) {
        for(int i = 0; i < heap.size; i++) {
            if(heap.used[i]) merge(heap.trees[i]);
        }

        return (*this);
    }

}
