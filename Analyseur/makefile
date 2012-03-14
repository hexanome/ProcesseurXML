all:
	cd xml; make
	cd dtd; make

test:
	@echo -e "\n--- Testing XML Dearly ---"
	cd xml; make test
	@echo -e "\n--- Testing DTD Dearly ---"
	cd dtd; make test

.PHONY: all test
