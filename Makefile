CC = g++
DIRS = AnalyseurXML/

all:
	for d in $(DIRS); do cd $$d; make; cd ..; done

test: Test/test.o all
	for d in $(DIRS); do cd $$d; make test; cd ..; done

Test/test.o: Test/test.cpp Test/test.h
	$(CC) -c Test/test.cpp -o Test/test.o

.PHONY: all test
