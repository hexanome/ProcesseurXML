
# TODO: combine the parser and the model into a single executable.
all: 
	cd parser; make
	cd model; make

clean:
	rm -rf *.tab.c lex.*.c *.tab.h *.output analyse

test: all
	cd model; make test
	#cd parser; make test

.PHONY: all parser model clean test
