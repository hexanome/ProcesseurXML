CC = g++
TESTEXE = test
OBJ = ElementNode.o Document.o TextNode.o
TESTOBJ = ../../../Test/test.o test.o

all: $(OBJ) $(TESTOBJ)
	$(CC) -o $(TESTEXE) $^

# Testing ...

test: all
	./$(TESTEXE)

ElementNode.o: ElementNode.cpp ElementNode.h Node.h
Document.o: Document.cpp Document.h ElementNode.h
TextNode.o: TextNode.cpp TextNode.h Node.h
test.o: test.cpp Document.h commun.h


%.o: %.cpp
	$(CC) -c $<


clean:
	rm *.o $(TESTEXE)


.PHONY: all test clean
