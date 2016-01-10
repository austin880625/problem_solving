#include<iostream>
#include<stdio.h>

using namespace std;

int A[100];
int C[100];
int n;

int lowbit(int x)
{
    return x&(-x);
}

int suffix_sum(int i)
{
    int res=0;
    while(i>0)
    {
        res+=C[i];
        i-=lowbit(i);
    }
    return res;
}

int query(int L,int R)
{
    return suffix_sum(R)-suffix_sum(L-1);
}

void add(int i,int delta)
{
    while(i<=n)
    {
        C[i]+=delta;
        i+=lowbit(i);
    }
}

int main()
{
    while(cin>>n)
    {
        if(n==0)break;
        cout<<"start insert"<<endl;
        for(int i=1;i<=n;i++)
        {
            cin>>A[i];
            add(i,A[i]);
            cout<<i<<" ";
        }
        cout<<endl<<"init end"<<endl;
        int c,x,y;
        while(cin>>c)
        {
            if(c==0)break;
            cin>>x>>y;
            if(c==1)add(x,y);
            if(c==2)cout<<query(x,y)<<endl;
        }
    }
    return 0;
}
