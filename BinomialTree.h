
#ifndef BINOMIAL_TREE_H
#define BINOMIAL_TREE_H

/**
 * Contains an implementation of Binomial Heaps of integers.
 */
namespace integered {

    /**
     * A Binomial Tree.
     */
    class Tree {
      
      public:

        // Constructors.
        Tree();
        Tree(int size);
        Tree(int size, int value);
        Tree(const Tree&);

        // Destructor.
        virtual ~Tree();

        int getValue() const;
        int getSize() const;

        void setValue(int value);

        // Deep copy of tree. Needs the same size.
        Tree& operator=(const Tree& tree);

        // Check if the size, value and (recursively) childeren are equal.
        bool operator==(const Tree& tree) const;
        bool operator!=(const Tree& tree) const;

        // The merge of two tree of the same size.
        friend const Tree operator+(const Tree& tree1, const Tree& Tree2);

        // Debugging
        void print() const;
        void printr(int prefix) const;

      private:

        // The size of the tree. This is the order of the tree.
        int size;
        // The value of the root node.
        int value;
        // An array of the childeren of this Trees root.
        Tree* childeren;

    };

	class Leaf : public Tree {

	  public:

		Leaf();
		Leaf(int value);

	};

}

#endif
