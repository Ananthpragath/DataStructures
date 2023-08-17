#include<iostream>
using namespace std;
struct dnode
{
     int data;
     dnode *back,*fore;
};
struct Header
{
     int count;
     dnode *front,*rear;
};
class DLL
{
     Header *dlist;
     dnode *pNew,*pPre,*pSuc,*temp,*pLoc;
     public:
     DLL()
     {
          dlist=new Header;
          dlist->front=NULL;
          dlist->rear=NULL;
          dlist->count=0;
     }
     void insertNode(int);
     void deleteNode(int);
     int searchNode(int);
     void isEmpty();
     void isFull();
     void count();
     void displayHeadToRear();
     void displayRearToHead();
     void searchHead(int);
     void searchRear(int);
     ~DLL();
};
void DLL:: insertNode(int x)
{
    int found=searchNode(x);
    if(found)
    { 
         cout<<"Duplicate entry. You can't insert\n";
         return;
    }
    pNew=new dnode;
    if(pNew==NULL)
    {
         cout<<"Memory overflow\n";
         return;
    }
    pNew->data=x;
    if(pPre==NULL)
    {
          pNew->fore=dlist->front;
          pNew->back=NULL;
          dlist->front=pNew;
    }
    else
    {
          pNew->fore=pSuc;
          pNew->back=pPre;
          pPre->fore=pNew;
    }
    if(pSuc==NULL) dlist->rear=pNew;
    else pSuc->back=pNew;
    dlist->count++;
}

void DLL:: deleteNode(int x)
{
     if(dlist->count==0)
     {
          cout<<"Memory underflow. No node is there to be deleted\n";return;
     }
     int found=searchNode(x);
     if(!found)
     {
          cout<<"Data not found\n";return;
     }
     temp=pSuc;
     if(pPre==NULL)
     {
          dlist->front=pSuc->fore;
     }
     else pPre->fore=pSuc->fore;
     if(pSuc->fore==NULL) dlist->rear=pPre;
     else pSuc->fore->back=pPre;
     cout<<temp->data<<" is deleted\n";
     delete temp;
     dlist->count--;
}

int DLL:: searchNode(int target)
{
     pPre=NULL;
     pSuc=dlist->front;
     while(pSuc!=NULL && target>pSuc->data)
     {
         pPre=pSuc;pSuc=pSuc->fore;
     }
     if(pSuc==NULL) return 0;
     else
     {
          if(target==pSuc->data) return 1;
          else return 0;
     }
}

void DLL:: displayHeadToRear()
{
     if(dlist->count!=0)
     {
          temp=dlist->front;
          while(temp!=NULL)
          {
                cout<<temp->data<<"->";
                temp=temp->fore;
          }
          cout<<endl;
     }
     else cout<<"DLL is empty\n";
}

void DLL:: displayRearToHead()
{
     if(dlist->count!=0)
     {
          temp=dlist->rear;
          while(temp!=NULL)
          {
                cout<<temp->data<<"->";
                temp=temp->back;
          }
          cout<<endl;
     }
     else cout<<"DLL is empty\n";
}


void DLL :: isEmpty()
{
     if(dlist->count==0) cout<<"DLL is empty\n";
     else cout<<"DLL is not empty\n";
}
 
void DLL:: isFull()
{
     temp=new dnode;
     if(temp==NULL) cout<<"Memory is full\n";
     else cout<<"Memory is not full\n";
}

void DLL:: count()
{
      cout<<"No. of nodes in the DLL : "<<dlist->count<<endl;
}

void DLL:: searchHead(int target)
{
     pLoc=dlist->front;int pos=1;
     while(pLoc!=NULL && target>pLoc->data)
     {
          pos++;pLoc=pLoc->fore;
     }
     if(pLoc==NULL) cout<<"Reached end of list\n";
     else
     {
          if(target==pLoc->data) cout<<"Position of "<<target<<" from head is "<<pos<<endl;
          else cout<<"Target not found\n";
     }
}

void DLL :: searchRear(int target)
{
     pLoc=dlist->rear;int pos=1;
     while(pLoc!=NULL && target<pLoc->data)
     {
          pos++;pLoc=pLoc->back;
     }
     if(pLoc==NULL) cout<<"Reached end of list\n";
     else
     {
          if(target==pLoc->data) cout<<"Position of "<<target<<" from rear is "<<pos<<endl;
          else cout<<"Target not found\n";
     }
}


DLL ::~DLL()
{
     if(dlist->count!=0)
     {
          temp=dlist->front;
          while(temp!=NULL)
          {
               dlist->front=temp->fore;
               cout<<"Removing the node containing "<<temp->data<<endl;
               delete temp;dlist->count--;
               temp=dlist->front;
          }
          delete dlist;
     }
     else cout<<"DLL is empty\n";
}

int main()
{
     DLL d;
     int ch,x,found,target;
     do
     {
          cout<<"\n1.Insert,2.Delete,3.Search,4.Display from Head,5.Display from rear,6.isEmpty,7.isFull,8.Count,9.Search position from Head,10.Search position from Rear,11.Exit\n";
          cout<<"Enter your choice : ";cin>>ch;
          switch(ch)
          {
               case 1:
               cout<<"Enter element to be inserted : ";cin>>x;d.insertNode(x);break;
         
               case 2:
               cout<<"Enter element to be deleted : ";cin>>x;d.deleteNode(x);break;

               case 3:
               cout<<"Enter element to be searched : ";cin>>target;
               found=d.searchNode(target);
               if(found) cout<<"Element "<<target<<" found\n";
               else cout<<"Element "<<target<<" not found\n";
               break;

               case 4:d.displayHeadToRear();break;
               case 5:d.displayRearToHead();break;
               case 6:d.isEmpty();break;
               case 7:d.isFull();break;
               case 8:d.count();break;
               case 9:
               cout<<"Enter the element to be searched from head:";cin>>target;
               d.searchHead(target);break;

               case 10:cout<<"Enter the element to be searched from rear :";cin>>target;d.searchRear(target);break;
         }
     }
     while(ch!=11);
}

