all: analyseMixte
analyseMixte: *.l *.y *.c *.h makefile
	flex -Pxml xml.l
	bison --debug --verbose -p xml --defines=xml.tab.h xml.y
	flex -Pdtd dtd.l
	bison --debug --verbose -p dtd --defines=dtd.tab.h dtd.y
	g++ -g -DYYDEBUG=1 -o analyseMixte lex.xml.c lex.dtd.c xml.tab.c dtd.tab.c main.c
clean:
	-rm -rf *.tab.c lex.*.c *.tab.h *.output analyseMixte