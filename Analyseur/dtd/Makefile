CC = g++
CCFLAGS = -Wno-write-strings
PARSE_OBJ = lex.dtd.o dtd.tab.o dtd.o
MOD_OBJ = model/Attribut.o model/Choix.o model/ContenuCompose.o model/Doctype.o model/Element.o model/Sequence.o model/Serie.o
TEST_EXE = test

all:
	@echo "-- Making: DTD Parser --"
	@cd parser; make
	@make parser
	@echo "-- Making: DTD Model --"
	@cd model; make

clean:
	@cd parser; make clean
	@cd model; make clean
	@rm -f test.o
	@rm -rf $(MOD_OBJ) $(PARSE_OBJ) $(TEST_EXE)

test: all $(PARSE_OBJ)
	@cd model; make test
	@echo "--- Testing dtd ---"
	@g++ -o $(TEST_EXE) ../../Test/test.o test.o $(PARSE_OBJ) $(MOD_OBJ)
	@./test

lex.dtd.o: parser
dtd.tab.o: parser
dtd.o: parser
	

parser:
	@$(CC) $(CCFLAGS) -g -DYYDEBUG=1 -c parser/lex.dtd.c parser/dtd.tab.c test.cpp dtd.cpp

.PHONY: all parser clean test
