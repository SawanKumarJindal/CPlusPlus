/**
 * Time.cpp
 * For use with 4003-703-01, Homework 2
 * Winter 2012
 * Department of Computer Science
 * Rochester Institute of Technology
 * Author: Travis Brown
 */
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "Time.h"
#include <string>

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

Time Time::add( Time t )
{
   return seconds += t.seconds;
}

Time Time::subtract( Time t )
{
   return seconds -= t.seconds;
}

std::string Time::str() const
{
   /* Use ostringstream to convert from int to string. This will be covered in
    * detail in week 8
    */
   ostringstream oss;
   oss << seconds / 3600 << ":" << setfill('0') << setw(2) << ( seconds % 3600 ) / 60;
   return oss.str();

}

void Time::setTime( std::string t )
{
		std::string strSecond = "0";
		std::string strHour = "0";
		seconds = 0 ;
		bool foundSeconds = false;
		strSecond = "0";
		strHour = "0";
//		t = "12:23";
//		cout << t;
		for(int loop1 = 0 ; loop1 < t.length() ; loop1++)
		{
	
//			cout << t.at(loop1) << endl;
			if(t.at(loop1) == ':'){
				foundSeconds = true;	
				continue;
				} 
			if(foundSeconds == true)
			{
				strSecond = strSecond + t.at(loop1);
				//cout << "strSeconds  " << strSecond <<  "  at " << t.at(loop1) << "   " ;
			}
			else
			{
				strHour = strHour + t.at(loop1);
				//cout << "strHour  " << strHour <<  "  at " << t.at(loop1) << "   " ;
			}
		}
		//std::string::size_type sz;
		int hours , minutes ;
		hours = minutes = 0;
//		std::cout << "hours : " << strHour  << endl << " Min " << strSecond << endl;
/*		for(int loop1 = 0; loop1 <  strHour.length(); loop1++)
		{
			hours = (((int)strHour.at(loop1) - 48) + hours) * 10;
	//		cout << ((int)strHour.at(loop1) - 48) << endl << "  ";
		}
		hours = hours / 10;
	//	cout << "final hours : " << hours << endl;
		for(int loop1 = 0; loop1 <  strSecond.length(); loop1++)
		{
			minutes = (((int)strSecond.at(loop1) - 48) + minutes) * 10; 
		//	cout << ((int)strSecond.at(loop1) - 48) << endl << "  ";
		}
		minutes = minutes / 10;
*/
//	cout << strHour << endl << strSecond << endl;
	std::istringstream iHour (strHour);
    	iHour >> hours;
	std::istringstream iMin (strSecond);
        iMin >> minutes;
//	cout << hours << minutes << endl;

		//cout << "final min : " << minutes << endl;
		seconds =(hours*3600) + (minutes*60);
}

