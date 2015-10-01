/**
 * main.cpp
 * For use with 4003-703-01, Homework 2
 * Winter 2012
 * Department of Computer Science
 * Rochester Institute of Technology
 * Author: Travis Brown
 */
#include "Time.h"
#include <iostream>

using namespace std;

/* Your code here */

int main()
{
   string str;
   string strTime;
   bool isOperand;
   string strOperator;
   string strOperand;
   isOperand = false;
   do
   {
      getline( cin, str );
      strOperand = "00:00";
      strOperator = "+";
      Time t("00:00");
       strTime = "";
       Time *t1;
	  bool bln;
	  str = "+ " + str;
	  str = str + " ";
	  for(int loop1 = 0 ; loop1 < str.length() ; loop1++)
	  {
	  
		  if(str.at(loop1) == ' ')
			{
				isOperand = false;
				if(strTime == "+" || strTime == "-")
				{
					strOperator = strTime;
					isOperand = true; 
				//	cout << "In isTime false " << "strOperand " << strOperand << "strOperator " << strOperator << endl;
				}
				else
				{	isOperand = false;
					strOperand = strTime;		
					//cout << "In isTime true " << "strOperand " << strOperand << "strOperator " << strOperator << endl;
				}

				if(strOperator == "+" && isOperand == false)
				{
					Time t1(strOperand);
					t.add(t1);
				//cout << "In add " << "strOperand " << strOperand << "strOperator " << strOperator << endl;
				}
				else if(strOperator == "-" && isOperand == false)
				{
					Time t1(strOperand);
					t.subtract(t1);
					//cout << "In subtract " << "strOperand " << strOperand << "strOperator " << strOperator << endl;
					
				}

				strTime = "";
				continue;
			}
		else
		{	strTime = strTime + str.at(loop1);}
			//cout<< " strTime in else " << strTime << endl;
	  }
	cout << t.str() << endl;
   } while ( !cin.eof() );

	return 0;
}
