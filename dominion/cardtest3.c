//ZixuanFeng
//header files, including all the headers
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//This test is going to test the steward, we know the steward either get two cars, or trash cars or get two coinds
//card name: steward
//card effect: get two cards,trash two cards or get two coins.
////This is for judge the right or wrong for functions
int assert_result(int x, int y){
    if(x==y)
        return 1;
    else
        return 0;
}   
//main function

int main(){
	
		printf("*************start(steward)*************\n");
		//initial game reset everything for game and set 10 case to run
	struct gameState a;
	
	int cards1, cards2, cards3, cards;
	int k[10] = {steward, duchy, remodel, province, ambassador, adventurer, smithy, cutpurse, village, sea_hag};
	
	initializeGame(4, k, 2, &a);	
	//test the cards
	cards1=numHandCards(&a);
	cards2=a.coins;

	cards=cardEffect(steward,1,0,0,&a,0,0);
	//test the number of cards
	if(!assert_result(cards,0))
		printf("Card effect fail\n");
	else{

	cards=numHandCards(&a);

	if(!assert_result(cards,cards1+2-1))
		printf("card effect fail\n");

	cardEffect(steward,2,0,0,&a,0,0);
	//test the coins
	cards=a.coins;
	if(!assert_result(cards, cards2+2))
		printf("card effect fail\n");
	//test the trash cards
	cards3=numHandCards(&a);
	cardEffect(steward,0,0,0,&a,0,0);

	cards=numHandCards(&a);
	if(!assert_result(cards,cards3-2-1))
		printf("card effect fail\n");
		}
		
	      printf("*************done*************\n");
return 0;

}


