//Zixuan Feng
//header files, including all the headers
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//This fucntion is goind to test trash cars right or wrong

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
          //initial games reset, and go through some cases to test the unit
          struct gameState a;
  
          int before, after;
          int k[10] = {estate, duchy, remodel, province, ambassador, adventurer, smithy, village, cutpurse, sea_hag};

          initializeGame(4, k, 2, &a);
          //Test the total number in hand, and we could know right or wrong when we trash cards
          before=numHandCards(&a);
          discardCard(0,0,&a,0);
          after=numHandCards(&a);

          if(!assert_result(after,before-1))
          	printf("function failed\n");

          printf("*************done*************\n");

          return 0;
      }