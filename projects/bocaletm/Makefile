CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/

testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

unittestresults:
	
	echo "unittest1.c:" >> unittestresults.out
	gcc -g -o unittest1 dominion.c rngs.c unittest1.c $(CFLAGS)
	./unittest1 >> unittestresults.out
	gcov dominion.c -b -f >> unittestresults.out

	echo "unittest2.c:" >> unittestresults.out
	gcc -g -o unittest2 dominion.c rngs.c unittest2.c $(CFLAGS)
	./unittest2 >> unittestresults.out
	gcov dominion.c -b -f >> unittestresults.out

	echo "unittest3.c:" >> unittestresults.out
	gcc -g -o unittest3 dominion.c rngs.c unittest3.c $(CFLAGS)
	./unittest3 >> unittestresults.out
	gcov dominion.c -b -f >> unittestresults.out

	echo "unittest4.c:" >> unittestresults.out
	gcc -g -o unittest4 dominion.c rngs.c unittest4.c $(CFLAGS)
	./unittest4 >> unittestresults.out
	gcov dominion.c -b -f >> unittestresults.out

randomtestresults:
	
	echo "randomtestcard1.c:" >> randomtestresults.out
	gcc -g -o randomtestcard1 dominion.c rngs.c randomtestcard1.c $(CFLAGS)
	./randomtestcard1 >> randomtestresults.out
	gcov dominion.c -b -f >> randomtestresults.out

	echo "randomtestcard2.c:" >> randomtestresults.out
	gcc -g -o randomtestcard2 dominion.c rngs.c randomtestcard2.c $(CFLAGS)
	./randomtestcard2 >> randomtestresults.out
	gcov dominion.c -b -f >> randomtestresults.out

	echo "randomtestcard3.c:" >> randomtestresults.out
	gcc -g -o randomtestcard3 dominion.c rngs.c randomtestcard3.c $(CFLAGS)
	./randomtestcard3 >> randomtestresults.out
	gcov dominion.c -b -f >> randomtestresults.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player 

clean:
	rm -f *.o playdom.exe playdom player player.exe  unittest1 unittest2 unittest3 unittest4 randomtestcard1 randomtestcard2 randomtestcard3 *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
