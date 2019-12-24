all:
	lex lex.l
	yacc -d yacc.y
	gcc  y.tab.c lex.yy.c -ll -ly -o exec
	./exec cod.txt
	rm lex.yy.c
	rm y.tab.c
	rm y.tab.h