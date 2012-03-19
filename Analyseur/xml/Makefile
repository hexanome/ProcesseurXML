
# TODO: combine the parser and the model into a single executable.
all: 
	cd parser; make
	cd model; make

clean:
	rm -rf *.tab.c lex.*.c *.tab.h *.output analyse

test: all
	cd model; make test
	g++ -g -DYYDEBUG=1 -c parser/lex.xml.c parser/xml.tab.c test.cpp
	g++ -o test ../../Test/test.o test.o lex.xml.o xml.tab.o model/Document.o model/ElementNode.o model/TextNode.o
	./test

.PHONY: all parser model clean test
