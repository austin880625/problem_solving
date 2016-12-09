#include <stdio.h>
#include <iostream>
#define LL long long int
#define MAXN 100005

using namespace std;

LL GCD(LL a,LL b){return b ? GCD(b,a%b) : a;}

struct Node
{
    LL gcd,sum;
    Node *ch[2];
    Node(){gcd=0,sum=0,ch[0]=ch[1]=NULL;}
};

LL A[MAXN];
LL D[MAXN];
int N,Q;
int L,R,pos;
LL k;
Node *T;

void build(Node *&o,int l,int r)
{
    if(!o)o=new Node();
    if(l==r){o->gcd=o->sum=D[l];return ;}
    int mid=(l+r)/2;
    build(o->ch[0],l,mid);
    build(o->ch[1],mid+1,r);
    o->gcd=GCD(abs(o->ch[0]->gcd),abs(o->ch[1]->gcd));
    o->sum=o->ch[0]->sum+o->ch[1]->sum;
}

void add(Node *&o,int l,int r)
{
    if(pos==N+1)return ; //向在這裡
    if(l==r)
    {
        o->gcd+=k;
        o->sum+=k;
        return ;
    }
    int mid=(l+r)/2;
    if(pos<=mid)add(o->ch[0],l,mid);
    else add(o->ch[1],mid+1,r);
    o->gcd=GCD(abs(o->ch[0]->gcd),abs(o->ch[1]->gcd));
    o->sum=o->ch[0]->sum+o->ch[1]->sum;
}

LL query_gcd(Node *o,int l,int r)
{
    if(l>r)return 0;
    if(L<=l&&r<=R)
    {
        return abs(o->gcd);
    }
    int mid=(l+r)/2;
    LL res=0;
    if(L<=mid)res=GCD(query_gcd(o->ch[0],l,mid),res);
    if(R>mid)res=GCD(query_gcd(o->ch[1],mid+1,r),res);
    return res;
}

LL query_sum(Node *o,int l,int r)
{
    if(l>r)return 0;
    if(L<=l&&r<=R)
    {
        return o->sum;
    }
    int mid=(l+r)/2;
    LL res=0;
    if(L<=mid)res+=query_sum(o->ch[0],l,mid);
    if(R>mid)res+=query_sum(o->ch[1],mid+1,r);
    return res;
}

int main()
{
    while(scanf("%d%d",&N,&Q)==2)
    {
        T=NULL;
        A[0]=D[0]=0;
        for(int i=1;i<=N;i++)scanf("%lld",A+i),D[i]=A[i]-A[i-1];
        D[N+1]=-A[N];
        build(T,1,N);
        int type;
        for(int i=0;i<Q;i++)
        {
            scanf("%d%d%d",&type,&L,&R);
            if(type==1)
            {
                scanf("%lld",&k);
                pos=L,add(T,1,N);k=-k;
                pos=R+1,add(T,1,N);
            }
            else
            {
                L++;
                LL res=query_gcd(T,1,N);
                //cout<<"got gcd"<<endl;
                R=L-1;
                L=1;
                printf("%lld\n",GCD(res,query_sum(T,1,N)));
            }
        }
    }
    return 0;
}
