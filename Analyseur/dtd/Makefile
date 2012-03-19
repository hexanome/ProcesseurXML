
# TODO: combine the parser and the model into a single executable.
all: parser model

parser:
	flex -P dtd dtd.l
	bison --debug --verbose -p dtd --defines=yy.tab.h dtd.y

model:
	cd model; make

clean:
	rm -rf *.tab.c lex.*.c *.tab.h *.output analyse

test:	

.PHONY: all parser model clean test