#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

typedef struct bst
{
	struct bst *left;
	int info;
	struct bst *right;
}node;

node* root=NULL;
node* parptr=NULL;

void insert(int item)
{
	//creating the new node with left & right = null
	node* ptr=(node*)malloc(sizeof(node));
	ptr->info=item;
	ptr->left=ptr->right=NULL;
	
	
	node* loc=root;
	//pointer for traking
	node* aloc=NULL;
	
	
	while(loc != NULL)
	{
		aloc=loc;
		//if item if less then root move to left sub tree
		if(item < loc->info)
		{
			loc=loc->left;
		}
		//else move to right sub tree
		else
		{
			loc=loc->right;
		}
	}
	
	//check the tree is empty or not
	if(aloc ==NULL)
	{
		root=ptr;
		
	}
	//node is leaf node then
	else if(item < aloc->info)
	{
		aloc->left = ptr;
	}
	else
	{
		aloc->right = ptr;
	}
}

void preorder_traverse(node* ptr)
{
	//node left right
	if(ptr==NULL)
		return;
		
	cout<<ptr->info<<" ";
	
	preorder_traverse(ptr->left);
	preorder_traverse(ptr->right);
}

void postorder_traverse(node* ptr)
{
	//left right node
	if(ptr==NULL)
		return;
		
	postorder_traverse(ptr->left);
	postorder_traverse(ptr->right);
	
	cout<<ptr->info<<" ";
}

void inorder_traverse(node* ptr)
{	
	//Left node right
	if(ptr==NULL)
		return;
		
	inorder_traverse(ptr->left);
	cout<<ptr->info<<" ";
	inorder_traverse(ptr->right);
}

node* search(int item)
{
	node* ptr=root;
	while (ptr!=NULL)
	{
		//return item pointer if match found
		if(item==ptr->info)
		{
			return ptr;
		}
		//parent pointer tracker help in deletion
		parptr = ptr;
		//item is less then root then move to left sub tree  
		if(item < ptr->info)
		{
			ptr=ptr->left;	
		}
		//item is greater then root then move to the right sub tree 	
		else
		{
			ptr=ptr->right;
		}
	}
	
	//return NULL if match not found
	return NULL;	
}

void delete_node(int item)
{
	node* ptr;
	ptr=search(item);
	cout<<"knjn:"<<parptr->info;
	if(ptr==NULL)
	{
		cout<<endl<<"Element not found so can't delete"<<endl;
		return;
	}
	
	//case 1 when node has 2 child at right and left
	if(ptr->left != NULL && ptr->right != NULL)
	{
		node* next=ptr->right;
		
		if(next->left==NULL)
		{
			ptr->info = next->info;
			ptr->right = next->right;
		}
		else
		{
			while(next->left!=NULL)
			{
				parptr = next;
				next=next->left;
			}
			
			ptr->info=next->info;
			parptr->left=NULL;
		}
		cout<<"Deleted value is: "<<next->info;
		free(next);
	}
	//case2 when it is a leaf node means with 0 child
	else if(ptr->left==NULL && ptr->right==NULL)
	{
		if(parptr==NULL)
		{
			root=NULL;
		}
		else
		{
			if(parptr->left == ptr)
			{
				parptr->left = NULL;
			}
			else
			{
				parptr->right = NULL;
			}
		}
		cout<<"Deleted value is: "<<ptr->info;
		free(ptr);
	}
	//case3 child is present only at right sub tree
	else if(ptr->left==NULL && ptr->right!=NULL)
	{
			if(parptr==NULL)
		{
			root=ptr->right;
		}
		else
		{
			if(parptr->left == ptr)
			{
				parptr->left = ptr->right;
			}
			else
			{
				parptr->right = ptr->right;
			}
		}
		cout<<"Deleted value is: "<<ptr->info;
		free(ptr);
	}
	//case4 child is present at only left sub tree
	else if(ptr->left!=NULL && ptr->right==NULL)
	{
		if(parptr==NULL)
		{
			root=ptr->left;
		}
		else
		{
			if(parptr->left == ptr)
			{
				parptr->left = ptr->left;
			}
			else
			{
				parptr->right = ptr->left;
			}
		}
		cout<<"Deleted value is: "<<ptr->info;
		free(ptr);
	}
}

