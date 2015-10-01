#include "deck.h"
#include "hand.h"
#include <vector>
#include <iostream>
#include <stdlib.h>

using namespace std;
int main()
{
   vector< Hand > hands;
   Deck deck;
   int players; 
   int seed;
   int sizeOfHand = 5;

   cout << "Enter seed: ";
   cin >> seed;
   srand(unsigned(seed));

   cout << "Enter number of players: ";
   cin >> players; 
   deck.Shuffle();
   Hand abc[players];
   /*
    * This vector named storeCards will take no of cards from the deck
    * which is equal to the no of players and the size of each hand which is fixed.
    */
   vector<Card> storeCards = deck.Deal(players * sizeOfHand);
   int position = 0;
   /*
    * This series of loops will add the cards into the vector.
    */
   for(int k = 0 ; k < sizeOfHand ; k++)
   {
       for(int i = 0 ; i < players ;i++)
       {
              abc[i].add(storeCards[position]);
              position++;
        }
    }	
   /*
    * This loop will check the condition on the cards distributed to every player.
    */
    for(int j = 0 ; j < players ;j++)
    {
         cout<< "Player "<<j+1<<" hand:  ";
         abc[j].showHand();
         abc[j].check();
         cout<<endl;
     }
}
