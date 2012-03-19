all:
	cd xml; make
	cd dtd; make

test:
	@echo -e "\n--- Testing XML dearly ---"
	cd xml; make test
	@echo -e "\n--- Testing DTD dearly ---"
	cd dtd; make test

.PHONY: all test
