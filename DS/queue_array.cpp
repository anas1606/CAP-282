#include<iostream>
#include<conio.h>
using namespace std;

int qu[5],frnt=-1,rear=-1;

void enqueue(int iteam)
{
    if(frnt==0 && rear==4)
    {
        cout<<"OverFlow"<<endl;
        return;
    }
    else if(frnt==-1)
    {
        frnt=rear=0;
    }
    else if(rear==4)
    {
        for(int i=frnt;i<=rear;i++)
        {
            qu[i-frnt]=qu[i];
        }
        rear = rear-frnt+1;
        frnt=0;
    }
    else
    {
        rear = rear+1;
    }
    qu[rear]=iteam;

}

void dequeue()
{
    if(frnt==-1)
    {
        cout<<"Underflow";
        return;
    }
     cout<<endl<<"deleted iteam is: "<<qu[frnt];

     if(frnt==rear)
     {
         frnt=rear=-1;
     }
     else
     {
         frnt=frnt+1;
     }
}

int main()
{
    int sw;

    do
    {
        cout<<endl<<"<1> enqueue"<<endl<<"<2> Display"<<endl<<"<3> dequeue"<<endl<<"<4> EXIT"<<endl;
        cout<<"Enter your choice: ";
        cin>>sw;

        switch(sw)
        {
        case 1:
                int iteam;
                cout<<endl<<"enter the iteam: ";
                cin>>iteam;
                enqueue(iteam);
                break;
        case 2:
                if(frnt==-1)
                {
                    cout<<"Underflow"<<endl;
                }
                else
                {
                 cout<<endl<<"Queue List Is : ";
                 for(int i=frnt;i<=rear;i++)
                 {
                    cout<<"  "<<qu[i];
                 }
                }
                break;
        case 3:
                dequeue();
                break;

        }

    }while(sw!=4);
}
