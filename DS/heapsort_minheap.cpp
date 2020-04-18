#include<iostream>
#include<conio.h>
using namespace std;
int n,arr[100];

void display()
{       
	if(n==0)
	{
		cout<<"Heap is empty\n";
		return;
	}
	for(int i=0;i<n;i++)
		cout<<" "<<arr[i];
		
	cout<<endl;
}

void heapify(int arr[],int n,int i) 
{ 
    int largest = i;  
    int l = 2*i + 1;  
    int r = 2*i + 2; 
  
     
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
     
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
     
    if (largest != i) 
    { 
        swap(arr[i], arr[largest]); 
  
        heapify(arr, n, largest); 
    } 
} 
   
void heapsort() 
{ 
    
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
  
    for (int i=n-1; i>0; i--) 
    { 
        swap(arr[0], arr[i]); 
   
        heapify(arr, i, 0); 
    } 
    
    cout<<endl<<"After Heap Sort: "<<endl;
    display();
} 

void insert(int num,int loc)
{
	int par;
	while(loc>0)
	{
		par=(loc-1)/2;
		if(num>=arr[par])
		{
			arr[loc]=num;
			return;
		}
		arr[loc]=arr[par];
		loc=par;
	}
	arr[0]=num; 
}
void del(int num)
{
	int left,right,i,temp,par;

	for(i=0;i<n;i++)
	{
		if(num==arr[i])
		break;
	}
	if( num!=arr[i] )
	{
		cout<<"%d not found in heap\n"<<num ;
		return;
	}
	arr[i]=arr[n-1];
	n=n-1;
	par=(i-1)/2;   /*find parent of node i */
	if(arr[i] > arr[par])
	{
		insert( arr[i],i);
		return;
	}
	left=2*i+1;  /*left child of i*/
	right=2*i+2; /* right child of i*/
	while(right < n)
	{
		if( arr[i]>=arr[left] && arr[i]>=arr[right] )
			return;
		if( arr[right]<=arr[left] )
		{
			temp=arr[i];
			arr[i]=arr[left];
			arr[left]=temp;
			i=left;
		}
		else
		{
			temp=arr[i];
			arr[i]=arr[right];
			arr[right]=temp;
			i=right;
		}
		left=2*i+1;
		right=2*i+2;
	}
	if( left==n-1 && arr[i]<arr[left] ) 
	{	temp=arr[i];
		arr[i]=arr[left];
		arr[left]=temp;
	}
}

main()
{
	int choice,num;
	n=0;
	while(choice!=5)
	{
		cout<<"1.Insert\n";
		cout<<"2.Delete\n";
		cout<<"3.Display\n";
		cout<<"4.Heap Sort\n";
		cout<<"5.Quit\n";
		cout<<"Enter your choice : ";
		cin>>choice;
		switch(choice)
		{
		 case 1:
			cout<<"Enter the number to be inserted : ";
			cin>>num;
			insert(num,n);
			n=n+1;
			break;
		 case 2:
			cout<<"Enter the number to be deleted : ";
			cin>>num;
			del(num);
			break;
		 case 3:
			display();
			break;
		 case 4:
		 	heapsort();
		 case 5:
            break;
		 default:
				cout<<"Wrong choice\n";
		}
	}
	
	getch();
}
