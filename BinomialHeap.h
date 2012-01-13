
#ifndef BINOMIAL_HEAP_H
#define BINOMIAL_HEAP_H

/**
 * Contains an implementation of Binomial Heaps of integers.
 */
namespace integered {

    /**
     * A Binomial Tree.
     */
    class Tree {
      
        // Create a default tree of size 0.
        Tree();

        // Create a new Tree with size, value and no childeren.
        Tree(int size, int value);

        // Copy constructor.
        Tree(const Tree&);

        // Destructor.
        virtual ~Tree();

        public:
        int getValue() const;
        int getSize() const;

        int setValue(int value);

        // Deep copy of tree. Needs the same size.
        Tree& operator=(Tree tree);

        // Check if the size, value and (recursively) childeren are equal.
        bool operator==(Tree tree) const;

        // The merge of two tree of the same size.
        friend Tree operator+(const Tree tree1, const Tree Tree2);

        private:
        // The size of the tree. This is the order of the tree.
        const int size;
        // The value of the root node.
        int value;
        // An array of the childeren of this Trees root.
        Tree* childeren;

    }

}

#endif
