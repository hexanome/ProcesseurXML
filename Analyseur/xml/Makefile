
# TODO: combine the parser and the model into a single executable.
all: 
	cd parser; make
	cd model; make

clean:
	rm -rf *.tab.c lex.*.c *.tab.h *.output analyse

test:
	cd model; make test

.PHONY: all parser model clean test