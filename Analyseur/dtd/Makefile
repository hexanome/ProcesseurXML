PARSE_OBJ = lex.dtd.o dtd.tab.o dtd.o
MOD_OBJ = model/Attribut.o model/Choix.o model/ContenuCompose.o model/Definitions.o model/Document.o model/Element.o model/Sequence.o model/Serie.o
TEST_EXE = test

all:
	@echo -e "\n-- DTD Parser --"
	@cd parser; make
	@echo -e "\n-- DTD Model --"
	@cd model; make
	@# TODO: make the actual program.

clean:
	@cd parser; make clean
	@cd model; make clean
	@rm -rf $(MOD_OBJ) $(PARSE_OBJ) $(TEST_EXE)

test: all $(PARSE_OBJ)
	@cd model; make test
	@g++ -o $(TEST_EXE) ../../Test/test.o test.o $(PARSE_OBJ) $(MOD_OBJ)
	@./test

lex.dtd.o: parser
dtd.tab.o: parser
dtd.o: parser
parser:
	@g++ -g -DYYDEBUG=1 -c parser/lex.dtd.c parser/dtd.tab.c test.cpp dtd.cpp

.PHONY: all parser clean test
