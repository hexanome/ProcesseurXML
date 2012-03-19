CC = g++
TESTEXE = test
OBJ = ElementNode.o Document.o TextNode.o
TESTOBJ = ../../../Test/test.o test.o

all: $(OBJ) $(TESTOBJ)
	$(CC) -o $(TESTEXE) $^

# Testing ...

test: all
	./$(TESTEXE)

TextNode.o: TextNode.cpp TextNode.h Node.h ../../includes/common.h
ElementNode.o: ElementNode.cpp TextNode.h Node.h ../../includes/common.h
Document.o: Document.cpp Document.h ElementNode.h ../../includes/common.h

%.o: %.cpp
	$(CC) -c $<


clean:
	rm -f *.o $(TESTEXE)


.PHONY: all test clean
