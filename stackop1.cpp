#include<iostream>
using namespace std;
class stackarray
{
private:
int stack[10];
int size;
int top;
public:
stackarray()
{
cout<<"Enter size of the stack:";
cin>>size;
top=-1;
}
~stackarray(){}
void push(int);
void pop();
void display();
void peek();
void isfull();
void isempty();
};
void stackarray :: push(int x)
{
if(top<size-1)
{
stack[++top]=x;
}
else
{
cout<<"\nStack overflow\n";
}}

void stackarray :: pop()
{
if(top>-1)
{
int y=stack[top--];
cout<<y<<" is deleted\n";
}
else
{
cout<<"Stack underflow\n";
}}

void stackarray :: display()
{
if(top>-1)
{
for(int i=0;i<=top;i++)
{
cout<<"\t"<<stack[i]<<endl;
}}
else
cout<<"It is a empty stack"<<endl;
}

void stackarray :: peek()
{
if(top>-1)
{
int i;
cout<<"Enter the position of element:";
cin>>i;
cout<<"\nElement in "<<i<<"th position is:"<<stack[top-i+1]<<endl;
}
else
cout<<"It is a empty stack\n";
}

void stackarray :: isfull()
{
if(top==size-1)
cout<<"Stack is full\n";
else 
cout<<"Stack is not full\n";
}

void stackarray :: isempty()
{
if(top==-1)
cout<<"Stack is empty\n";
else 
cout<<"Stack is not empty\n";
}

int main()
{
stackarray s;
int choice;
do
{
cout<<"1.Push\n2.Pop\n3.Display\n4.Peek\n5.Isfull\n6.Isempty\n7.Exit\n";
cout<<"Enter your choice:";
cin>>choice;
switch(choice)
{
case 1:
int x;
cout<<"Enter the element to be inserted:";
cin>>x;
s.push(x);
break;

case 2:
s.pop();
break;

case 3:
s.display();
break;

case 4:
s.peek();
break;

case 5:
s.isfull();
break;

case 6:
s.isempty();
break;
}
}
while(choice!=7);
return 0;
}

