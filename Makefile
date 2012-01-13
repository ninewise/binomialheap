
SOURCES=main.cpp BinomialHeap.cpp
OBJECTS=$(SOURCES:.cpp=.o)

all: $(OBJECTS)
	g++ -Wall $(OBJECTS)

%.o: %.cpp
	g++ -Wall -c $< -o $@

clean:
	rm *.o a.out
