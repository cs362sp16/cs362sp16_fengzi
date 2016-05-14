/***********************************
CS 362 Assignment 3 
Zixuan Feng
10/5/2016
smithy test
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

int main(int argc, char* argv[]){
	int x[10] = {smithy,gardens, embargo, sea_hag, tribute, village, adventurer, minion, mine, cutpurse };
     int y, num = 0, players,handCount,randSeed;

	struct gameState state;

	srand(time(NULL));
		if(argv[1]!=NULL)
		randSeed = atoi(argv[1]);
	else
		randSeed = rand()%10 + 1;

	printf("*********** smithy test **********\n");

	for (y=0;y<NUM_TESTS;y++)
	{
		players=4;//set up players

		randSeed=rand();

		initializeGame(players, x, randSeed, &state);//initial the game state

		state.handCount[num] = rand() % MAX_HAND;

		handCount = state.handCount[num];

		cardEffect(smithy, 0, 0, 0, &state,0,0);


		my_assert(handCount+2, state.handCount[num], "Handcount.");

	}
		printf("************** finished **************");
	return 0;
	}
