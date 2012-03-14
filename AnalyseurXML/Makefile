EXE = test
OBJ = ElementNode.o Document.o test.o TextNode.o

all: test

test: $(OBJ)
	gcc -o $(EXE) $<

ElementNode.o: ElementNode.cpp ElementNode.h
Document.o: Document.cpp Document.h
test.o: test.cpp
TextNode.o: TextNode.cpp TextNode.h


%.o: %.cpp
	gcc -c $<


.PHONY: all
