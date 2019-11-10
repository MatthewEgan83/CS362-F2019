default: testme

testme:
	gcc -Wall -fpic -coverage -lm -std=c99 -o testme testme.c
	./testme

cleanall: 
	rm testme *.gcda *.gcno *.gcov