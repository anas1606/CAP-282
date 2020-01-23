#include<iostream>
#include<conio.h>
using namespace std;

int main()
{
	int a[50],n,i,j;
	
	cout<<"Enter the array Lenth: ";
	cin>>n;
	
	   for(i=0;i<n;i++)
	   {
	   	cin>>a[i];
	   }
	   
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
			
		}
	}
	
	cout<<"After ShortinG: ";
	
	for (i=0;i<n;i++)
    {
      cout << "  " << a[i];
    }
}
