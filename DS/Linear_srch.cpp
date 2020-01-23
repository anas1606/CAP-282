#include<iostream>
#include<conio.h>
using namespace std;

int main()
{
	int a[50],n,i,item;
	
	cout<<"Enter the Array Length: ";
	cin>>n;
	
	   for(i=0;i<n;i++)
	   {
	   	cin>>a[i];
	   }
	   
	   cout<<"Enter the Item: ";
	   cin>>item;
	   
	    for(i=0;i<n;i++)
	    {
	    	if(item==a[i])
	    	{
	    		cout<<"Match Foud on: "<<i+1<<" Possition";
	    		break;
			}
		}
		
		if(i == n)
         cout<<"Given element is not found in the list!!!";
}
