CC = g++
EXE = test
OBJ = ElementNode.o Document.o test.o TextNode.o

all: test

test: $(OBJ)
	$(CC) -o $(EXE) $^

ElementNode.o: ElementNode.cpp ElementNode.h Node.h
Document.o: Document.cpp Document.h ElementNode.h
test.o: test.cpp Document.h commun.h
TextNode.o: TextNode.cpp TextNode.h Node.h


%.o: %.cpp
	$(CC) -c $<


clean:
	rm *.o $(EXE)


.PHONY: all clean
