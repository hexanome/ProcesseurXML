CC = g++
TESTEXE = test
OBJ = ElementNode.o Document.o TextNode.o ../../dtd/model/Element.o ../../dtd/model/Attribut.o ../../dtd/model/Serie.o ../../dtd/model/Sequence.o ../../dtd/model/Doctype.o
TESTOBJ = ../../../Test/test.o test.o

all: $(OBJ) $(TESTOBJ)
	@$(CC) -o $(TESTEXE) $^

# Testing ...

test: all
	@echo "\n--- Testing xml/model ---"
	@./$(TESTEXE)

TextNode.o: TextNode.cpp TextNode.h Node.h ../../includes/common.h
ElementNode.o: ElementNode.cpp TextNode.h Node.h ../../includes/common.h
Document.o: Document.cpp Document.h ElementNode.h ../../includes/common.h  \
  ../../dtd/model/Doctype.o ../../dtd/model/Sequence.o

../../dtd/model/%.o:
	@cd ../../dtd/model ; make

%.o: %.cpp
	@$(CC) -c $<


clean:
	@rm -f *.o $(TESTEXE)


.PHONY: all test clean
