
# TODO: combine the parser and the model into a single executable.
all: 
	cd parser; make
	cd model; make

clean:
	rm -rf *.tab.c lex.*.c *.tab.h *.output analyse

test: all
	cd model; make test
	g++ -g -DYYDEBUG=1 -o test parser/lex.xml.c parser/xml.tab.c test.cpp

.PHONY: all parser model clean test
