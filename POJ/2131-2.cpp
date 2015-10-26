#include<iostream>
#include<stdio.h>
#include<vector>
#define maxn 1000000
using namespace std;

int N,M;
int C[maxn*4];
int qr[maxn];
vector<int> fin;

int lowbit(int x){return x&(-x);}
int prefix_sum(int i)
{
    int res=0;
    while(i>0)
    {
        res+=C[i];
        i-=lowbit(i);
    }
    return res;
}
void add(int i,int delta)
{
    while(i<=N+M)
    {
        C[i]+=delta;
        i+=lowbit(i);
    }
}
int query(int x)    //query the position of xth non-zero value
{
    return prefix_sum(x)-prefix_sum(0);
}

int main()
{
    int maxpos=0;
    scanf("%d %d",&N,&M);
    for(int i=1;i<=N+M;i++)add(i,1);
    for(int i=0;i<N;i++)
    {
        scanf("%d",&qr[i]);
    }
    fin.clear();fin.resize(N+M);
    int pos;
    for(int i=N;i>=1;i--)
    {
        if(query(qr[i-1])-query(qr[i-1]-1))pos=qr[i];
        else pos=query(qr[i-1]);maxpos=max(pos,maxpos);
        cout<<pos<<endl;
        fin[pos]=i;
        add(pos,-1);
    }
    for(int i=1;i<=maxpos;i++)printf("%d ",fin[i]);
}
