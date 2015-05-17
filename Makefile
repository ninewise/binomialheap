
CC=g++
CPPFLAGS=-Wall

all: main

main: main.o BinomialHeap.o BinomialTree.o
main.o: main.cpp BinomialHeap.h
BinomialHeap.o: BinomialHeap.cpp BinomialHeap.h BinomialTree.h
BinomialTree.o: BinomialTree.cpp BinomialTree.h

clean:
	rm -f *.o main

run: main
	./main
