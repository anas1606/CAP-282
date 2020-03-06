#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

typedef struct qu
{
    int info;
    struct qu *link;
}node;

node *frnt,*rear;

void empty_ls()
{
    frnt=rear=NULL;
}

void enqueue()
{
   node *ptr;
   ptr=(node*)malloc(sizeof(node));

   cout<<"Enter  the value: ";
   cin>>ptr->info;

     if(frnt==NULL && rear==NULL)
     {
         frnt = rear = ptr;
         ptr->link = NULL;
     }
     else
     {
         ptr->link = NULL;
         rear->link = ptr;
         rear = ptr;
     }

}

void dequeue()
{
    node *ptr=frnt;

    if(frnt==NULL)
    {
        cout<<"underflow"<<endl;
    }
    else
    {
       cout<<endl<<"deleted item is : "<<ptr->info<<endl;
       frnt=ptr->link;
       free(ptr);
    }
}

void traverse()
{
    node *ptr=frnt;

    if(frnt==NULL)
    {
        cout<<"UnderFlow";
    }
    else
    {
        while (ptr!=-NULL)
        {
            cout<<ptr->info<<endl;
            ptr=ptr->link;
        }
    }
}
int main()
{
    int sw;
    empty_ls();

    do
    {
        cout<<endl<<"<1> Enqueue"<<endl<<"<2> Dequeue"<<endl<<"<3> traverse"<<endl;
        cout<<"Enter your choice: ";
        cin>>sw;

        switch(sw)
        {
        case 1:
                enqueue();
                break;
        case 2:
                dequeue();
                break;

        case 3:
                traverse();
                break;
        }

    }while(sw!=4);
}
