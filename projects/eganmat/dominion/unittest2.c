/*********************************************
 * Author: Matthew Egan
 * CS 362 Fall 2019
 * unittest2.c
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


	printf("\nTesting Minion Card\n");

	currentPlayer = whoseTurn(&G);
	currentPlayerTester = whoseTurn(&tester);


	minionCard(choice1, choice2, handpos, currentPlayer, &G);

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

	//initialize game again to trigger bug of adding too much gold
	initializeGame(numPlayers, k, randomSeed, &G);
	choice2 = 1;

	//copy gamestate to a temp gamestate
	memcpy(&tester, &G, sizeof(struct gameState));

	printf("\nTesting Minion Card\n");

	currentPlayer = whoseTurn(&G);
	currentPlayerTester = whoseTurn(&tester);

	minionCard(choice1, choice2, handpos, currentPlayer, &G);

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
	
	//initialize game again to trigger bug of adding too much gold
	initializeGame(numPlayers, k, randomSeed, &G);
	G.coins = 0;
	choice1 = 1;

	//copy gamestate to a temp gamestate
	memcpy(&tester, &G, sizeof(struct gameState));

	currentPlayer = whoseTurn(&G);
	currentPlayerTester = whoseTurn(&tester);

	minionCard(choice1, choice2, handpos, currentPlayer, &G);

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
		printf("Bug 2 found wrong number of gold added\n\n");
	}
	else
	{
		printf("Bug 2 NOT found\n\n");
	}
	

}