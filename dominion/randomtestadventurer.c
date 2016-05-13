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

void my_assert(int a, int b, char *c)
{
	if(a != b)
	{
		printf("Random test fail %s\n", c);
	}
}

int main(){
	int x[10] = {adventurer, gardens, embargo, sea_hag, tribute, smithy,
		village, minion, mine, cutpurse, 
     };

     int y, z,num = 0, players,handCount, deckCount,randSeed;

	struct gameState state;
	srand(time(NULL));

	printf("*********** adventurer test **********\n");

	for (y = 0; y < NUM_TESTS; y++) {
		players=4;
		randSeed=rand();
		initializeGame(players, x, randSeed, &state);

		state.deckCount[num] = rand() % MAX_DECK; //Pick random deck size out of MAX DECK size
		state.discardCount[num] = rand() % MAX_DECK;//pick the random discard number
		state.handCount[num] = rand() % MAX_HAND;// pick the random handCount number

		handCount = state.handCount[num];//get the varibles
		deckCount = state.deckCount[num];//get the varibles

//some chance to make the empty
		if (randSeed % 3 == 0) {

			state.deckCount[num] = 0;
		}
//random the card 
		for (z = 0; z < state.deckCount[num]; z++){
            state.deck[num][z] = rand() % treasure_map;
        }

         for (z = 0; z < state.discardCount[num]; z++){
            state.discard[num][z] = rand() % treasure_map;
        }
		for (z = 0; z < state.handCount[num]; z++){
            state.hand[num][z] = rand() % treasure_map;
        }
//run the adventurer
        cardEffect(adventurer, 0, 0, 0, &state,0,0);
        	handCount += 2;
        				printf("result shown below:");
        				printf("%d, %d\n", handCount, state.handCount[num]);

        			my_assert(handCount, state.handCount[num], "handCount");
        		}
printf("*********finished***********\n");
return 0; 
}
