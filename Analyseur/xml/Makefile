PARSE_OBJ = lex.xml.o xml.tab.o xml.o
MOD_OBJ = model/Document.o model/ElementNode.o model/TextNode.o

all: $(PARSE_OBJ)
	cd parser; make
	# TODO: make the actual program.
	cd model; make

clean:
	cd parser; make clean
	cd model; make clean
	rm -rf MOD_OBJ

test: all
	cd model; make test
	g++ -o test ../../Test/test.o test.o $(PARSE_OBJ) $(MOD_OBJ)
	./test

lex.xml.o: parser
xml.tab.o: parser
xml.o: parser
parser: parser/lex.xml.c parser/xml.tab.c
	g++ -g -DYYDEBUG=1 -c parser/lex.xml.c parser/xml.tab.c test.cpp xml.cpp

.PHONY: all parser clean test

