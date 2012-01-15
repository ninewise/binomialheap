
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
        Tree* getChilderen() const;

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
		Leaf(const int value);

	};

}

namespace Template {

    template<class T> class Tree;
    template<class T>
    const Tree<T> operator+(const Tree<T>& tree1, const Tree<T>& tree2);

    template<class T> class Tree {

      public:
        Tree();
        Tree(int size);
        Tree(int size, T value);
        Tree(const Tree<T>&);

        virtual ~Tree();

        T getValue() const;
        int getSize() const;
        Tree<T>* copyChilderen() const;
        
        void setValue(T value);

        Tree<T>& operator=(const Tree<T>& tree);
        bool operator==(const Tree<T>& tree) const;
        bool operator!=(const Tree<T>& tree) const;
        
        friend const Tree<T> operator+ <> (const Tree<T>& tree1, const Tree<T>& tree2);

      private:
        int size;
        int value;
        Tree* childeren;

    };

    template<class T> class Leaf : public Tree<T> {

      public:
        Leaf();
        Leaf(const T value);

    };

    template<class T> Tree<T>::Tree() : size(0) {}
    template<class T> Leaf<T>::Leaf() : Tree<T>() {}
    template<class T> Leaf<T>::Leaf(const T value) : Tree<T>(0, value) {}

    template<class T> Tree<T>::Tree(int size) : size(size) {
        if(size != 0) childeren = new Tree[size];
    }

    template<class T>
    Tree<T>::Tree(int size, T value) : size(size), value(value) {
        if(size != 0) childeren = new Tree[size];
    }

    template<class T>
    Tree<T>::Tree(const Tree<T>& tree) : size(tree.size), value(tree.value) {
        if(size != 0) childeren = new Tree[size];
        for(int i = 0; i < size; i++) childeren[i] = tree.childeren[i];
    }

    template<class T> Tree<T>::~Tree() {
        if(size > 0) delete[] childeren;
    }


    template<class T> T Tree<T>::getValue() const { return value; }
    template<class T> int Tree<T>::getSize() const { return size; }
    template<class T> void Tree<T>::setValue(T value) { this->value = value; }
    template<class T> Tree<T>* Tree<T>::copyChilderen() const {
        Tree* copy = new Tree[size];
        for(int i = 0; i < size; i++) copy[i] = childeren[i];
        return copy;
    }

    template<class T> Tree<T>& Tree<T>::operator=(const Tree<T>& tree) {
        if(size > 0) delete[] childeren;

        size = tree.size;
        value = tree.value;

        if(size > 0) childeren = tree.copyChilderen();

        return (*this);
    }

    template<class T> bool Tree<T>::operator==(const Tree<T>& tree) const {
        if(size != tree.size || value != tree.value) return false;

        int i = 0;
        while(childeren[i] == tree.childeren[i]) i++;

        return i == size;
    }

    template<class T> bool Tree<T>::operator!=(const Tree<T>& tree) const {
        return ! operator==(tree);
    }

    template<class T> const Tree<T> operator+(const Tree<T>& tree1,
    const Tree<T>& tree2) {
        if(tree1.size != tree2.size)
            throw "Operation + only for Trees of equal size.";
        int size = tree1.size;

        Tree<T> larger(size), smaller(size);
        if(tree1.value < tree2.value) { smaller = tree1; larger = tree2; }
        else { smaller = tree2; larger = tree1; }

        Tree<T> temp(size + 1, smaller.value);

        temp.childeren[0] = larger;
        for(int i = 0; i < size; i++)
            temp.childeren[i+1] = smaller.childeren[i];

        return (temp);
    }

}

#endif
