#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#define NUM_TESTS 100

int isUnique_k(int a, int * b)
{	
	int i;
	for (i = 0; i < 10; i++) {
		if (i != a && b[a] == b[i])
			return 0;
	}
	return 1;
}



int check_money(struct gameState *p)
	{
			int i, money=0;
    		for (i = 0; i < numHandCards(p); i++){			
    			if (handCard(i, p) == copper){
   	 				money++;
   	 			}
   	   			else if (handCard(i, p) == silver){
    				money += 2;
				}
    	 		else if (handCard(i, p) == gold){
    				money += 3;
    			}
   	   			else 
   	   				money +=0;
   	 		
   	 		}
   	 		return money;
  }	

int check_end(struct gameState *p)
		{
      			
      		int i, users=0;/* data */
    		printf("Player %i: end turn\n", whoseTurn(p));
      		endTurn(p);
			for (i = 0; i < users; i++){
      			printf ("Score for Player %d: %d\n", i, scoreFor(i, p));   //end turn section  
	    	}
	    	return 0;
		} 

int check_buy(struct gameState *p)
	{
				/* data */
			int money=0;
			int testbuy=0;
      		if (money >= 8) {                                        //buy 
        		printf("Player %i: bought province\n", whoseTurn(p)); 
        		buyCard(province, p);
      		}
      		else if (money >= 6) {
        		printf("Player %i: bought gold\n", whoseTurn(p));
    			buyCard(gold, p);
      		}     			
      		else if (money >= 3) {
        		printf("Player %i: bought silver\n", whoseTurn(p));
        		buyCard(silver, p);
      		}
			else {
       			testbuy = rand() % (treasure_map + 1);
       			if (buyCard(testbuy, p) == 0)
					printf("\t\tBought Card %d.\n", testbuy);
				else {
					printf("\t\tNo other cards were bought this turn.\n");
					//break;
				}
      		}
      		return money;
      }

int main () {
	struct gameState G;
	struct gameState *p = &G;
  	int k[10];
	int users;
	int x;
	srand(time(NULL));
	x = rand();
  	printf ("Starting game.\n");
  	int i, z, r;
  	for (z = 0; z < NUM_TESTS; z++){
  		users = rand() % 3 + 2; //not less than 2 or greater than 4 players	
  		printf("num_players: %d\n", users);
  		for (i = 0; i < 10; i++){
  			do {
				k[i] = rand() % (treasure_map - 7 + 1) + 7;
			} while (!isUnique_k(i, k));
  		}
  
  		initializeGame(users, k, x, p);
  
  		int money = 0;
  		int effect = -1;
		int whoturn = 1;
		  	

  		while (!isGameOver(p)) {
  			printf("Turn #%d\n", whoturn++);
  	 		money = check_money(p);
   	 		effect = -1;

    	    check_money(p);
   	 	   	
	
      		if (effect != -1) {
      			
				r = playCard(effect, -1, -1, -1, p); 			
				if (r == -1)
					printf("\t\tcard play failed\n");
				else
					printf("\t\tcard play successful\n");
						
				money = 0;
				i=0;

				check_money(p);

  			}
      		    				
      	  check_buy(p);
    	  check_end(p);
		}  //end of While
	
  		printf ("Finished game.\n");
		for (i = 0; i < users; i++){
      		printf ("Score for Player %d: %d\n", i, scoreFor(i, p));
		}
	}
	return 0;
}
