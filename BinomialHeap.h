
#ifndef BINOMIAL_HEAP_H
#define BINOMIAL_HEAP_H

namespace integered {

    class Element {

      public:
        Element(const int size);

      private:
        const int size;

    }

    class Leaf : public Element {

      private:
        int value;

    }

    class Root : public Element {

      private:
        Element* small;
        Element* large;

    }

}

#endif
