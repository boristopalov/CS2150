

CXX=clang++ -m64

CXXFLAGS=-Wall -g

AS=nasm


ASFLAGS=-f elf64 -g

OFILES=mergeSort.o testMergeSort.o


.SUFFIXES: .o .cpp

.SUFFIXES: .o .s

testMergeSort: $(OFILES)
	$(CXX) $(CXXFLAGS) $(OFILES)


clean:
	-rm -f *.o *.~
