#include <stdio.h>
#include <iostream>
#include <algorithm>
#define MAXN 1000000005
#define LL long long int

using namespace std;

int R,C,N;
int T,P,Q,U,V;
LL K;
inline LL GCD(LL a,LL b)
{
    //cout<<a<<" "<<b<<endl;
    LL t;
    if(a<b)swap(a,b);
    while(a&&b){t=a;a=b;b=t%b;}
    return a;
}
void assert(bool con)
{
    int a;
    if(!con)
    {
        while(1)a++;
    }
}

struct Node2
{
    LL gcd;
    int lonely_pos;
    Node2 *ch[2];
    Node2(LL g,int lp){gcd=g;lonely_pos=lp;ch[0]=ch[1]=NULL;}
};

struct Node1
{
    Node2 *t;
    Node1 *ch[2];
    Node1(){t=NULL;ch[0]=ch[1]=NULL;}
};

inline LL getgcd(Node2 *o){return o ? o->gcd : 0;}
inline Node2* getch2(Node2 *&o,int dir){return o ? o->ch[dir] : o;}
inline Node2* gett(Node1 *&o){return o ? o->t : NULL;}

void push(Node2 *o,int l,int r)
{
    if(l==r||!o)return ;
    int mid=(l+r)/2;
    if(o->lonely_pos!=-1)
    {
        assert(o->ch[0]==NULL&&o->ch[1]==NULL);
        if(o->lonely_pos<=mid)
            o->ch[0]=new Node2(o->gcd,o->lonely_pos);
        else
            o->ch[1]=new Node2(o->gcd,o->lonely_pos);
        o->lonely_pos=-1;
    }
}

void setval2(Node2 *&o,int l,int r,Node2 *lch,Node2 *rch)
{
    //cout<<"2 "<<l<<r<<endl;
    push(lch,l,r),push(rch,l,r);
    if(!o){o=new Node2(GCD(getgcd(lch),getgcd(rch)),Q);return ;}
    if(l==r)
    {
        o->gcd=GCD(getgcd(lch),getgcd(rch));
        return ;
    }
    int mid=(l+r)/2;
    if(o->lonely_pos!=-1)
    {
        assert(o->ch[0]==NULL&&o->ch[1]==NULL);
        if(o->lonely_pos<=mid)
            o->ch[0]=new Node2(o->gcd,o->lonely_pos);
        else
            o->ch[1]=new Node2(o->gcd,o->lonely_pos);
        o->gcd=0;
        o->lonely_pos=-1;
    }
    if(Q<=mid)setval2(o->ch[0],l,mid,getch2(lch,0),getch2(rch,0));
    else setval2(o->ch[1],mid+1,r,getch2(lch,1),getch2(rch,1));
    o->gcd=GCD(getgcd(o->ch[0]),getgcd(o->ch[1]));
}
void setval2L(Node2 *&o,int l,int r)
{
    if(!o){o=new Node2(K,Q);return ;}
    //cout<<"leaf "<<l<<" "<<r<<endl;
    if(l==r)
    {
        o->gcd=K;
        return ;
    }
    int mid=(l+r)/2;
    if(o->lonely_pos!=-1)
    {
        assert(o->ch[0]==NULL&&o->ch[1]==NULL);
        if(o->lonely_pos<=mid)
            o->ch[0]=new Node2(o->gcd,o->lonely_pos);
        else
            o->ch[1]=new Node2(o->gcd,o->lonely_pos);
        o->gcd=0;
        o->lonely_pos=-1;
    }
    if(Q<=mid)setval2L(o->ch[0],l,mid);
    else setval2L(o->ch[1],mid+1,r);
    o->gcd=GCD(getgcd(o->ch[0]),getgcd(o->ch[1]));
}

void setval1(Node1 *&o,int l,int r)
{
//cout<<l<<" "<<r<<endl;
    if(!o)o=new Node1();
    if(l==r)
    {
        setval2L(o->t,0,C-1);
        return ;
    }
    int mid=(l+r)/2;
    if(P<=mid)setval1(o->ch[0],l,mid);
    else setval1(o->ch[1],mid+1,r);
    setval2(o->t,0,C-1,gett(o->ch[0]),gett(o->ch[1]));
}

LL query2(Node2 *&o,int l,int r)
{
    if(!o)return 0;
    //cout<<"querying2 at "<<l<<" "<<r<<" "<<o->lonely_pos<<" "<<o->gcd<<endl;
    if(Q<=l&&r<=V)return o->gcd;
    if(o->lonely_pos!=-1){return Q<=o->lonely_pos&&o->lonely_pos<=V ? o->gcd : 0;}
    LL res=0;
    int mid=(l+r)/2;
    if(Q<=mid)res=GCD(res,query2(o->ch[0],l,mid));
    if(V>mid)res=GCD(res,query2(o->ch[1],mid+1,r));
    return res;
}
LL query1(Node1 *&o,int l,int r)
{
    if(!o)return 0;
    if(P<=l&&r<=U)return query2(o->t,0,C-1);
    LL res=0;int mid=(l+r)/2;
    if(P<=mid)res=GCD(res,query1(o->ch[0],l,mid));
    if(U>mid)res=GCD(res,query1(o->ch[1],mid+1,r));
    return res;
}

Node1 *TREE;
int main()
{
    while(scanf("%d%d%d",&R,&C,&N)==3)
    {
        TREE=NULL;
        for(int i=0;i<N;i++)
        {
            scanf("%d",&T);
            if(T==1)
            {
                scanf("%d%d%lld",&P,&Q,&K);
                setval1(TREE,0,R-1);
            }
            else
            {
                scanf("%d%d%d%d",&P,&Q,&U,&V);
                if(P>U)swap(P,U);
                if(Q>V)swap(Q,V);
                printf("%lld\n",query1(TREE,0,R-1));
            }
        }
    }
}

