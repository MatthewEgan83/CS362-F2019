/*********************************************
 * Author: Matthew Egan
 * CS 362 Fall 2019
 * unittest4.c
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


	printf("\nTesting Ambassador Card\n");

	currentPlayer = whoseTurn(&G);
	currentPlayerTester = whoseTurn(&tester);

	ambassadorCard(choice1, choice2, handpos, currentPlayer, &G);

	return 0;
}