all:
	flex -Pdtd dtd.l
	bison --debug --verbose -p dtd --defines=yy.tab.h dtd.y

clean:
	rm -f lex.xml.c xml.tab.c

.PHONY: all clean
