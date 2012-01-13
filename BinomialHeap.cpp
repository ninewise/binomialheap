
#include "BinomialHeap.h"
<<<<<<< HEAD

namespace integered {

    Element::Element(const int size) : size(size) {}
=======
#include <iostream>


namespace integered {

    /* ===================================================================== *\
     *                      CONSTRUCTORS AND DESTRUCTOR                      *
    \* ===================================================================== */

    Tree::Tree() : size(0), value(0) {}

    Tree::Tree(const int size, int value) : size(size), value(value) {
        if(size != 0) {
            childeren = new Tree[size];
        }
    }

    Tree::Tree(const Tree& tree) : size(tree.size), value(tree.value) {
        for(int i = 0; i < size; i++) childeren[i] = tree.childeren[i];
    }

    Tree::~Tree() {
        delete[] childeren;
    }

    /* ===================================================================== *\
     *                          GETTERS AND SETTERS                          *
    \* ===================================================================== */

    int Tree::getValue() const { return value; }
    int Tree::getSize() const { return size; }

    void Tree::setValue(int value) { this->value = value; }

    /* ===================================================================== *\
     *                               OPERATORS                               *
    \* ===================================================================== */

    Tree& Tree::operator=(const Tree& tree) {
        if(size != tree.size) throw "Operation only for Trees of equal size.";
        value = tree.value;
        for(int i = 0; i < size; i++) childeren[i] = tree.childeren[i];

        return (*this);
    }

    bool Tree::operator==(const Tree& tree) const {
        if(size != tree.size || value != tree.value) return false;

        int i = 0;
        while(childeren[i] == tree.childeren[i]) i++;

        return i == size;
    }

    const Tree operator+(const Tree& tree1, const Tree& tree2) {
        if(tree1.size != tree2.size)
            throw "Operation only supported for Trees of equal size.";
        const int size = tree1.size;

        Tree larger(size, 0), smaller(size, 0);
        if(tree1.value < tree2.value) {
            smaller = tree1; larger = tree2;
        } else {
            smaller = tree2; larger = tree1;
        }

        Tree temp(size + 1, smaller.value);

        temp.childeren[0] = larger;
        for(int i = 1; i < size; i++) temp.childeren[i] = smaller.childeren[i];

        return (temp);
    }

    /* ===================================================================== *\
     *                               DEBUGGING                               *
    \* ===================================================================== */

    void Tree::print() const {
        std::cout << "=> " << value << std::endl;
        for(int i = 0; i < size; i++) childeren[i].printr(1);
    }

    void Tree::printr(int prefix) const {
        for(int i = 0; i < prefix; i++) std::cout << " ";
        std::cout << "=> " << value << std::endl;
        for(int i = 0; i < size; i++) childeren[i].printr(prefix + 1);
    }
>>>>>>> parent of 6f4eb09... cleanup for restart

}
