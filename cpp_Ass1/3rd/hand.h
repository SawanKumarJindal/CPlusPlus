#ifndef _HAND_H_
#define _HAND_H_

#include "card.h"
#include <vector>
using namespace std;
class Hand
{
public:
   /**
    * Add in individual card to a player's hand 
    */
   void add( Card card );

   /**
    * Dump out a user's hand to STDOUT
    */
   void showHand();

   /**
    * Dump out the current user's hand. We check for the following
    * combinations:
    *    Four of a kind
    *    Flush (all cards the same suit)
    *    Three of a kind
    *    Two pair
    *    One pair
    */
   void check();
   /**
    * Check for "Four Of A Kind."
    */
   int checkFourOfAKind();
    
   /**
    * Check for "Flush"
    */
   int checkFlush();
    
   /**
    * Check for "Three Of A Kind"
    */
   int checkThreeOfAKind();
    
   /**
    * Check for "Two Pairs"
    */
   int checkTwoPairs();
    
   /**
    * Check for "One Pairs"
    */
   int checkOnePair();
private:
   std::vector< Card > cards;

};

#endif // _HAND_H_
