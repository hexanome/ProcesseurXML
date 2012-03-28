CC = g++
OBJ = xml/model/Document.o dtd/model/Sequence.o #main.o   # ← Is this a joke?
TESTOBJ = test.o

all: $(OBJ)
	@cd dtd; make
	@cd xml; make

xml/model/%.o: xml/model/%.cpp
	@cd xml/model; make
	
dtd/model/%.o: dtd/model/%.cpp
	@cd dtd/model; make
	
%.o: %.cpp
	@$(CC) -c $<

main.o: main.cpp main.h
test.o: test.cpp

test: all $(TESTOBJ)
	@echo -e "\n--- Testing DTD ---"
	@cd dtd; make test
	@echo -e "\n--- Testing XML ---"
	@cd xml; make test
	@$(CC) -o $(OBJ) $(TESTOBJ)

clean:
	@cd dtd; make clean
	@cd xml; make clean

.PHONY: all test clean
