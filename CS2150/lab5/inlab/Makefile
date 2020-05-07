#Boris Topalov, bnt4yb 2/24/2020

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2
DEBUG=-g
OBJECTS=BinaryNode.o BinarySearchTree.o BSTPathTest.o

a.out: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) -o a.out


BinaryNode.o: BinaryNode.cpp BinaryNode.h

BinarySearchTree.o: BinarySearchTree.cpp BinarySearchTree.h

BSTPathTest.o: BSTPathTest.cpp

.PHONY: clean

clean:
	-rm -f *.o *~ a.out


