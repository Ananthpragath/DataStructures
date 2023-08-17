#include<iostream>
using namespace std;
class sorting
{
private:
int a[10],n,hold;
public:
sorting()
{
cout<<"Enter no. of elements:";
cin>>n;
cout<<"Enter the elements:";
for(int i=0;i<n;i++)
{
cin>>a[i];
}}
void insertion();
void display();
};
void sorting ::insertion()
{
for(int i=0;i<n;i++)
{
hold=a[i];
int j=i-1;
while(j>=0 && a[j]>hold)
{
a[j+1]=a[j];
j--;
}
a[j+1]=hold;
cout<<"\nCurrent status of array:\n";
display();
}}
void sorting :: display()
{
for(int i=0;i<n;i++)
{
cout<<a[i]<<"\t";
}}

int main()
{
sorting s;
s.insertion();
cout<<"\n\nFinal status of list after sorting:\n";
s.display();
}
