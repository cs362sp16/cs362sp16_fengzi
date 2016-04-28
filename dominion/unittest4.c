//Zixuan Feng
//header files, including all the headers
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//This test is going to test whether the game is over, we need to go through some cases and 
//test the it.
void my_assert(int i, int j, char *z)
{
	if(i!= j)
	{
		printf("Fail in  %s", z);
	}
}
//main function
int main()
{
	printf("*************start(game over)*************\n");
			//initial games
		  struct gameState a;
  
          int x;
          int k[10] = {estate, duchy, remodel, province, ambassador, adventurer, smithy, village, cutpurse, sea_hag};

	      initializeGame(2, k, 3, &a);

	      a.supplyCount[province]=0;
	      x=isGameOver(&a);
	      my_assert(x,1,"province is 0");

	      a.supplyCount[province]=5;
	      int y;
	      //set the number and test the game 

	      for(y=0;y<25;y++)
	      {
	      	if(y==5)
	      	{
	      		a.supplyCount[y]=0;
	      	}
	      	else if(y==10)
	      	{
	      		a.supplyCount[y]=0;
	      	}
	      	else if(y==15)
	      	{
	      		a.supplyCount[y]=0;
	      	}
	      	else{
	      		a.supplyCount[y]=y;
	      	}
	  	  }
	  x=isGameOver(&a);
	  my_assert(x,1,"rovince is 0");
	  for (y=5;y<=15;y++)
	  {
	  	a.supplyCount[y]=y;
	  }
	  x=isGameOver(&a);
	  my_assert(x,0,"no cards for supply");
	  printf("*************done*************\n");

	  return 0;
	}