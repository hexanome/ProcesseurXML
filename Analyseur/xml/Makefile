
# TODO: combine the parser and the model into a single executable.
all: 
	cd parser; make
	cd model; make
	#cd parser; make

clean:
	rm -rf *.tab.c lex.*.c *.tab.h *.output analyse

test:
	cd model; make test
	#cd parser; make test

.PHONY: all parser model clean test
