//Zixuan Feng
//header files, including all the headers
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//This function is going to test draw card, whether success or fail for draw cards

//this is for judge the right or wrong.
int assert_result(int x, int y){
    if(x==y)
        return 1;
    else
        return 0;
}    

//main function
int main(){
          printf("*************start(trash Card)*************\n");
        //initial game, and go throught some case to test
          struct gameState a;
  
          int before, after;
          int k[10] = {estate, duchy, remodel, province, ambassador, adventurer, smithy, village, cutpurse, sea_hag};

          initializeGame(4, k, 2, &a);
        //test before and after card number, we could know the total number we could decide right or wrong
        before=numHandCards(&a);
        drawCard(0,&a);
        after=numHandCards(&a);

        if(!assert_result(after,before+1))
        	printf("draw card failed\n");
	printf("*************done*************\n");
        return 0;

	
    }
