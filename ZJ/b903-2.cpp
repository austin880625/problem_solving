#include <stdio.h>
#include <iostream>
#include <algorithm>
#define LL long long int
#define MAXN 300000

using namespace std;

int N,M,K;
struct Node2
{
    LL maxv;
    Node2 *ch[2];
    Node2(){maxv=0;ch[0]=ch[1]=NULL;}
};

int L2,R2;
int X,Y;LL V;
inline LL mx(Node2 *o){return o ? o->maxv : 0;}
void modify2(Node2 *&o,int l,int r)
{
    //cout<<"m2 "<<l<<" "<<r<<endl;
    if(!o)o=new Node2();
    if(l==r){o->maxv=max(o->maxv,V);return ;}

    int mid=(l+r)/2;
    if(Y<=mid)modify2(o->ch[0],l,mid);
    else modify2(o->ch[1],mid+1,r);
    o->maxv=max(mx(o->ch[0]),mx(o->ch[1]));
}

LL query2(Node2 *&o,int l,int r)
{
    //cout<<"2 "<<l<<" "<<r<<endl;
    if(!o)return 0;
    LL res=0;
    if(L2<=l&&r<=R2)return mx(o);

    int mid=(l+r)/2;
    if(L2<=mid)res=max(res,query2(o->ch[0],l,mid));
    if(R2>mid)res=max(res,query2(o->ch[1],mid+1,r));
    return res;
}

struct line
{
    int a,b;
    LL e;
    bool operator <(const line &r)const{
        return b<r.b;
    }
};

line L[MAXN];
LL dp[MAXN];
Node2 *T;

int main()
{
    L[0].a=0,L[0].b=0;L[0].e=0;
    while(scanf("%d%d%d",&N,&M,&K)==3)
    {
        T=NULL;
        for(int i=1;i<=K;i++)
        {
            scanf("%d%d%lld",&L[i].a,&L[i].b,&L[i].e);
        }
        sort(L+1,L+K+1);
        dp[0]=0;
        int sp=0;
        LL ans=0;
        for(int i=1;i<=K;i++)
        {
            if(L[i].b!=L[sp].b)
            {
                for(int j=sp;j<i;j++)
                {
                    Y=L[j].a,V=dp[j];
                    modify2(T,0,N);
                }
                sp=i;
            }
            dp[i]=0;
            //cout<<i<<endl;
            L2=0,R2=L[i].a-1;
            dp[i]=query2(T,0,N)+L[i].e;
            //cout<<dp[i]<<endl;
            ans=max(ans,dp[i]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
