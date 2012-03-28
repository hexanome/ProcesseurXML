MOD_OBJ = ../xml/xml.o ../dtd/dtd.o ../xml/model/Document.o ../xml/model/ElementNode.o ../xml/model/TextNode.o ../dtd/model/Element.o ../dtd/model/Attribut.o ../dtd/model/Serie.o ../dtd/model/Doctype.o ../dtd/model/Sequence.o

all:
	g++ -g -DYYDEBUG=1 -c main.cpp
	g++ -o parse main.o $(MOD_OBJ)
