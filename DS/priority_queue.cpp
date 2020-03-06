#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace  std;

typedef struct p_qu
{
    char info;
    int priority;
    struct p_qu *link;
}node;

 node *head;

void empty_lis()
{
    head=NULL;
}

void ins_p_q()
{
    node *ptr,*loc,*temp;
    char item;
    int pno;

    ptr=(node*)malloc(sizeof(node));
    cout<<endl<<"Enter the item: ";
    cin>>ptr->info;

    cout<<"Enter the priority: ";
    cin>>ptr->priority;


    if(head==NULL || head->priority > ptr->priority)
    {
        ptr->link = head;
        head = ptr;
    }
    else
    {
        loc=head;
        while(loc->priority <= ptr->priority && loc->link!=NULL)
        {
            temp=loc;
            loc=loc->link;
        }
        if(loc->priority > ptr->priority)
        {
            ptr->link=temp->link;
            temp->link=ptr;
        }
        else
        {
          loc->link=ptr;
          ptr->link=NULL;
        }
    }
}

void traverse()
{
    node *ptr=head;
    if(head==NULL)
    {
        cout<<"UnderFlow"<<endl;
    }
    else
    {
      cout<<endl<<" item     Priority"<<endl;
      while(ptr!=NULL)
      {
         cout<<"  "<< ptr->info<<"           "<<ptr->priority<<endl;
         ptr=ptr->link;
      }
    }
}

void del()
{
    if(head==NULL)
    {
        cout<<"UnderFlow";
    }
    else if(head->link==NULL)
    {
        cout<<endl<<"deleted item is: "<<head->info<<endl;
        free(head);
        head=NULL;
    }
    else
    {
        node *ptr=head;
        cout<<endl<<"deleted item is: "<<head->info<<endl;
        head = ptr->link;
        free(ptr);
    }
}

int main()
{
    int sw;

    empty_lis();

        do
        {
           cout<<endl<<"<1> Insertion "<<endl<<"<2> traverse"<<endl<<"<3> Deletion"<<endl;
           cout<<"Enter the choice: ";
           cin>>sw;

           switch(sw)
           {
           case 1:
                    ins_p_q();
                    break;
           case 2:
                    traverse();
                    break;
           case 3:
                    del();
                    break;
           default:
                    cout<<endl<<"Wrong Choice";
           }
        }while(sw!=4);
}
