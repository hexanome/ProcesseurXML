CC = g++
TESTEXE = testXSLT
OBJ = transformer.o ../xml/model/Document.o
TESTOBJ = test.o

all: $(OBJ) $(TESTOBJ)
	@$(CC) -o $(TESTEXE) $^

# Testing ...

test: all
	@./$(TESTEXE)

transformer.o: transformer.cpp transformer.h ../xml/model/Document.h

../xml/model/%.o:
	@cd ../xml/model; make

%.o: %.cpp
	@$(CC) -c $<


clean:
	@rm -f *.o $(TESTEXE)


.PHONY: all test clean
