#include<iostream>
#include<conio.h>
using namespace std;

int main()
{
	int a[50],mid,strt,item,end,i,n;
	
	cout<<"Enter the array length: ";
	cin>>n;
	
	cout<<"Enter the Value: ";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	cout<<"Enter the NO: ";
	cin>>item;
	
	strt=0;
	end=n;
	mid=(strt+n)/2;
	
		while(strt<end && a[mid]!=item)
		{
			if(item>a[mid])
			{
				strt=mid+1;
			}
			else
			{
				end=mid-1;
			}
			
			mid=(strt+end)/2;
		}
		
		if(a[mid]==item)
		{
			cout<<"Success"<<mid+1;
		}
		else
		{
			cout<<"UNSeccess";
		}
}
