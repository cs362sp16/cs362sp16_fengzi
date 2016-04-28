//ZixuanFeng
//header files, including all the headers
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//This test is going to test the great hall case, we know the great hall effect is add one action and one card
//so we just test the action and number of cards in user's hand
void my_assert(int e, char* f)
{
	if(!e)
	{
		printf("ASSERTION FAILURE: %s\n", f);
	}
}
//main function

int main(){

	
		printf("*************start(steward)*************\n");
		//initial game reset everything for game and set 10 case to run
	struct gameState G;
	
int k[10] = {great_hall, duchy, remodel, province, ambassador, adventurer, smithy, cutpurse, village, sea_hag};	
int before, after, actions_before, actions_after;
	
	initializeGame(4, k, 2, &G);

	G.hand[0][0] = great_hall;
	
	before = G.handCount[0];
	actions_before = G.numActions;
	//test cards
	playCard(1, -1, -1, -1, &G);

	after = G.handCount[0];
	actions_after = G.numActions;
	//test actions
	my_assert(after == before, "Handcounts."); //test the cars
	my_assert(actions_after == actions_before, "Actions."); //test the actions
 printf("*************done*************\n");
	
	return 0;
}