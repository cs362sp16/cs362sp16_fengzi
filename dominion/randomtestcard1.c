/***********************************
CS 362 Assignment 3 
Zixuan Feng
10/5/2016
Village test
***********************************/
#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "dominion_helpers.h"
#define NUM_TESTS 100

//This is going to judge the fault
void my_assert(int a, int b, char *c)
{
	if(a != b)
	{
		printf("Random test fail %s\n", c);
	}
}
//before main, I just set up everything, and initial all the varibles
int main(){
	int x[10] = {village, gardens, embargo, sea_hag, tribute, smithy,
		adventurer, minion, mine, cutpurse, 
     };
     int y, num = 0, players,handCount, deckCount, numActions, randSeed;

	struct gameState state;
	srand(time(NULL));

	printf("*********** village test **********\n");

	for (y=0;y<NUM_TESTS;y++)
	{
		players=4;//set up players

		randSeed=rand();//set up the random seed

		initializeGame(players, x, randSeed, &state);//initial the game state

	        state.handCount[num] = rand() % MAX_HAND;
       		state.numActions = rand() % 10 + 1;
       		state.deckCount[num] = rand() % MAX_DECK;
       		//copy the varibles 
		handCount = state.handCount[num];
		deckCount = state.deckCount[num];
		numActions = state.numActions;

		cardEffect(village, 0, 0, 0, &state,0,0);
		//print out the resulte
		my_assert(handCount, state.handCount[num], "Handcount.");
		my_assert(numActions+2, state.numActions, "numActions.");
	}

	printf("************** finished **************");
	return 0;
	}

