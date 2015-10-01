#include "deck.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/**
 * Default constructor. This will shuffle the deck.
 */
Deck::Deck()
{
   Shuffle();
}
/**
 * This method shuffle will take all cards and will shuffle them using random_shuffle.
 */
void Deck::Shuffle()
{
   cards.erase(cards.begin(), cards.end());
   for ( int i = Card::CLUBS; i <= Card::SPADES; i++ )
   {
      for ( int j = Card::TWO; j <= Card::ACE; j++ )
      {
         cards.push_back( Card(Card::SUITS(i),Card::COUNT(j)));
      }
   }
   random_shuffle ( cards.begin(), cards.end() );
}
/**
 * This method will display the card remaining on the deck.
 */
void Deck::ShowDeck()
{
  int i=1;
  cout << cards[i].str();
}
/**
 * This method will input the cards to the myVector vector.
 */
vector<Card> Deck::Deal(int count)
{
     vector<Card> myVector(count);
     vector<Card>::iterator iter;
     int position=0;
     for(iter=cards.begin();iter!=cards.end();iter++)
     {
         myVector.at(position)=cards.at(position);
         position +=1;
         if(position >= count)
         {
              break;
         }  
     }
     return myVector;
}
