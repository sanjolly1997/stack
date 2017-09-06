#include <iostream>

using namespace std;
int top=-1;
void push(int x,int a[])
{
    a[++top]=x;
}
int pop(int a[])
{
    int x=a[top];
    top--;
    return x;
}
void insert_at_bottom(int x,int a[])
{
    if(top==-1)
    {
        push(x,a);
        return;
    }
    else
    {
        int c=pop(a);
        insert_at_bottom(x,a);
        push(c,a);
    }
}
void reverse_stack(int a[])
{
    if(top==-1)
        return;
    int x=pop(a);
    reverse_stack(a);
   insert_at_bottom(x,a);
}
int main()
{
    int *a;
    int n;
    cin>>n;
    a=new int[n];
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        push(x,a);
    }
    reverse_stack(a);
    cout<<endl;
while(top!=-1)
    {
        int x=pop(a);
         cout<<x;
    }
    return 0;
}
