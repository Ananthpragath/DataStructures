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
class CDLL
{
     Header *list;
     dnode *temp,*temp1,*pNew,*pPre,*pSuc,*pLoc;
     public:
     CDLL()
     {
          list=new Header;
          list->front=NULL;
          list->rear=NULL;
          list->count=0;
     }
     void insertNode(int);
     void deleteNode(int);
     int searchNode(int);
     void isEmpty();
     void isFull();
     void count();
     void displayFrontToRear();
     void displayRearToFront();
     void searchFront(int);
     void searchRear(int);
     ~CDLL();
};
void CDLL:: insertNode(int x)
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
          if(list->count==0)
          {
               list->front=pNew;
               list->rear=pNew;
          }
          else
          {
               list->front->back=pNew;
               list->rear->fore=pNew;
          }
          pNew->fore=list->front;
          pNew->back=list->rear;
          list->front=pNew;
    }
    else
    {
          pNew->fore=pSuc;
          pNew->back=pPre;
          pPre->fore=pNew;
          if(pSuc==list->front) list->rear=pNew;
          pSuc->back=pNew;
    }
    list->count++;
}

void CDLL:: deleteNode(int x)
{
     if(list->count==0)
     {
          cout<<"Memory underflow. No node is there to be deleted\n";return;
     }
     int found=searchNode(x);
     if(!found)
     {
          cout<<"Data not found\n";return;
     }
     if(list->count==1)
     {
          list->front=NULL;list->rear=NULL;
     }
     else
     {
         if(pPre!=NULL)
         {
             pPre->fore=pSuc->fore;
             pSuc->fore->back=pPre;
             if(pSuc==list->rear) list->rear=pPre;
         }
         else
         {
              list->front=pSuc->fore;
              pSuc->fore->back=pSuc->back;
              list->rear->fore=pSuc->fore;
         }
     }
     
     cout<<pSuc->data<<" is deleted\n";
     delete pSuc;
     list->count--;
}

int CDLL:: searchNode(int target)
{
     pPre=NULL;
     pSuc=list->front;
     if(list->count==0)
     {
          return 0;
     }
     if(pSuc->data==target) return 1;
     if(target<pSuc->data) return 0;
     pPre=pSuc;pSuc=pSuc->fore;
     while(pSuc!=list->front && target>pSuc->data)
     {
         pPre=pSuc;pSuc=pSuc->fore;
     }
     if(pSuc==list->front) return 0;
     else
     {
          if(target==pSuc->data) return 1;
          else return 0;
     }
}

void CDLL:: displayFrontToRear()
{
     if(list->count!=0)
     {
          temp=list->front;
          if(temp!=NULL)
          {
                cout<<temp->data<<"->";
                temp=temp->fore;
          }
          while(temp!=list->front)
          {
                cout<<temp->data<<"->";
                temp=temp->fore;
          }
          cout<<endl;
     }
     else cout<<"CDLL is empty\n";
}

void CDLL:: displayRearToFront()
{
     if(list->count!=0)
     {
          temp=list->rear;
          if(temp!=NULL)
          {
                cout<<temp->data<<"->";
                temp=temp->back;
          }
          while(temp!=list->rear)
          {
                cout<<temp->data<<"->";
                temp=temp->back;
          }
          cout<<endl;
     }
     else cout<<"CDLL is empty\n";
}


void CDLL :: isEmpty()
{
     if(list->count==0) cout<<"CDLL is empty\n";
     else cout<<"CDLL is not empty\n";
}
 
void CDLL:: isFull()
{
     temp=new dnode;
     if(temp==NULL) cout<<"Memory is full\n";
     else cout<<"Memory is not full\n";
}

void CDLL:: count()
{
      cout<<"No. of nodes in the CDLL : "<<list->count<<endl;
}

void CDLL:: searchFront(int target)
{
     pLoc=list->front;int pos=1;
     if(list->count==0)
     {
           cout<<"List empty\n";return;
     }
     if(target==pLoc->data)
     {
           cout<<"Position of "<<target<<" from front is "<<pos<<endl;
           return;
     }
     pLoc=pLoc->fore;pos++;
     while(pLoc!=list->front && target>pLoc->data)
     {
          pos++;pLoc=pLoc->fore;
     }
    
     if(target==pLoc->data) cout<<"Position of "<<target<<" from front is "<<pos<<endl;
     else cout<<"Target not found\n";

}

void CDLL:: searchRear(int target)
{
     pLoc=list->rear;int pos=1;
     if(list->count==0)
     {
           cout<<"List empty\n";return;
     }
     if(target==pLoc->data)
     {
           cout<<"Position of "<<target<<" from rear is "<<pos<<endl;
           return;
     }
     pLoc=pLoc->back;pos++;
     while(pLoc!=list->rear && target>pLoc->data)
     {
          pos++;pLoc=pLoc->back;
     }
    
     if(target==pLoc->data) cout<<"Position of "<<target<<" from rear is "<<pos<<endl;
     else cout<<"Target not found\n";
}


CDLL ::~CDLL()
{
     temp=list->front;temp1=NULL;
     if(list->count!=0)
     {
          temp1=temp;temp=temp->fore;
          cout<<"Removing the node containing "<<temp1->data<<endl;delete temp1;
          while(temp!=list->front)
          {
               temp1=temp;temp=temp->fore;
               cout<<"Removing the node containing "<<temp1->data<<endl;
               delete temp1;
          }
           delete list;
     }
     else cout<<"CDLL is empty\n";
}

int main()
{
     CDLL d;
     int ch,x,found,target;
     do
     {
          cout<<"\n1.Insert,2.Delete,3.Search,4.Display from Front,5.Display from rear,6.isEmpty,7.isFull,8.Count,9.Search position from Front,10.Search position from Rear,11.Exit\n";
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

               case 4:d.displayFrontToRear();break;
               case 5:d.displayRearToFront();break;
               case 6:d.isEmpty();break;
               case 7:d.isFull();break;
               case 8:d.count();break;
               case 9:
               cout<<"Enter the element to be searched from front:";cin>>target;
               d.searchFront(target);break;

               case 10:cout<<"Enter the element to be searched from rear :";cin>>target;d.searchRear(target);break;
         }
     }
     while(ch!=11);
}

