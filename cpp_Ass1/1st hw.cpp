#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
    int i,j,n,n1;
    cout<< "List 1 size: ";
    cin>>n; // This will input the size of an array
    int listA[n]; 
    cout<<"List 1 data: ";
   for(int k=0;k<n;k++)
   {
     cin>>listA[k];  // This will input the elements of array1
   }
   cout<< "List 2 size: ";
   cin>>n1;
   int listB[n1];
   cout<<"List 2 data: ";    
   for(int k=0;k<n1;k++)
   {
     cin>>listB[k]; // This will input the elements of array2
   }
   for(i=0;i<n;i++)
   {
       for(j=0;j<n1;j++)
       {
	 if(listA[i]==listB[j]) // This condition will check whether the element is similar or not
           {
                break;
           }
           else
           {
                continue;
           }
       }
       if(j==n1) // This condition will work only if certain element will not be in array2
       {
       cout<<"FALSE\n";
       exit(0);
       }
   }
  cout<<"TRUE\n";
   return 0;
}
