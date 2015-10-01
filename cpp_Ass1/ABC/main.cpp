#include <iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<map>
#include<cstdlib>
using namespace std;
/*
 * This is the main method which will first take the file value and 
 * with each string at a time and parsing over it character-wise,
 * it will it will detect non-alphabetic characters. If the non-alphabetic character
 * is "'" then it will check whether it contains the same character at the end. If yes, 
 * it will remove both the characters else it will not change the string. With other 
 * non-alphabetic characters it will take the characters before that and then the resultant 
 * character will first checked whether it is already in the map or not. If yes, 
 * then it will increase its count value else it will add it in the map and then it will print 
 * the map. 
 */
int main(int a,char * args[])
{
    // This statement will execute when the no of parameters will either exceed or reduced.
    if ( a != 2 )
    {
        string correctName=args[0];
        cerr << "usage:"<< endl;
        cerr <<"   "<< correctName.substr(2) << " " << "filename"<<endl ;
        exit(2);
    }
    else
    {
        ifstream inputfile;
        map<string, int> map1;
        typedef map<string, int>::value_type Pair;
        map<string, int>::iterator p;
        // This conditional statement will work when there are parameters. 
        if(a>0)
        {
             inputfile.open(args[1],ios::in);
             // It will check whether the file can open and is in good condition.
             if(inputfile.is_open() && inputfile.good())
             {
                  // This while loop will work until the end of file.
                  while(!inputfile.eof())
                  {
                        string str="",str1="";
                        getline(inputfile,str,' ');
                        // This if loop will bypass the execution if the string is null.
                        if(str=="")
                        {
                              continue;
                        }
                  // It will check whether the string contains new line character.
                  // If yes, it will eliminate it.
                  if(str.at(str.length()-1) == 10)
                  {
                         str=str.substr(0,str.size()-1);
                  }
                  // It will execute until the length of the string. 
                  for(int i=0;i<str.length();i++)
                  {
                         int j;
                         // This loop will check whether the string contains "'" character.
                         if((int)str.at(i) ==39)
                         {
                                // This loop will gets satisfied if that character is at the begining.
                                if(i==0)
                                {
                                       // If the character is at the end then it will take entire inside string.
                                       if((int)str.at(str.length()-1) ==39)
                                       {
                                              for(int k=1;k<str.length()-1;k++)
                                              {
                                                     str1 += str.at(k);						
                                               }
                                               break;
                                        }
                                        // If not,it will take entire string.
                                        else
                                        {
                                               str1=str;
                                               break;
                                        }
                                 }
                                 else
                                 {
                                        str1=str;
                                        break;
                                  }
                           }
                           // If other non-alphabetic characters arrives then it will break.	
                           else if((int)str.at(i) > 90 && (int)str.at(i) < 97 ||(int)str.at(i) > 122 ||(int)str.at(i) <65)
                           {
                                  break;
                           }
                           // If the character is alphabetic then it will concatenate in the resultant string.
                           else
                           {
                                   str1 +=  str.at(i);
                           }
                   }
                   // It will bypass all the resultant strings that are empty.
                   if(str1=="")
                   {
                           continue;
                   }
                   p = map1.find(str1);
                   // This condition will check whether that string is in map or not.
                   // If not then it will insert that value.
                   if (p == map1.end())
                   {
                           map1.insert(Pair(str1,1));		
                   }
                   // If yes, then will increase its count.	
                   else
                   {
                           long int count = p->second;
                           p->second = ++count;
                   }
                   if(inputfile.eof())
                   {
                           break;
                    }
            }
            // It will print the entire map.
            for (p = map1.begin(); p != map1.end(); p++)
            {
                   cout << p->first << ": " << p->second << endl;
             }
        }
        // It will work when the file doesnot exist.
        else
        {
             string correctName=args[0];
             cerr << "  "<<correctName.substr(2) << ": " << args[1] << ": " << "No such file" << endl;
             exit(2);
        }
    }
  }
  exit(0);
}
