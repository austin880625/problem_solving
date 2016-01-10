#include<iostream>
#include<stdio.h>

using namespace std;
int BIT[10005];
int N,M,K;
int lowbit(int x){return x&(-x);}
int sufsum(int x)
{
    int res=0;
    while(x>0)
    {
        res+=BIT[x];
        x-=lowbit(x);
    }
    return res;
}
void add(int x,int v)
{
    while(x<=N)
    {
        BIT[x]+=v;
        x+=lowbit(x);
    }
}
int query(int x)
{
    int l=1,r=N;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(sufsum(mid)<x)l=mid+1;
        else r=mid;
    }
    return l;
}
int main()
{
    while(scanf("%d%d%d",&N,&K,&M)==3&&N&&K&&M)
    {
        int now=N,last=M,pos;
        for(int i=1;i<=N;i++){add(i,1);}
        for(int i=0;i<N-1;i++)
        {
            //next=(last+K)%now;
            pos=query(last);
            //cout<<pos<<" ";
            add(pos,-1);
            now--;
            last=(last-1+K)%now;
            if(last==0)last=now;
        }
        pos=query(1);
        printf("%d\n",pos);
        add(pos,-1);
    }
}
