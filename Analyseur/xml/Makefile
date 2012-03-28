PARSE_OBJ = lex.xml.o xml.tab.o xml.o
MOD_OBJ = model/Document.o model/ElementNode.o model/TextNode.o ../dtd/model/Element.o ../dtd/model/Attribut.o ../dtd/model/Serie.o ../dtd/model/Doctype.o ../dtd/model/Sequence.o
TEST_EXE = test

all:
	@echo; echo "-- Making: XML Parser --"
	@cd parser; make
	@make parser
	@echo; echo "-- Making: XML Model --"
	@cd model; make

clean:
	@cd parser; make clean
	@cd model; make clean
	@rm -f test.o
	@rm -rf $(MOD_OBJ) $(PARSE_OBJ) $(TEST_EXE)

test: all $(PARSE_OBJ)
	@cd model; make test
	@g++ -o $(TEST_EXE) ../../Test/test.o test.o $(PARSE_OBJ) $(MOD_OBJ)
	@./test

lex.xml.o: parser
xml.tab.o: parser
xml.o: parser
	

parser:
	@g++ -Wno-write-strings -g -DYYDEBUG=1 -c parser/lex.xml.c parser/xml.tab.c test.cpp xml.cpp

.PHONY: all parser clean test
