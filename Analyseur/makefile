all: analyse
analyse: *.c *.h makefile
	cd xml ; make
	cd dtd ; make
	g++ -g -DYYDEBUG=1 -o analyse xml/parser/lex.xml.c dtd/parser/lex.dtd.c xml/parser/xml.tab.c dtd/parser/dtd.tab.c main.c
clean:
	-rm -rf *.tab.c lex.*.c *.tab.h *.output analyse
