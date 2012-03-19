all: analyseXML
analyseXML: *.l *.y Makefile
	flex -Pxml xml.l
	bison --debug --verbose -p xml --defines=yy.tab.h xml.y
	g++ -g -DYYDEBUG=1 -o analyseXML  lex.xml.c xml.tab.c
clean:
	rm -rf *.tab.c lex.*.c *.tab.h *.output analyseXML

.PHONY: all analyseXML clean
