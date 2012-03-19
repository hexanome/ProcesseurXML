all: analyseDTD
analyseDTD: *.l *.y makefile
	flex -Pdtd dtd.l
	bison --debug --verbose -p dtd --defines=yy.tab.h dtd.y
	g++ -g -DYYDEBUG=1 -o analyseDTD  lex.dtd.c dtd.tab.c 
clean:
	-rm -rf *.tab.c lex.*.c *.tab.h *.output analyseDTD