void largest()
{
	if(root==NULL)
	{
		cout<<"UnderFlow"<<endl;
		return;
	}
	
	node* ptr=root;
	
	while(ptr->right!=NULL)
	{
		ptr= ptr->right;
	}
	
	cout<<endl<<"Largest Vlaue= "<<ptr->info<<endl;
}

void smallest()
{
	if(root==NULL)
	{
		cout<<"UnderFlow"<<endl;
		return;
	}
	
	node* ptr=root;
	
	while(ptr->left!=NULL)
	{
		ptr=ptr->left;
	}
	cout<<endl<<"Smallest value: "<<ptr->info<<endl;
}

int height(node* ptr)
{
	static int ht=0;
	
	if(ptr==NULL)
	{
		return(0);
	}
	else
	{
		int l = 0;
		l=height(ptr->left);
		int r = 0;
		r=height(ptr->right);
		
		if(l>r)
		{
			ht = l+1;
		}
		else
		{
			ht = r+1;
		}
		return(ht);
	}
}
int main()
{
	int sw;
	
	do
	{
		cout<<endl<<"----------------------"<<endl;
		cout<<"1> insert in BST"<<endl;
		cout<<"2> Preorder traversel"<<endl;
		cout<<"3> Postorder traversel"<<endl;
		cout<<"4> inorder traversel"<<endl;
		cout<<"5> Search"<<endl;
		cout<<"6> deletion"<<endl;
		cout<<"7> Largest Value"<<endl;
		cout<<"8> Lowest Value"<<endl;
		cout<<"9> Height of BST"<<endl;
		cout<<"10> Exit"<<endl;
		cout<<"----------------------"<<endl;
		cout<<"Enter your choice: ";
		cin>>sw;
		
			switch(sw)
			{
				default:
					cout<<"Wrong input"<<endl;
					break;
				
				case 1:
					int item;
					cout<<"Enter the the value: ";
					cin>>item;
					insert(item);
					break;
					
				case 2:
					if(root==NULL)
					{
						cout<<endl<<"UnderFlow"<<endl;
					}
					else
					{
						cout<<endl<<"preorder Tree lis in (NLR) :"<<endl;
						preorder_traverse(root);
						cout<<endl;
					}
					break;
					
				case 3:
					if(root==NULL)
					{
						cout<<endl<<"UnderFlow"<<endl;
					}
					else
					{
						cout<<endl<<"postorder Tree lis in (LRN) :"<<endl;
						postorder_traverse(root);
						cout<<endl;
					}
					break;
					
				case 4:
					if(root==NULL)
					{
						cout<<endl<<"UnderFlow"<<endl;
					}
					else
					{
						cout<<endl<<"inorder Tree lis in (LNR) :"<<endl;
						inorder_traverse(root);
						cout<<endl;
					}
					break;
					
				case 5:
					
					if(root==NULL)
					{
						cout<<endl<<"UnderFlow"<<endl;
						break;
					}
					node* loc;
					cout<<endl<<"Enter the item to search: ";
					cin>>item;
					
					loc = search(item);
					
					if(loc==NULL)
					{
						cout<<endl<<"NO Match Found"<<endl;
					}
					else
					{
						cout<<endl<<"Match Found"<<endl;
					}
					
					break;
				case 6:
					cout<<endl<<"Enter the value that want to delete: ";
					cin>>item;
					delete_node(item);
					break;
					
				case 7:
					largest();
					break;
					
				case 8:
					smallest();
					break;
					
				case 9:
					cout<<endl<<"Height of BST is: "<<height(root)<<endl;
					break;
			}
	}while(sw!=10);
}
