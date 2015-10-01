#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "Time.h"
#include <string>
#include <stdexcept>
using namespace std;

Time::Time( void )
{
    seconds = 0;
}

Time::Time( int _seconds )
{
    seconds = _seconds;
}

Time::Time( std::string t )
{
    setTime( t );
}
/* Use ostringstream to convert from int to string. This will be covered in
 * detail in week 8
 */
std::string Time::str() const
{
    ostringstream oss;
    oss << seconds / 3600 << ":" << setfill('0') << setw(2) << ( seconds % 3600 ) / 60 << ":" << setfill('0') << setw(2)  << (( seconds % 3600 ) % 60);
    return oss.str();
}

void Time::setTime( std::string t )
{
 
   string array[3],temp_string;
   int i=0,hour=0,min=0,sec=0; 
    stringstream iss(t);
	
    while( getline(iss, temp_string, ':'))
    {
        array[i]=temp_string;
        i++;
    }
    istringstream iss1(array[0]);
    iss1 >> hour;
    istringstream iss2(array[1]);
    iss2 >> min;
    istringstream iss3(array[2]);
    iss3 >> sec;
    if(hour < 0 || sec < 0 || sec >=60 || min < 0 || min >=60)
       throw std::runtime_error("Invalid Time Entry");    
    seconds = (hour * 3600)+ (min * 60) + sec;
}

bool Time::operator< (const Time &t) const
{ 
    return (this->seconds < t.seconds);
}

bool Time::operator> (const Time &t) const
{
    return (this->seconds > t.seconds);
}

bool Time::operator= ( const Time &t)
{
     (this->seconds = t.seconds);
     return true;
}

int Time::operator/ (const int t) const
{
    return (int) (this->seconds / t);
}
istream& operator>>(istream& in , Time& t)
{
	    string str;
	    in >> str;
	    t.setTime(str);
		return in;
}
  ostream& operator<<(ostream& out , const Time& t)
  {
	  out << t.str();
	  return out;    
  }
  Time& Time::operator+ (const Time &t)
  {
	  int timeResult= this->seconds + t.seconds;
	  
	  return *(new Time(timeResult));
  }
       bool Time::operator== (const Time &t) const
       {
		   return this->seconds == t.seconds;
	   }
	   
	int Time::inSec()
	{
			return seconds;
	}
	

