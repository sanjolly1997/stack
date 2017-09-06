#include <iostream>

using namespace std;
int priority(char ch)
{
    if(ch=='+' || ch=='-')
        return 1;
    if(ch=='*' || ch=='/')
        return 2;
    if(ch=='&' || ch=='^')
        return 3;
        else
            return -1;
}
int top=-1;
void push(char a[],char x)
{
    a[++top]=x;

}
char pop(char a[])
{
    char x=a[top];
    top--;
    return x;
}
void conversion(string s)
{
    char a[s.length()];
    string str1="";
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='a' && s[i]<='z')
        {
         str1=str1+s[i];
}

        else if(s[i]=='(')
       {
            push(a,s[i]);

       }
        else if(top!=-1 && s[i]==')')
        {
            char x=pop(a);
            while(x!='(')
            {
                str1=str1+x;
                x=pop(a);
            }

        }
        else
        {

            while(top!=-1 && priority(a[top])>=priority(s[i]))
            {
                 char x=pop(a);
                str1=str1+x;
            }
             push(a,s[i]);

        }
        //cout<<str1<<endl;
    }
    while(top!=-1)
    {
        char x=pop(a);
       str1=str1+x;
    }
    cout<<str1;

}
int main()
{
    string s;
    cin>>s;
    conversion(s);
    return 0;
}
