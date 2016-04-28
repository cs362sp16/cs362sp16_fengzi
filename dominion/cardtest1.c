//ZixuanFeng
//header files, including all the headers

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//This test is going to test the smithy case, we know that smithy case add 3 cards
////This is for judge the right or wrong for functions
 void my_assert(int x, char* y)
{
	 if(!x)
       {
		 printf("card test fail: %s\n", y);
       }
 }

//main function
int main(){
	
	printf("*************start(smithy)*************\n");
	//initial game reset everything for game and set 10 case to run
	struct gameState a;
	
	int before, after;
	int k[10] = {estate, duchy, remodel, province, ambassador, adventurer, smithy, cutpurse, village, sea_hag};
	
	initializeGame(4, k, 2, &a);	
	//use smithy to test
	a.hand[0][0] = smithy;

	before = a.handCount[0];
	//count the cards, we could know our cards in hand to test
	playCard(1, -1, -1, -1, &a);
	
	after = a.handCount[0];
	
	my_assert(after == (before + 3 - 1), "cards number wrong."); 

	printf("*************done*************\n");
	
	return 0;
}







