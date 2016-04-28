 //ZixuanFeng
//header files, including all the headers
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//This test is going to test the village whether the village is wrong, we know the village could add card and 2 actions
////This is for judge the right or wrong for functions


void my_assert(int c, char* d)
{
	if(!c)
	{
		printf("card failed on %s\n",d);
	}
}
//main function

int main(){
		printf("*************start(village)*************\n");
	//initial game reset everything for game and set 10 case to run
 
         struct gameState a;
  
          int before, after,actions_before, actions_after, pcBefore, pcAfter;
          int k[10] = {estate, duchy, remodel, province, ambassador, adventurer, smithy, village, cutpurse, sea_hag};
  
          initializeGame(4, k, 2, &a);
  			//use the village function to test
          a.hand[0][0] = village;

          actions_before = a.numActions;
		  pcBefore = a.playedCardCount;
	      before = a.handCount[0];
		//test the card number
		  playCard(1, -1, -1, -1, &a);
	
	      actions_after = a.numActions;
	      pcAfter = a.playedCardCount;
	      after = a.handCount[0];
		//test the action
	      my_assert(actions_after == (actions_before - 1 + 2),"action faile"); 
	      my_assert(pcAfter == (!(pcBefore + 1)),"card fail");
	      my_assert(after == before,"card number fail"); 
		printf("pcAfter is %d, pcBefore is %d\n", pcAfter, pcBefore);
	      printf("*************done*************\n");

	return 0;
}	
