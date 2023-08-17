#include<iostream>
using namespace std;
class stackarray
{
    char stack[10];
    int top;
    public:
    stackarray()
    {
        top=-1;
    }
    void push(char c)
    {
        stack[++top]=c;
    }
    char pop()
    {
        char y=stack[top--];
        return y;
    }
    int isempty()
    {
        if(top==-1) return 1;
        else return 0;
    }
    char stacktop()
    {
        if(!isempty()) return stack[top];
        else return '\0';
    }
};
 

int precedence(char c)
{
    if(c=='*'||c=='/')
       return 2;
    else if(c=='-'||c=='+')
       return 1;
    else 
       return 0;
}

int main()
{
   char ch,del;int count=0;
   string infix,postfix="";
   stackarray s;
   cout<<"Enter the infix expression :";
   cin>>infix;
   while(infix[count]!='\0')
   {
       ch=infix[count];
       if(ch=='(')
           s.push(ch);
       else if(ch==')')
       {
           while(s.stacktop()!='(')
           {
              del=s.pop();
              postfix+=del;
           }
           s.pop();
       }
       else if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
       { 
           while(!s.isempty() && precedence(ch)<=precedence(s.stacktop()))
           {
              del=s.pop();
              postfix+=del;
           }
           s.push(ch);
       }
       else
       {
            postfix+=ch;
       }
       count++;
   }
   while(!s.isempty())
   {
       del=s.pop();
       postfix+=del;
   }
   cout<<"Converted postfix expression :"<<postfix<<endl;
} 
