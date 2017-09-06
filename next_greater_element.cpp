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

void next_greater_stack(int a[],int p[],int n)
{

   int s=p[0];
       push(s,a);
      // cout<<s<<endl;
   for(int i=1;i<n;i++)
   {

       int x=pop(a);
       int next=p[i];
       while(next>x)
       {
           cout<<x<<"   "<<next<<endl;
           x=pop(a);
       }
       push(x,a);
       push(next,a);
   }
while(top!=-1)
{
    int x=pop(a);
    cout<<x<<"  "<<"-1"<<endl;
}
}
int main()
{
    int *a;
    int n;
    cin>>n;
    a=new int[n];
    int p[n];
    for(int i=0;i<n;i++)
    {
        int x;
cin>>p[i];
    }
   // cout<<top;
   next_greater_stack(a,p,n);

return 0;
}
