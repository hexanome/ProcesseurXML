CC = g++
DIRS = AnalyseurXML/ Analyseur/
TESTDIRS = Analyseur/

all:
	@for d in $(DIRS); do  \
		echo; echo "--- Making the $$d ---";  \
		cd $$d;  \
		make;  \
		cd ..;  \
	done

test: Test/test.o
	@for d in $(TESTDIRS); do  \
		echo; echo "--- Dealing with $$d ---";  \
		cd $$d;  \
		make test;  \
		cd ..;  \
	done

clean:
	@rm -f Test/test.o
	@cd Analyseur; make clean

Test/test.o: Test/test.cpp Test/test.h
	@$(CC) -c Test/test.cpp -o Test/test.o

.PHONY: all test
