//program for sll
#include<iostream>
using namespace std;

//for data node
struct node
{
   int data;
   node *link;
};

// for head node
struct header
{
  int count;
  node *head;
  node *pos;
};

class sll
{
  private:
  node *pnew,*pred,*ploc,*temp;
  header *plist;

  public:
  sll()
  {
     plist=new header;
     plist->count=0;
     plist->head=NULL;
     plist->pos=NULL;
  }
  void insertNode(int);
  void deleteNode(int);
  void display();
  int search(int);
  void traverse(int,int);
  int count();
  int isEmpty();
  void isFull();
  ~sll();
};

//member func definitions outside class
void sll ::insertNode(int x)
{
   int found=search(x);
   if(found)
   {
      cout<<"Duplicate entry. You can't enter data\n";
   }
   pnew=new node;
   if(pnew==NULL)
   {
      cout<<"Memory full\n";
   }
   pnew->data=x;
   if(pred==NULL)
   {
      pnew->link=plist->head;
      plist->head=pnew;
   }
   else
   {
     pnew->link=pred->link;
     pred->link=pnew;
   }
   plist->count++;
}

void sll ::deleteNode(int x)
{ 
   if(plist->count==0)
   {
      cout<<"Underflow. No node is there to be deleted\n";
      return;
   }
   int found=search(x);
   if(!found)
   {
      cout<<"Data not found. You can't delete data\n";
      return;
   }
   if(pred==NULL)
   {
      plist->head=ploc->link;
   }
   else
   {
      pred->link=ploc->link;
   }
   cout<<ploc->data<<" is deleted\n";
   delete ploc;
   plist->count--;
}

void sll ::display()
{
   temp=plist->head;
   while(temp!=NULL)
   {
      cout<<temp->data<<"->";
      temp=temp->link;
   }
   cout<<endl;
}

int sll ::search(int target)
{
   pred=NULL;
   ploc=plist->head;
   while(ploc!=NULL && ploc->data<target) 
   {
      pred=ploc;
      ploc=ploc->link;
   }
   if(ploc==NULL)
   {
     return 0;
   }
   else
   {
      if(ploc->data==target)
         return 1;
      else
         return 0;
   }
}

void sll::traverse(int from,int dataout)
{
      if(plist->count==0)
      {
         cout<<"Empty list\n";
         return;
      }

       if(from==0)
       { 
          plist->pos=plist->head;
          dataout=plist->pos->data;
          plist->pos=plist->pos->link;
          cout<<"Traversed element :"<<dataout<<endl;
       }
       else
       { 
          if(plist->pos==NULL)
          {
             cout<<"Reached end of list\n";
             return;
          }
          else
          {
            dataout=plist->pos->data;
            plist->pos=plist->pos->link;
            cout<<"Traversed element :"<<dataout<<endl;
          }
       }
}

int sll::count()
{
      return plist->count;
}

int sll::isEmpty()
{
   if(plist->count==0)
       return true;
   else
       return false;
}

void sll::isFull()
{
    temp=new node;
    if(temp==NULL)
       cout<<"Memory is full\n";
    else
       cout<<"Memory is not full\n";
}
      

sll ::~sll()
{
  temp=plist->head;
  while(temp!=NULL)
  {
     plist->head=temp->link;
     cout<<"Removing the node containing "<<temp->data<<endl;
     delete temp;
     plist->count--;
     temp=plist->head;
  }
}

int main()
{
  sll s;
  int choice,x,found,from,dataout;
  do
  {
     cout<<"\n1.Insert\n2.Delete\n3.Display\n4.Search\n5.Traverse\n6.Count\n7.isEmpty\n8.isFull\n9.Exit\n";
     cout<<"Enter your choice : ";
     cin>>choice;
     switch(choice)
     {
         case 1:
         cout<<"Enter the element to be inserted:";
         cin>>x;
         s.insertNode(x);
         break;

         case 2:
         cout<<"Enter the element to be deleted:";
         cin>>x;
         s.deleteNode(x);
         break;

         case 3:
         s.display();
         break;

         case 4:
         cout<<"Enter the target element:";
         cin>>x;
         found=s.search(x);
         if(found)
           cout<<x<<" is found\n";
         else
           cout<<x<<" is not found\n";
         break;
  
        case 5:
        cout<<"Enter from where element has to be traversed:";
        cin>>from;
        s.traverse(from,dataout);
        break;

        case 6:
        found=s.count();
        cout<<"No. of elements in the linked list are :"<<found<<endl;
        break;
   
        case 7:
        found=s.isEmpty();
        if(found==1)
           cout<<"Linked list is empty\n";
        else
           cout<<"It is not empty\n";
        break;
  
        case 8:
        s.isFull();
        break;
     

    }
  }
  while(choice!=9);
}
         





                                                                                                                                                                                                    

