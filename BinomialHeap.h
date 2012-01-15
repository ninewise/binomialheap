
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

        // Pushing a new value onto the heap.
        void push(const int value);

        // Taking the smallest value off the heap.
        int pop();

        // Merge another heap with this one.
        Heap& operator+=(const Heap& heap);

      private:

        int size;
        Tree* trees;
        bool* used;

        // Merge a single tree into this heap.
        void merge(const Tree& tree);

        // Grow the number of trees this heap holds.
        void grow(const int min_size);

    };

}


namespace Template {

    template<class T> class Heap {

      public:

        Heap();
        ~Heap();

        T pop();
        void push(const T value);

        Heap<T>& operator+=(const Heap<T>& heap);

      private:

        int size;
        Tree<T>* trees;
        bool* used;
        
        void grow(const int min_size);
        void merge(const Tree<T>& tree);

    };

    template<class T> Heap<T>::Heap() : size(0) {}
    template<class T> Heap<T>::~Heap() {
        if(size > 0) { delete[] trees; delete[] used; }
    }

    template<class T> void Heap<T>::grow(const int min_size) {

        int new_size = 0;
        if(min_size < size) {
            new_size = size;
            if(used[size-1]) new_size++;
        } else {
            new_size = min_size + 1;
        }

        if(new_size != size) {
            Tree<T>* treet = new Tree<T>[new_size];
            bool* boolt = new bool[new_size];
            for(int i = 0; i < new_size; i++) {
                if(i < size && used[i]) {
                    treet[i] = trees[i];
                    boolt[i] = true;
                } else {
                    boolt[i] = false;
                }
            }

            if(size > 0) { delete[] trees; delete[] used; }
            trees = treet;
            used = boolt;
            size = new_size;
        }

    }

    template<class T> void Heap<T>::push(const T value) {
        Leaf<T> element(value);
        merge(element);
    }

    template<class T> T Heap<T>::pop() {
        int min = 0;
        while(min < size && !used[min]) min++;
        if(min == size) throw "Pop on empty stack error.";

        for(int i = 0; i < size; i++) if(used[i]) {
            if(trees[i].getValue() < trees[min].getValue()) min = i;
        }

        T value = trees[min].getValue();
        int order = trees[min].getSize();
        Tree<T>* childeren = trees[min].copyChilderen();
        used[min] = false;

        for(int i = 0; i < order; i++) merge(childeren[i]);

        delete[] childeren;
        return value;
    }

    template<class T> void Heap<T>::merge(const Tree<T>& tree) {
        grow(tree.getSize());

        Tree<T> hold;
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

    template<class T> Heap<T>& Heap<T>::operator+=(const Heap<T>& heap) {
        for(int i = 0; i < heap.size; i++) if(heap.used[i]) {
            merge(heap.trees[i]);
        }

        return *this;
    }

}

#endif
