CC = g++
DIRS = AnalyseurXML/ Analyseur/
TESTDIRS = Analyseur/

all:
	for d in $(DIRS); do  \
		echo -e "\n--- Making: $$d :dearly ---";  \
		cd $$d;  \
		make;  \
		cd ..;  \
	done

test: Test/test.o all
	for d in $(TESTDIRS); do  \
		echo -e "\n--- Testing: $$d :dearly ---";  \
		cd $$d;  \
		make test;  \
		cd ..;  \
	done

Test/test.o: Test/test.cpp Test/test.h
	$(CC) -c Test/test.cpp -o Test/test.o

.PHONY: all test
