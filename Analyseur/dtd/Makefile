
# TODO: combine the parser and the model into a single executable.
all: parser model

parser:
	flex -Pxml xml.l
	bison --debug --verbose -p xml --defines=yy.tab.h xml.y
	g++ -g -DYYDEBUG=1 -o analyse xml/parser/lex.xml.c dtd/parser/lex.dtd.c xml/parser/xml.tab.c dtd/parser/dtd.tab.c main.c

model:
	cd model; make
	#cd model; make

clean:
	rm -rf *.tab.c lex.*.c *.tab.h *.output analyse

test:
	#cd model; make test
	#cd parser; make test
	

.PHONY: all parser model clean test
