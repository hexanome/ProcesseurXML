all: analyseXML
analyseXML: *.l *.y makefile
	bison --debug --verbose --defines=yy.tab.h xml.y
	g++ -g -DYYDEBUG=1 -o analyseXML  lex.yy.c  xml.tab.c
xml.l:
	flex  xml.l
clean:
	-rm -rf *.tab.c lex.*.c *.tab.h *.output analyseXML

