

all: test

test: test.o

ElementNode.o: ElementNode.cpp ElementNode.h
Document.o: Document.cpp Document.h
test.o: test.cpp
TextNode.o: TextNode.cpp TextNode.h


%.o: %.cpp
	gcc -c $<


.PHONY: all test
