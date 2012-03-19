all:
	flex -Pxml xml.l
	bison --debug --verbose -p xml --defines=yy.tab.h xml.y

clean:
	rm -f lex.xml.c xml.tab.c

.PHONY: all clean
