//Zixuan Feng
//header files, including all the headers
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//This function is going to test the update Coinds function, we use the card to judge
//whether this function is right or wrong

//This is for judge the right or wrong for functions
void my_assert(int a, int b, char *c)
{
	if(a!= b)
	{
		printf("Function faild because   %s", c);
	}
}

//main function
int main()
{
	printf("*************start(update coins)*************\n");
	printf("*************if the card number is 4,5,6,3,11, then pass****\n");
	struct gameState x; //get the struct element
	
	//initial the game.
	x.hand[0][0] = copper;
	x.hand[0][1] = silver;
	x.hand[0][2] = gold;
	
	int total_coin;
	
	int y;
	for(y = 0; y < 3; y++)
	{
		//test how many cars in hand
		printf("I have these number cards in my hand: %d \n", x.hand[0][y]);
		if(x.hand[0][y] >= 0 && x.hand[0][y] <= 26)
		{
			x.handCount[0] += 1;
		}
	}
	
	printf("I have these number cards right now: %d \n", x.handCount[0]);
	
	//count the coins
	updateCoins(0, &x, 5);
	
	//count the total coins
	total_coin = x.coins;
	printf("I have these number coins: %d\n", total_coin);
	
	//assert the total coins are 11
	my_assert(total_coin, 11, "update coin.");
	
	printf("*************done*************\n");

	return 0;
}



