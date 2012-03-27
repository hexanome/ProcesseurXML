all:
	@cd dtd; make
	@cd xml; make

test:
	@echo -e "\n--- Testing DTD ---"
	@cd dtd; make test
	@echo -e "\n--- Testing XML ---"
	@cd xml; make test

.PHONY: all test
