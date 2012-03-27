CC = g++
TESTEXE = test
OBJ = Attribut.o Serie.o Choix.o ContenuCompose.o \
      Doctype.o Element.o Sequence.o
TESTOBJ = ../../../Test/test.o test.o

all: $(OBJ) $(TESTOBJ)
	$(CC) -o $(TESTEXE) $^

# Testing ...

test: all
	@./$(TESTEXE)

Attribut.o: Attribut.cpp Attribut.h ../../includes/common.h
Serie.o: Serie.cpp Serie.h ../../includes/common.h
Choix.o: Choix.cpp Choix.h ../../includes/common.h
ContenuCompose.o: ContenuCompose.cpp ContenuCompose.h ../../includes/common.h
Doctype.o: Doctype.cpp Doctype.h ../../includes/common.h
Element.o: Element.cpp Element.h ../../includes/common.h
Sequence.o: Sequence.cpp Sequence.h ../../includes/common.h
test.o: test.cpp

%.o: %.cpp
	@$(CC) -c $<


clean:
	@rm *.o $(TESTEXE)


.PHONY: all test clean
