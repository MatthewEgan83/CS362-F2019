/*********************************************
 * Author: Matthew Egan
 * CS 362 Fall 2019
 * randomtestcard3.c 
 * Testing Tribute
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
	int randomSeed = 0;
	int numPlayers = 2;
	int currentPlayer = 0;
	int currentPlayerTester = 0;
	int i = 0;
	
	int k[10] = {mine, tribute, smithy, baron, minion, ambassador, sea_hag, gardens, village, adventurer};

	for (i = 0; i < 100; i++)
	{
		printf("\nTesting Tribute Card: Test #%d\n", i+1);
		//set seed to a random number up to 100
		randomSeed = rand() % 100;
		//randomize number of players between 2-4
		numPlayers = (rand() % 3) + 2;


		initializeGame(numPlayers, k, randomSeed, &G);		
		

		//copy gamestate to a temp gamestate
		memcpy(&tester, &G, sizeof(struct gameState));

		currentPlayer = whoseTurn(&G);
		currentPlayerTester = whoseTurn(&tester);

		int nextPlayer = currentPlayer + 1;


		tributeCard(currentPlayer,nextPlayer, &G);

		if (tester.coins + 2 == G.coins)
		{
			printf("Treasure card revealed, two gold/coins added\n");
		}

		else if (tester.handCount + 2 == G.handCount)
		{
			printf("Victory card revealed, two cards added\n");
		}


		else if (tester.numActions + 2 == G.numActions)
		{
			printf("Action card revealed, two actions added\n");
		}

		else
		{
			printf("No cards revealed\n");
		}
		
	}

	
	return 0;
}