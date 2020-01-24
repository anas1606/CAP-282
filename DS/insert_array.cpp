#include<iostream>
#include<conio.h>
using namespace std;

int main()
{
	int a[50],n,i,item,k;
	
	cout<<"Enter the Array Length: ";
	cin>>n;
	
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		
		cout<<"Enter The Item: "<<endl;
		cin>>item;
		cout<<"Enter the Possition: "<<endl;
		cin>>k;
		
		 for(i=n;i>=k;i--)
		 {
		 	a[i+1] = a[i];
		 }
		 
		 a[k]=item;
		 n=n+1;
		
	cout<<"After Insertion: ";
	for(i=0;i<n;i++)
	{
		cout<<" "<<a[i];
	}
}
