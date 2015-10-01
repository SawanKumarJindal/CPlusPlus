#ifndef __TIME_H__
#define __TIME_H__
#include <string>
using namespace std;
class Time
{
     public:
     Time();
     Time( std::string time );
     Time( int _seconds );
     void setTime( std::string time );
     std::string str() const;
     bool operator< (const Time &t) const;
     bool operator> (const Time &t) const;
     bool operator= (const Time &t);
     int operator/(const int t) const;
     Time& operator+ (const Time &t);
     bool operator== (const Time &t) const;
     friend std::ostream& operator<<(std::ostream& , const Time& );
     friend std::istream& operator>>(std::istream& , Time&);
     int inSec();
     private:
     int seconds;
};
#endif
