/*********************************************
 * Author: Matthew Egan
 * CS 362 Fall 2019
 * unittest1.c
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
	int choice1 = 0, choice2 = 1, choice3 = 0, handpos = 0;
	int randomSeed = 1000;
	int numPlayers = 2;
	int currentPlayer = 0;
	
	int k[10] = {mine, tribute, smithy, baron, minion, ambassador, sea_hag, gardens, village, adventurer};

	initializeGame(numPlayers, k, randomSeed, &G);

	printf("\nTesting Mine Card\n");

	currentPlayer = whoseTurn(&G);

	//mineCard(choice1, choice2, handpos, currentPlayer, &G);
	mineEffect(choice1, choice2, currentPlayer, handpos, &G);

	
	
	if (G.hand[currentPlayer][G.handCount[currentPlayer]] == -1)

	{
		printf("Bug 1 found, wrong card added to hand\n");
	}

	else
	{
		printf("Bug not working correctly\n");
	}

	if (G.discardCount[currentPlayer] != 1)
	{
		printf("Bug found, card not discarded\n\n");
	}

	else
	{
		printf("Bug not working correctly\n\n");
	}
	

	initializeGame(numPlayers, k, randomSeed, &G);
	choice1 = 5;
	choice2 = 6;

	printf("\nTesting Mine Card\n");

	currentPlayer = whoseTurn(&G);


	//mineCard(choice1, choice2, handpos, currentPlayer, &G);
	mineEffect(choice1, choice2, currentPlayer, handpos, &G);

	

	if (G.hand[currentPlayer][G.handCount[currentPlayer]] == -1)

	{
		printf("Bug 1 found, wrong card added to hand\n");
	}

	else
	{
		printf("Bug not working correctly\n");
	}

	if (G.discardCount[currentPlayer] != 1)
	{
		printf("Bug found, card not discarded\n\n");
	}

	else
	{
		printf("Bug not working correctly\n\n");
	}

}