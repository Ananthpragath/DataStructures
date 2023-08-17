#include<iostream>
using namespace std;
class LinSrch
{
    int a[10];
    public:
    LinSrch(int size)
    {
       cout<<"Enter "<<size<<" elements :";
       for(int i=0;i<size;i++)
       {
           cin>>a[i];
       }
    }
    int recLinSrch(int target,int last)
    {
       int first=0;
       if(first>last)
           return 0;
       else  
       {
           if(target==a[last])
              return last;
           return recLinSrch(target,last-1);
       }
    }
};
int main()
{
    int size,target;
    cout<<"Enter the size of array :";
    cin>>size;
    LinSrch l(size);
    cout<<"Enter the target element :";
    cin>>target;
    int found=l.recLinSrch(target,size-1);
    if(found)
       cout<<"Element "<<target<<" found at position "<<found<<endl;
    else
       cout<<"Element not found\n";
}
   
