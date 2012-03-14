CC = g++
TESTEXE = test
TESTOBJ = ElementNode.o Document.o ../Test/test.o test.o TextNode.o

all: analyseXML
analyseXML: *.l *.y Makefile
	flex -Pxml xml.l
	bison --debug --verbose -p xml --defines=yy.tab.h xml.y
	g++ -g -DYYDEBUG=1 -o analyseXML  lex.xml.c  xml.tab.c


# Testing ...

test: $(TESTOBJ)
	$(CC) -o $(TESTEXE) $^
	./$(TESTEXE)

ElementNode.o: ElementNode.cpp ElementNode.h Node.h
Document.o: Document.cpp Document.h ElementNode.h
test.o: test.cpp Document.h commun.h
TextNode.o: TextNode.cpp TextNode.h Node.h


%.o: %.cpp
	$(CC) -c $<


clean:
	rm *.o $(TESTEXE)
	rm -rf *.tab.c lex.*.c *.tab.h *.output analyseXML


.PHONY: all analyseXML clean
