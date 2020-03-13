#include<iostream>
#include<conio.h>

using namespace std;
int l[20]={-1},l_top=0,u[20],u_top=-1;

//push lower stack
void push_l(int item)
{
	if(l_top==0)
	{
		l_top=1;
	}
	else
	{
		l_top=l_top+1;
	}
	l[l_top]=item;
}

//push upper stack
void push_u(int item)
{
	if(u_top==-1)
	{
		u_top=0;
	}
	else
	{
		u_top=u_top+1;
	}
	u[u_top]=item;
}

//check empty list
int emptyL()
{
   if(l[l_top]==-1)
   {
   	return 0;
   }
   else
   {
   	return 1;
   }
}

//pop in lower stack
int pop_l()
{
	int t= l[l_top];
	l_top=l_top-1;
	return t;
}

//pop in upper stack
int pop_u()
{
	int t= u[u_top];
	u_top=u_top-1;
	return t;
}

//main quick
int quik(int s[],int beg,int end)
{	
	int left,loc;
	left=loc=beg;
	int right=end;
	
		a:
		while(s[loc]<=s[right] && loc!=right)
		{
			right = right - 1;
		}
		
		if(loc==right)
		{
			return(loc);
		}
		if(s[loc]>s[right])
		{
			int t;
			t = s[loc];
			s[loc] = s[right];
			s[right] = t;
			loc= right;
		}
		
		while(s[left]<=s[loc] && left!=loc)
		{
			left = left +1;
		}
		if(loc==left)
		{
			return(loc);
		}
		if(s[left]>s[loc])
		{
			int t;
			t = s[left];
			s[left] = s[loc];
			s[loc] = t;
			loc=left;
			goto a;
		}
}

int quick(int s[],int n)
{
	int beg,end;
	if(n>0)
	{
		push_l(0);
		push_u(n-1);
	}
	
	while(emptyL())
	{
		beg = pop_l();
		end = pop_u();
	
		int loc = quik(s,beg,end);
	
		if(beg<loc-1)
		{
			push_l(beg);
			push_u(loc-1);
		}
		if(loc+1<end)
		{
			push_l(loc+1);
			push_u(end);
		}
	}
}

int main()
{
	int a[10],n;
	
	cout<<"Enter the Array Size: ";
	cin>>n;
	
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		quick(a,n);
		for(int i=0;i<n;i++)
		{
			cout<<" "<<a[i];
		}
}
