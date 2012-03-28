PARSE_OBJ = lex.xml.o xml.tab.o xml.o
MOD_OBJ = model/Document.o model/ElementNode.o model/TextNode.o ../dtd/model/Element.o ../dtd/model/Attribut.o ../dtd/model/Serie.o
TEST_EXE = test

all:
	@echo -e "\n-- XML Parser --"
	@cd parser; make
	@echo -e "\n-- XML Model --"
	@cd model; make
	# TODO: make the actual program.

clean:
	@cd parser; make clean
	@cd model; make clean
	@rm -rf $(MOD_OBJ) $(PARSE_OBJ) $(TEST_EXE)

test: all $(PARSE_OBJ)
	@cd model; make test
	@g++ -o $(TEST_EXE) ../../Test/test.o test.o $(PARSE_OBJ) $(MOD_OBJ)
	@./test

lex.xml.o: parser
xml.tab.o: parser
xml.o: parser
parser:
	@g++ -g -DYYDEBUG=1 -c parser/lex.xml.c parser/xml.tab.c test.cpp xml.cpp

.PHONY: all parser clean test
