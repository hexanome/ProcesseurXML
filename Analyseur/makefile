CC = g++
OBJ = xml/model/Document.o dtd/model/Sequence.o dtd/model/Doctype.o xml/model/ElementNode.o xml/model/TextNode.o dtd/model/Element.o dtd/model/Attribut.o dtd/model/Serie.o dtd/model/ContenuCompose.o dtd/model/Choix.o xml/lex.xml.o xml/xml.tab.o xml/xml.o dtd/lex.dtd.o dtd/dtd.tab.o dtd/dtd.o
TESTOBJ = test.o ../Test/test.o

all: $(OBJ)
	@cd dtd; make
	@cd xml; make
	@cd xslt; make

xml/model/%.o: xml/model/%.cpp
	@cd xml/model; make
xml/%.o:
	@cd xml/model; make

dtd/model/%.o: dtd/model/%.cpp
	@cd dtd/model; make
dtd/%.o:
	@cd dtd/model; make

%.o: %.cpp
	@$(CC) -c $<

main.o: main.cpp main.h
test.o: test.cpp

tool:
	$(CC) -c tool/main.cpp
	$(CC) -o parse tool/main.o $(OBJ)

test: $(TESTOBJ)
	@cd dtd; make test
	@cd xml; make test
	@cd xslt; make test
	@echo "--- Testing Analyseur ---"
	@$(CC) -o test $(OBJ) $(TESTOBJ)
	@./test

clean:
	@rm -f *.o ./test
	@cd dtd; make clean
	@cd xml; make clean
	@cd xslt; make clean

.PHONY: all test clean tool
