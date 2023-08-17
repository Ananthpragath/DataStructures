//linked stack
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
   node *top;
};

class LinkedStack
{
   node *pNew,*temp;
   Header *Stack;
   public:
   LinkedStack()
   {
      Stack=new Header;
      Stack->count=0;
      Stack->top=NULL;
   }
   void PushStack(int);
   void PopStack();
   void display();
   int StackTop();
   int peek(int);
   int isEmpty();
   void isFull();
   int StackCount();
   ~LinkedStack()
   {
      if(Stack->count!=0)
      {
        temp=Stack->top;
        while(temp!=NULL)
        {
          Stack->top=temp->link;
          cout<<"Removing the node containing "<<temp->data<<endl;
          delete temp;
          Stack->count--;
          temp=Stack->top;
        }
        delete Stack;
      }
      else
          cout<<"Stack is empty\n";
   }
};

void LinkedStack ::PushStack(int x)
{
    
        pNew=new node;
        if(pNew==NULL)
        {
            cout<<"Overflow. You can't insert\n";
        }
        pNew->data=x;
        pNew->link=Stack->top;
        Stack->top=pNew;
        Stack->count++;
        
}

void LinkedStack ::PopStack()
{
    if(Stack->top==NULL)
    {
        cout<<"Underflow. No node is there to be popped out\n";
        return;
    }
    temp=Stack->top;
    Stack->top=temp->link;
    cout<<temp->data<<" is deleted\n";
    Stack->count--;
}

void LinkedStack ::display()
{
     if(Stack->top==NULL)
        cout<<"Linked stack is empty\n";
     else
     {
         temp=Stack->top;
         while(temp!=NULL)
         {
             cout<<temp->data<<"->";
             temp=temp->link;
         }
         cout<<endl;
     }
}
         
int LinkedStack ::StackTop()
{
    if(Stack->count==0)
        return 0;
    else
        return Stack->top->data;
}

int LinkedStack ::peek(int i)
{
    if(Stack->top==NULL)
    {
        cout<<"Linked stack is empty\n";
        return 0;
    }
    int j=1;
    temp=Stack->top;
    while(temp!=NULL && i>j)
    {
       temp=temp->link;j++;
    }
    if(temp==NULL)
    {
        cout<<"Memory out of bounds\n";
        return 0;
    }
    else if(i==j)
       return temp->data;
}
        

int LinkedStack ::isEmpty()
{
    if(Stack->count==0)
        return 1;
    else
        return 0;
}

void LinkedStack ::isFull()
{
    temp=new node;
    if(temp==NULL)
       cout<<"Memory is full\n";
    else 
       cout<<"Memory is not full\n";
}

int LinkedStack ::StackCount()
{
    return Stack->count;
}

int main()
{
   LinkedStack s;
   int choice,x,found;
   do
   {
      cout<<"\n1.Push Stack,2.Pop Stack,3.Stack Top,4.isEmpty,5.isFull,6.Stack Count,7.Display,8.Peek,9.Exit\n";
      cout<<"Enter your choice :";
      cin>>choice;
      switch(choice)
      {
          case 1:
          cout<<"Enter the element to be pushed :";
          cin>>x;
          s.PushStack(x);break;
 
          case 2:
          s.PopStack();break;
 
          case 3:
          found=s.StackTop();
          if(found)
              cout<<"Stack Top element :"<<found<<endl;
          else
              cout<<"Linked stack is empty\n";
          break;
  
          case 4:
          found=s.isEmpty();
          if(found)
              cout<<"Linked stack is empty\n";
          else 
              cout<<"Linked Stack is not empty\n";
          break;
 
          case 5:
          s.isFull();break;
 
          case 6:
          found=s.StackCount();
          cout<<"No. of elements in the linked stack are :"<<found<<endl;
          break;

          case 7:
          s.display();break;

          case 8:
          int i;
          cout<<"Enter the position for peek :";
          cin>>i;
          found=s.peek(i);
          if(found!=0)
          cout<<"Element in the position "<<i<<" is "<<found<<endl;
          break;


      }
   }
   while(choice!=9);
}

