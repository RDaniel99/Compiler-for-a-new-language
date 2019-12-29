clean:
	lex lex.l
	yacc -d yacc.y
	gcc  y.tab.c lex.yy.c -ll -ly -o exec
	rm lex.yy.c
	rm y.tab.c
	rm y.tab.h
	clear
	./exec cod.txt

verbose:
	lex lex.l
	yacc -d yacc.y
	gcc  y.tab.c lex.yy.c -ll -ly -o exec
	rm lex.yy.c
	rm y.tab.c
	rm y.tab.h
	./exec cod.txt

debug:

	lex -d lex.l
	yacc -d yacc.y
	gcc  y.tab.c lex.yy.c -ll -ly -o exec
	rm lex.yy.c
	rm y.tab.c
	rm y.tab.h
	./exec cod.txt