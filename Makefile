CC = g++
DIRS = AnalyseurXML/ Analyseur/
TESTDIRS = Analyseur/

all:
	@for d in $(DIRS); do  \
		echo "--- Making: $$d ---";  \
		cd $$d;  \
		make;  \
		cd ..;  \
	done

test: Test/test.o all
	@for d in $(TESTDIRS); do  \
		echo "--- Testing: $$d ---";  \
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
