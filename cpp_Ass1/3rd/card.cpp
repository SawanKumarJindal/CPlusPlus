#include "card.h"
#include <sstream>

using namespace std;
/** 
 * Default constructor
 */
 Card::Card()
 {
 }
 /**
  * Constructor to initialize suit and value
  *
  */
 Card::Card( Card::SUITS _suit, Card::COUNT _val )
 {
     suit=_suit;
     value=_val;
 }
 /**
  *Method which will convert the value and suit to string 
  * using ostringstream. 
  */
 std::string Card::str()
 {
     ostringstream os;
     os << valToStr() << suitToStr();
     return os.str();
 }
 /**
  * Accessor to get this card's suit
  * @return value of this card
  */
 Card::SUITS Card::getSuit()
 {
     return suit;
 }
 /**
  * Accessor to get this card's value
  * @return value of this card
  */
 Card::COUNT Card::getValue()
 {
     return value;
 }
 /**
  * Method which will convert values numbered 2 to 14 to string 
  * and will return it to the calling method.
  */
 std::string Card::valToStr()
 {
     ostringstream ss;
     if(value==11)
     {
       return "J";
     }
     else if(value==12)
     {
       return "Q";
     }
     else if(value==13)
     {
       return "K";
     }
     else if(value==14)
     {
       return "A";
     }
     else
     {
       ss << value;
       return ss.str();
     }
 }
 /**
  * Method which will convert suit numbered 1 to 4 to string 
  * and will return it to the calling method.
  */
 std::string Card::suitToStr()
 {
    if(suit==1)
    {
      return "C";
    }
    else if(suit==2)
    {
      return "D";
    }
    else if(suit==3)
    {
      return "H";
    }
    else
    {
      return "S";
    }
 }
