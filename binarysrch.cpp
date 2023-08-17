#include<iostream>
using namespace std;
int main()
{
int a[10],n,i,j,temp,low,mid,high,flag=0;
cout<<"Enter no. of elements:";
cin>>n;
cout<<"Enter the elements one by one:";
for(i=0;i<n; i++)
{
cin>>a[i];
}
for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
if(a[i]>a[j])
{
temp=a[i];
a[i]=a[j];
a[j]=temp;
}}}
cout<<"\nElements after sorting:\n";
for(i=0;i<n;i++)
{
cout<<a[i]<<"\t";
}
int x;
cout<<"\nEnter search element:";
cin>>x;
low=0;high=n-1;
while(low<=high)
{
mid=(low+high)/2;
if(x==a[mid])
{
flag=1;
cout<<"Element "<<x<<" found in location "<<mid<<endl;
break;
}
else if(x>a[mid])
{
low=mid+1;
}
else
{
high=mid-1;
}}
if(flag==0)
{
cout<<"\nElement "<<x<<" not found\n";
}}
