#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "Time.h"
#include <string>
#include <stdexcept>
using namespace std;
/**
 * This is the constructor which will initialise the value of seconds to zero.  
 */
Time::Time( void )
{
    seconds = 0;
}
/**
 * This is the constructor which will initialise the value of seconds to seconds.  
 */
Time::Time( int _seconds )
{
    seconds = _seconds;
}
/**
 * Time constructor which will take a string in the format hh:mm:ss and convert it into seconds
 * by internally calling setTime method.   
 */
Time::Time( std::string t )
{
    setTime( t );
}
/*
 * Using ostringstream to convert from int to string. 
 */
std::string Time::str() const
{
    ostringstream oss;
    oss << seconds / 3600 << ":" << setfill('0') << setw(2) << ( seconds % 3600 ) / 60 << ":" << setfill('0') << setw(2)  << (( seconds % 3600 ) % 60);
    return oss.str();
}
/**
 * This setTime method stores the hours, minutes and seconds into string array and then
 * uses istringstream to convert string array elements into int and convert them to the seconds.  
 */
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
    {
       throw std::runtime_error("Invalid Time Entry");
    }    
    seconds = (hour * 3600)+ (min * 60) + sec;
}
/**
 * This is the overloading of < operator which will return true or false.  
 */
bool Time::operator< (const Time &t) const
{ 
    return (this->seconds < t.seconds);
}
/**
 * This is the overloading of > operator which will return true or false.  
 */
bool Time::operator> (const Time &t) const
{
    return (this->seconds > t.seconds);
}
/**
 * This is the overloading of = operator which will return true or false.  
 */
bool Time::operator= ( const Time &t)
{
     (this->seconds = t.seconds);
     return true;
}
/**
 * This is the overloading of / operator which will return int value.  
 */
int Time::operator/ (const int t) const
{
     return (int) (this->seconds / t);
}
/**
 * This is the overloading of >> operator which will take the value and  return it..  
 */
istream& operator>>(istream& in , Time& t)
{
     string str;
     in >> str;
     t.setTime(str);
     return in;
}
/**
 * This is the overloading of << operator which will print the value .  
 */
ostream& operator<<(ostream& out , const Time& t)
{
     out << t.str();
     return out;    
}
/**
 * This is the overloading of + operator which will return reference value.  
 */
Time& Time::operator+ (const Time &t)
{
     int timeResult= this->seconds + t.seconds;
     return *(new Time(timeResult));
}
/**
 * This is the overloading of == operator which will return true or false.  
 */
bool Time::operator== (const Time &t) const
{
      return this->seconds == t.seconds;
}
/**
 * This is the method which will return the value of seconds .  
 */
int Time::inSec()
{
      return seconds;
}
