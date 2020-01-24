#include<iostream>
#include<conio.h>
using namespace std;

int main()
{
	int a[50],b[50],c[50]={0},k,n,m,i,j;
	
	cout<<"Enter The Length OF 1st array: ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	cout<<"Enter The Length OF 2st array: ";
	cin>>m;
	for(j=0;j<m;j++)
	{
		cin>>b[j];
	}
	
	i=k=j=0;
	
	  while(i<n && j<m)
	  {
	  	if(a[i]<b[j])
	  	{
	  	  c[k]=a[i];
		  i=i+1;	
		}
		else
		{
			c[k]=b[j];
			j=j+1;
		}
		k=k+1;
	  }
	  
	  	if(i==n)
	  	{
	  		while(j<m)
	  		{
			
	  	   		c[k] = b[j];
			 	j=j+1;
			 	k=k+1;
		    }
		}
		else
		{
			while(i<n)
			{
				c[k] = a[i];
				i=i+1;
				k=k+1;
			}
		}
		
	  cout<<"After The Merging: ";
	  for(i=0;i<n+m;i++)
	  {
	  	cout<<" "<<c[i];
	  }
	
	
}
