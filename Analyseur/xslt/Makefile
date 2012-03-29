CC = g++
TESTEXE = test
OBJ = transformer.o ../xml/model/Document.o ../xml/model/ElementNode.o ../xml/model/TextNode.o ../dtd/model/Doctype.o ../dtd/model/Sequence.o ../dtd/model/Serie.o ../dtd/model/Element.o ../dtd/model/Attribut.o
TESTOBJ = test.o ../../Test/test.o

all: $(OBJ) $(TESTOBJ)
	@echo "\n --- Making xslt ---"
	@$(CC) -o $(TESTEXE) $^

# Testing ...

test: all
	@echo "\n --- Testing xslt ---"
	@./$(TESTEXE)

transformer.o: transformer.cpp transformer.h ../xml/model/Document.h

../xml/model/%.o:
	@cd ../xml/model; make


%.o: %.cpp
	@$(CC) -c $<


clean:
	@rm -f *.o $(TESTEXE)


.PHONY: all test clean
