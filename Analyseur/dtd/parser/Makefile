all:
	@flex -Pdtd dtd.l
	@bison --debug --verbose -p dtd --defines=yy.tab.h dtd.y
