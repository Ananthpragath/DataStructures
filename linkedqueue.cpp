//linked queue
#include<iostream>
using namespace std;
struct node
{
   int data;
   node *link;
};

struct Header
{
   int count;
   node *front,*rear;
};

class LinkedQueue
{
   node *pNew,*temp,*pDlt;
   Header *Queue;
   public:
   LinkedQueue()
   {
      Queue=new Header;
      Queue->count=0;
      Queue->front=NULL;
      Queue->rear=NULL;
   }
   void Enqueue(int);
   void Dequeue();
   void display();
   void QueueFront();
   void QueueRear(); 
   int isEmpty();
   void isFull();
   int QueueCount();
   ~LinkedQueue()
   {
      if(Queue->count!=0)
      {
        temp=Queue->front;
        while(temp!=NULL)
        {
          Queue->front=temp->link;
          cout<<"Removing the node containing "<<temp->data<<endl;
          delete temp;
          Queue->count--;
          temp=Queue->front;
        }
        delete Queue;
      }
      else
          cout<<"Queue is empty\n";
   }
};

void LinkedQueue ::Enqueue(int x)
{
    
        pNew=new node;
        if(pNew==NULL)
        {
            cout<<"Overflow. You can't insert\n";return;
        }
        pNew->data=x;
        if(Queue->count==0)
            Queue->front=pNew;
        else
            Queue->rear->link=pNew;
        Queue->rear=pNew;
        Queue->count++;
        
}

void LinkedQueue ::Dequeue()
{
    if(Queue->count==0)
    {
        cout<<"Underflow. No node is there to be popped out\n";
        return;
    }
    pDlt=Queue->front;
    if(Queue->count==1)
    {
        Queue->rear=NULL;
    }
    Queue->front=pDlt->link;
    cout<<pDlt->data<<" is deleted\n";
    delete pDlt;
    Queue->count--;
}

void LinkedQueue ::display()
{
     if(Queue->count==0)
        cout<<"Linked queue is empty\n";
     else
     {
         temp=Queue->front;
         while(temp!=NULL)
         {
             cout<<temp->data<<"->";
             temp=temp->link;
         }
         cout<<endl;
     }
}
         

void LinkedQueue ::QueueFront()
{
    if(Queue->count==0)
        cout<<"Linked Queue is empty\n";
    else
        cout<<"Element at the front :"<<Queue->front->data<<endl;
}

void LinkedQueue ::QueueRear()
{
    if(Queue->count==0)
        cout<<"Linked Queue is empty\n";
    else
        cout<<"Element at the rear :"<<Queue->rear->data<<endl;
}
    

int LinkedQueue ::isEmpty()
{
    if(Queue->count==0) return 1;
    else return 0;
}

void LinkedQueue ::isFull()
{
    temp=new node;
    if(temp==NULL)
       cout<<"Memory is full\n";
    else 
       cout<<"Memory is not full\n";
}

int LinkedQueue ::QueueCount()
{
    return Queue->count;
}

int main()
{
   LinkedQueue q;
   int choice,x,found;
   do
   {
      cout<<"\n1.Enqueue,2.Dequeue,3.Display,4.QueueFront,5.QueueRear,6.isEmpty,7.isFull,8.QueueCount,9.Exit\n";
      cout<<"Enter your choice :";
      cin>>choice;
      switch(choice)
      {
          case 1:
          cout<<"Enter the element to be inserted :";
          cin>>x;
          q.Enqueue(x);break;
 
          case 2:
          q.Dequeue();break;
 
          case 3:
          q.display();break;

          case 4:
          q.QueueFront();
          break;
  
          case 5:
          q.QueueRear();break;

          case 6:
          found=q.isEmpty();
          if(found)
              cout<<"Linked queue is empty\n";
          else 
              cout<<"Linked queue is not empty\n";
          break;
 
          case 7:
          q.isFull();break;
 
          case 8:
          found=q.QueueCount();
          cout<<"No. of elements in the linked queue are :"<<found<<endl;
          break;
      }
   }
   while(choice<9);
}

