#ifndef _STATISTICS_H_
#define _STATISTICS_H_
#include <list>
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <set>
#include <stdlib.h>
#include <vector>
using namespace std;
template< class T >
/*
 * This class contains all the methods which are used to calculate the geometrical methods. 
 */
class Statistics
{
   public:
   typedef T value_type;
   
   /**
    * Calculate the mean (average) of the data entered.
    */
   T mean()
   {
	   	iter = list1.begin(); 
        iter1 =list1.end();  
        int sizeOfVector=this->v.size();
        value_type totalTime;

          if(this->v.size() < 1)
          {
               throw std::underflow_error("Not Enough Data");
          }
          else
          {
               for(this->it=this->v.begin(); this->it!=this->v.end() ;++it)
               {
                    totalTime = totalTime + *(this->it);
               }
               
          }
      
			return *(new value_type(totalTime/sizeOfVector));
   }

   /**
    * Calculate the median (middle element when the data is sorted)
    */
   T median()
   {
	iter = list1.begin(); 
    iter1 =list1.end();  
    std::sort(this->v.begin(),this->v.end());
    int temp ;
    int sizeOfVector=this->v.size();
           if(this->v.size() < 1)
           {
               throw std::underflow_error("Not Enough Data");
           }
           else
           {

               if(sizeOfVector%2==0)
               {
				temp = (this->v[sizeOfVector/2-1]+this->v[sizeOfVector/2])/2;
               }
               else
               {
               temp = v[(sizeOfVector + 1)/2].inSec();
               }
           }
   return *(new value_type(temp));
   }

   /**
    * Calculate the mode (most common element). This can be the empty set if
    * there is a uniform distribution
    */
   std::set<T> mode()
   {
	iter = list1.begin(); 
    iter1 =list1.end();  
    typename std::set<T> a;
       if(this->v.size() < 1)
       {
           throw std::underflow_error("Not Enough Data");
       }
       else
       {
           
           int i=0,j=0;
           for(this->it=v.begin(); this->it!=v.end() ;++it)
           {
                i=std::count(this->v.begin(),this->v.end(),*it);
                if(i>j && i>1)
                {
                     j=i;
                }
           }
           for(this->it=v.begin(); this->it!=v.end() ;++it)
           {
                i=count(this->v.begin(),this->v.end(),*it);
                if(i==j)
                {
                    a.insert(*it);
                }
           }
       }
       return a;  
        
   }    

   /**
    * Get the value of the smallest element 
    */
   T min()
   {
	   	iter = list1.begin(); 
        iter1 =list1.end();  

          if(this->v.size() < 1)
          {
              return *(new value_type(0));
          }
              return *(std::min_element(iter,iter1));


  }
   /**
    * Get the value of the largest element
    */
   T max()
   {
	   	iter = list1.begin(); 
    iter1 =list1.end();  

           if(this->v.size() < 1)
           {
                 return *(new value_type(0));
           }

                 return *(std::max_element(iter,iter1));

   }

   /**
    * Add an element to our data set
    */
   void push( T t )
   {
       list1.push_back(t);
       v.push_back(t);
   }

   /**
    * Removes all elements from the data
    */
   void clear()
   {
        list1.clear();
        v.clear();
   }
 /**
    *  
    */
   typename std::list<T>::iterator iter; 
   typename std::list<T>::iterator iter1;
   typename std::vector<T>::iterator it;
   private:
   std::list<T> list1;
   std::vector<T> v,v1;
  
};
#endif // _STATISTICS_H_
