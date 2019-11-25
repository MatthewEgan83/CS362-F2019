/*********************************************
 * Author: Matthew Egan
 * CS 362 Fall 2019
 * randomtestcard1.c 
 * Testing Baron
***********************************************/


#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int main()
{
	struct gameState G, tester;
	int choice1 = 1, handpos = 0;
	int randomSeed = 1000;
	int numPlayers = 2;
	int currentPlayer = 0;
	int currentPlayerTester = 0;
	int i = 0;
	int nextPlayer = 0;
	
	int k[10] = {mine, tribute, smithy, baron, minion, ambassador, sea_hag, gardens, village, adventurer};

	for (i = 0; i < 100; i++)
	{
		if (i >49)
		{
			choice1 = 0;
		}

		printf("\nTesting Baron Card: Test #%d\n", i+1);
		//set seed to a random number up to 100
		randomSeed = rand() % 100;
		//randomize number of players between 2-4
		numPlayers = (rand() % 3) + 2;


		initializeGame(numPlayers, k, randomSeed, &G);		
		

		//copy gamestate to a temp gamestate
		memcpy(&tester, &G, sizeof(struct gameState));

		currentPlayer = whoseTurn(&G);
		nextPlayer = currentPlayer + 1;
		currentPlayerTester = whoseTurn(&tester);


		//baronCard(choice1, currentPlayer, &G);
		baronEffect(choice1, currentPlayer, nextPlayer, &G);

		if (tester.supplyCount[province] -1 == G.supplyCount[province])
		{
			printf("Bug 2 caught, province added instead of estate\n\n");
		}

		else
		{
			printf("Bug 2 not caught\n\n");
		}

		if (G.discard[currentPlayer][ G.discardCount[currentPlayer] ] == province)
		{
			printf("Bug 2 caught, province added instead of estate\n\n");
		}

		else
		{
			printf("Bug 2 not caught\n\n");
		}
	}

	
	return 0;
}