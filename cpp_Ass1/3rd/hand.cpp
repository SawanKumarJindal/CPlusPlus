#include "hand.h"
#include <iostream>
#include<iomanip>
using namespace std;
/**
 * Method add will add the cards of a partcular player from the back using push_back method.
 */
void Hand::add(Card card)
{
    cards.push_back(card);
}
/**
 * Method showHand will display the set of cards of a particular player.
 */
void Hand::showHand()
{
    for(int i = 0; i < cards.size() ; i++)
    {
        cout << setfill(' ')<<setw(3)<<cards[i].str()<<" ";
    }
}
/**
 * Method check will check the pattern of the cards of each player by internally calling 
 * methods checkFourOfAKind,checkFlush,checkThreeOfAKind,checkTwoPairs and checkOnePair and
 * will evaluate the category it belongs to.
 */
void Hand::check()
{	
    std::cout<<"  ";
    if((this->checkFourOfAKind())==1)
    {
        cout << "Four Of A Kind";
    }
    else if((this->checkFlush())==1)
    {
        cout << "Flush";
    }
    else if((this->checkThreeOfAKind())==1)
    {
        cout<< "Three Of A Kind";
    }
    else if((this->checkTwoPairs())==1)
    {
        cout << "Two Pair";
    }
    else if((this->checkOnePair())==1)
    {
        cout << "One Pair";	
    }
}
/**
 * Method checkFourOfAKind will check Four Of A Kind pattern which states that 
 * if four cards have the same value then it will fall into this category.
 */
int Hand::checkFourOfAKind()
{
   int count=0,count1=0;
   int  firstValue=cards[0].getValue();
   int secondValue=cards[1].getValue();
   for(int i = 0; i < cards.size() ; i++)
   {	    
       if(cards[i].getValue() == firstValue)
       {
           ++count;
       }
       if(cards[i].getValue() == secondValue)
       {
           ++count1;
       }
   }
   return ((count == 4 || count1 == 4)?1:0);
}
/**
 * Method checkFlush will check Flush pattern which states that 
 * if all five cards have the same suit then it will fall into this category.
 */
int Hand :: checkFlush()
{
    int count = 0;
    int firstSuit=cards[0].getSuit();
    for(int i = 0; i < cards.size() ; i++)
    {		    
        if(cards[i].getSuit() == firstSuit)
         {
             ++count;
         }
    }	
    return ((count == 5)?1:0);
}
/**
 * Method checkThreeOfAKind will check Three Of A Kind pattern which states that 
 * if three cards have the same value then it will fall into this category.
 */
int Hand::checkThreeOfAKind()
{
    int count=0,count1=0,count2=0;
    int  firstValue=cards[0].getValue();
    int secondValue=cards[1].getValue();
    int  thirdValue=cards[3].getValue();
    for(int i = 0; i < cards.size() ; i++)
    {		   
         if(cards[i].getValue() == firstValue )
         {
              ++count;
         }
         if(cards[i].getValue() == secondValue)
         {
              ++count1;
         }
         if(cards[i].getValue() == thirdValue)
         {
              ++count2;
         }
    }
    return((count == 3 || count1 == 3 || count2 == 3)?1:0);
}
/**
 * Method checkTwoPairs will check Two Pair pattern which states that 
 * if two pairs of two cards which have the same value then it will fall into this category.
 */
int Hand :: checkTwoPairs()
{
    int count=0;
    for(int i = 0; i < cards.size() ; i++)
    {
         for(int j=0; j< cards.size() ; j++)   
          {
               if(cards[i].getValue() == cards[j].getValue())
               {
                      ++count;
               }
          }
    }
    return ((count == 9)?1:0);
}
/**
 * Method checkOnePair will check One Pair pattern which states that 
 * if two cards have the same value then it will fall into this category.
 */
int Hand :: checkOnePair()
{
    int count = 0; 
    for(int i = 0; i < cards.size() ; i++)
    {
         for(int j=0; j< cards.size() ; j++)
         {
               if(cards[i].getValue() == cards[j].getValue())
               {
                     ++count;
                }
          }
     }
     return((count == 7)?1:0);	
}
