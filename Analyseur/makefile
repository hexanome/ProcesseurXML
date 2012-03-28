CC = g++
OBJ = xml/model/Document.o dtd/model/Sequence.o dtd/model/Doctype.o xml/model/ElementNode.o xml/model/TextNode.o dtd/model/Element.o dtd/model/Attribut.o dtd/model/Serie.o dtd/model/ContenuCompose.o dtd/model/Choix.o xml/lex.xml.o xml/xml.tab.o xml/xml.o dtd/lex.dtd.o dtd/dtd.tab.o dtd/dtd.o
TESTOBJ = test.o ../Test/test.o

all: $(OBJ)
	@cd dtd; make
	@cd xml; make

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

test: $(TESTOBJ)
	@echo -e "\n--- Testing DTD ---"
	@cd dtd; make test
	@echo -e "\n--- Testing XML ---"
	@cd xml; make test
	@$(CC) -o test $(OBJ) $(TESTOBJ)
	@./test

clean:
	@rm -f *.o ./test
	@cd dtd; make clean
	@cd xml; make clean

.PHONY: all test clean
