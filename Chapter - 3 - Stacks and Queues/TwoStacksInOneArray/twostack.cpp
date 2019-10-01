#include<bits/stdc++.h>
#define ll long long int
using namespace std;
//given number of elements in two stacks cannot exceed 100...
ll stac[101]={0};

ll top1=-1,top2=100;
void push1(int data)
{ if(stac[top1+1]==0){
  stac[top1+1]=data;
  top1+=1;}
  else
  cout<<"Full"<<endl;

}
void push2(int data)
{
  if(stac[top2-1]==0)
  {
    stac[top2-1]=data;
    top2-=1;
  }
  else
  {
    cout<<"Full"<<endl;
  }
}
void pop1()
{
  if(top1==-1)
  {
    cout<<"Empty"<<endl;
  }
  else
  { stac[top1]=0;
    top1-=1;
  }
}
void pop2()
{
  if(top2==100)
  {
    cout<<"Empty"<<endl;
  }
  else
  {
    stac[top2]=0;
    top2+=1;
  }
}
void disp()
{
  for(ll i=0;i<=top1;i++)
  cout<<stac[i]<<" ";
  cout<<endl;
  for(ll i=100;i>=top2;i--){if(stac[i]!=0)
  cout<<stac[i]<<" ";
}}
int main()
{
  cout<<"Press"<<endl;
  cout<<"1 for insertion in stack1"<<endl;
  cout<<"2 for deletion in stack1"<<endl;
  cout<<"3 for insertion in stack2"<<endl;
  cout<<"4 for deletion in stack2"<<endl;
  cout<<"0 to stop"<<endl;
  int ch,x;
  while(1)
  {
    cin>>ch;
    if(ch==1)
    {
      cout<<"Enter element"<<endl;

      cin>>x;
      push1(x);
      cout<<"Modified"<<endl;
      disp();
    }
    else if(ch==2)
    {
      pop1();
      cout<<"Modified"<<endl;
      disp();
    }
    else if(ch==3)
    {
      cout<<"Enter element"<<endl;
      cin>>x;
      push2(x);
      cout<<"Modified"<<endl;
      disp();
    }
    else if(ch==4)
    {
      pop2();
      cout<<"Modified"<<endl;
      disp();
    }
    else
    break;

  }
  cout<<"Final"<<endl;
  disp();

}
