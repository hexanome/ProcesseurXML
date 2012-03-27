all:
	@cd dtd; make
	@cd xml; make

test:
	@echo -e "\n--- Testing DTD ---"
	@cd dtd; make test
	@echo -e "\n--- Testing XML ---"
	@cd xml; make test

clean:
	@cd dtd; make clean
	@cd xml; make clean

.PHONY: all test clean
