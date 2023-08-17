#include<iostream>
using namespace std;
class queuearray
{
   private:
   int queue[10];
   int size;
   int front,rear;
   public:
   queuearray()
   {
      cout<<"Enter size of the queue:";
      cin>>size;
      front=rear=-1;
   }
   ~queuearray(){}
   void enqueue(int);
   void dequeue();
   void display();
   void frontelement();
   void rearelement();
   void isfull();
   void isempty();
   void count();
};
void queuearray :: enqueue(int x)
{
   if(rear<size-1)
   {
      queue[++rear]=x;
      if(front==-1)
         front++;
   }
   else
   {
      cout<<"\nQueue overflow\n";
   }
}

void queuearray :: dequeue()
{
   if(front>-1)
   {
      int y=queue[front];
      cout<<y<<" is deleted\n";
      if(front==rear)
         front=rear=-1;
      else
         front++;
   }
   else
   {
      cout<<"Queue underflow\n";
   }
}

void queuearray :: display()
{
   if(front>-1)
   {
      cout<<"\nElements in the queue are:\n";
      for(int i=front;i<=rear;i++)
      {
         cout<<"\t"<<queue[i];
      }
      cout<<endl;
   }
   else
       cout<<"It is a empty queue"<<endl;
}

void queuearray :: frontelement()
{
   if(front>-1)
      cout<<"Front element :"<<queue[front]<<endl;
   else
      cout<<"It is a empty queue\n";
}

void queuearray :: rearelement()
{
   if(front>-1)
      cout<<"Rear element :"<<queue[rear]<<endl;
   else
      cout<<"It is a empty queue\n";
}

void queuearray :: isfull()
{
   if(front==0 &&rear==size-1)
      cout<<"Queue is full\n";
   else 
      cout<<"Queue is not full\n";
}

void queuearray :: isempty()
{
   if(front==-1)
      cout<<"Queue is empty\n";
   else 
      cout<<"Queue is not empty\n";
}

void queuearray :: count()
{
   int i,count=0;
   if(front>-1)
   {
      for(i=front;i<=rear;i++)
      {
           count++;
      }
      cout<<"No. of elements :"<<count<<endl;
   }
   else
      cout<<"Queue is empty\n";
}

int main()
{
    queuearray q;
    int choice;
    do
    {
       cout<<"1.Enqueue\n2.Dequeue\n3.Display\n4.Front element\n5.Rear element\n6.Isfull\n7.Isempty\n8.Count\n9.Exit\n";
       cout<<"Enter your choice:";
       cin>>choice;
       switch(choice)
       {
          case 1:
          int x;
          cout<<"Enter the element to be inserted:";
          cin>>x;
          q.enqueue(x);
          break;

          case 2:
          q.dequeue();
          break;

          case 3:
          q.display();
          break;

          case 4:
          q.frontelement();
          break;

          case 5:
          q.rearelement();
          break;
  
          case 6:
          q.isfull();
          break;

          case 7:
          q.isempty();
          break;

          case 8:
          q.count();
          break;
      }
   }
   while(choice!=9);
   return 0;
}

