CC = g++
TESTEXE = test
OBJ = Attribut.o Children.o Choix.o ContenuCompose.o Contenu.o ContenuMixte.o \
      Definitions.o Document.o Element.o Sequence.o
TESTOBJ = ../../../Test/test.o test.o

all: $(OBJ) $(TESTOBJ)
	$(CC) -o $(TESTEXE) $^

# Testing ...

test: all
	./$(TESTEXE)

Attribut.o: Attribut.cpp Attribut.h ../../includes/common.h
Children.o: Children.cpp Children.h ../../includes/common.h
Choix.o: Choix.cpp Choix.h ../../includes/common.h
ContenuCompose.o: ContenuCompose.cpp ContenuCompose.h ../../includes/common.h
Contenu.o: Contenu.cpp Contenu.h ../../includes/common.h
ContenuMixte.o: ContenuMixte.cpp ContenuMixte.h ../../includes/common.h
Definitions.o: Definitions.cpp Definitions.h ../../includes/common.h
Document.o: Document.cpp Document.h ../../includes/common.h
Element.o: Element.cpp Element.h ../../includes/common.h
Sequence.o: Sequence.cpp Sequence.h ../../includes/common.h

%.o: %.cpp
	$(CC) -c $<


clean:
	rm *.o $(TESTEXE)


.PHONY: all test clean
