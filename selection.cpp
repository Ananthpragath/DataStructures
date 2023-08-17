#include<iostream>
using namespace std;
class sorting
{
private:
int a[10],n,min;
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
void selection();
void display();
};
void sorting ::selection()
{
int i,j;
for(int i=0;i<n-1;i++)
{
min=i;
for(int j=i+1;j<n;j++)
{
if(a[j]<a[min])
{
min=j;
}}
swap(a[i],a[min]);
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
s.selection();
cout<<"\n\nFinal status of list after sorting:\n";
s.display();
}
