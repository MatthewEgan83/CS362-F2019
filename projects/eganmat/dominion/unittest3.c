/*********************************************
 * Author: Matthew Egan
 * CS 362 Fall 2019
 * unittest3.c
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
	int choice1 = 0, choice2 = 0, choice3 = 0, handpos = 0;
	int randomSeed = 1000;
	int numPlayers = 2;
	int currentPlayer = 0;
	int currentPlayerTester = 0;
	
	int k[10] = {mine, tribute, smithy, baron, minion, ambassador, sea_hag, gardens, village, adventurer};

	initializeGame(numPlayers, k, randomSeed, &G);

	//copy gamestate to a temp gamestate
	memcpy(&tester, &G, sizeof(struct gameState));


	printf("\nTesting Baron Card\n");

	currentPlayer = whoseTurn(&G);
	currentPlayerTester = whoseTurn(&tester);


	baronCard(choice1, currentPlayer, &G);
	
	if (tester.supplyCount[province] -1 == G.supplyCount[province])
	{
		printf("Bug 2 caught, province added instead of estate\n\n");
	}

	else
	{
		printf("Bug 2 not caught\n\n");
	}

	initializeGame(numPlayers, k, randomSeed, &G);
	choice1 = 1;

	//copy gamestate to a temp gamestate
	memcpy(&tester, &G, sizeof(struct gameState));


	printf("\nTesting Baron Card\n");

	currentPlayer = whoseTurn(&G);
	currentPlayerTester = whoseTurn(&tester);
	
	baronCard(choice1, currentPlayer, &G);
	if (G.discard[currentPlayer][ G.discardCount[currentPlayer] ] == province)
	{
		printf("Bug 2 caught, province added instead of estate\n\n");
	}

	else
	{
		printf("Bug 2 not caught\n\n");
	}

	return 0;
}
	