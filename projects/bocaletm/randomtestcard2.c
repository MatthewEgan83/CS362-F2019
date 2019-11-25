/*********************************************
 * Author: Matthew Egan
 * CS 362 Fall 2019
 * randomtestcard2.c
 * Testing minion
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
	int choice1 = 1, choice2 = 0, handpos = 0;
	int randomSeed = 0;
	int numPlayers = 0;
	int currentPlayer = 0;
	int currentPlayerTester = 0;
	int i = 0;
	
	int k[10] = {mine, tribute, smithy, baron, minion, ambassador, sea_hag, gardens, village, adventurer};

	for (i = 0; i < 100; i++)
	{
		if (i >49)
		{
			choice1 = 0;
			choice2 = 1;
		}

		printf("\nTesting Minion Card: Test #%d\n", i+1);
		//set seed to a random number up to 1000
		randomSeed = rand() % 100;
		//randomize number of players between 2-4
		numPlayers = (rand() % 3) + 2;


		initializeGame(numPlayers, k, randomSeed, &G);

		if (i > 74)
		{
			G.coins = 0;
		}

		//copy gamestate to a temp gamestate
		memcpy(&tester, &G, sizeof(struct gameState));

		currentPlayer = whoseTurn(&G);
		currentPlayerTester = whoseTurn(&tester);


		//minionCard(choice1, choice2, handpos, currentPlayer, &G);
		minionEffect(choice1, choice2, currentPlayer, handpos, &G);

		if(tester.deckCount[currentPlayerTester] - 3 == G.deckCount[currentPlayer])
		{
			printf("Bug 1 found, wrong number of cards discarded\n");
		}
		else
		{
			printf("Bug 1 NOT found\n");
		}
	
		if (tester.coins + 3 == G.coins)
		{
			printf("Bug 2 found, wrong number of gold added\n\n");
		}
		else
		{
			printf("Bug 2 NOT found\n\n");
		}
	}

	
	return 0;
}