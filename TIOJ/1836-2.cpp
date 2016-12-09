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

int ran(){static int x=7122;return x=x*0xdefaced+1;}
struct Node2
{
    LL gcd,v;
    int pri,key;
    Node2 *ch[2];
    Node2(int _key,LL g){key=_key;pri=ran();gcd=v=g;ch[0]=ch[1]=NULL;}
};

struct Node1
{
    Node2 *t;
    Node1 *ch[2];
    Node1(){t=NULL;ch[0]=ch[1]=NULL;}
};

inline LL getgcd(Node2 *o){return o ? o->gcd : 0;}
inline LL getv(Node2 *o){return o ? o->v : 0;}
inline Node2* getch2(Node2 *&o,int dir){return o ? o->ch[dir] : o;}
inline Node2* gett(Node1 *&o){return o ? o->t : NULL;}

inline void pull(Node2 *&o)
{
    if(o->ch[0]||o->ch[1])
        o->gcd=GCD(o->v,GCD(getgcd(o->ch[0]),getgcd(o->ch[1])));
    else
        o->gcd=o->v;
}

void split(Node2 *o,int k,Node2 *&a,Node2 *&b)
{
    if(!o){a=b=NULL;return ;}
    if(k<o->key)
    {
        b=o;
        split(o->ch[0],k,a,b->ch[0]);
        pull(b);
    }
    else
    {
        a=o;
        split(o->ch[1],k,a->ch[1],b);
        pull(a);
    }
}
Node2 *merge(Node2 *a,Node2 *b)
{
    if(!a||!b){return a?a:b;}
    if(a->pri>b->pri)
    {
        a->ch[1]=merge(a->ch[1],b);
        pull(a);
        return a;
    }
    else
    {
        b->ch[0]=merge(a,b->ch[0]);
        pull(b);
        return b;
    }
}

void insert(Node2 *&o,LL v)
{
    Node2 *a,*b;
    split(o,Q,a,b);
    b=merge(new Node2(Q,v),b);
    o=merge(a,b);
}
void remove(Node2 *&o,int k)
{
    Node2 *a,*b;
    split(o,k,o,a);
    split(o,k-1,o,b);
    delete b;
    o=merge(o,a);
}
Node2* find(Node2 *&o,int k)
{
    Node2 *t,*a;
    split(o,k-1,o,t);
    split(t,k,t,a);
    //o=merge(o,merge(t,a));
    return t;
}
void setval2(Node2 *&o,Node2 *lch,Node2 *rch)
{
    Node2 *a=find(lch,Q),*b=find(rch,Q);
    insert(o,GCD(getgcd(a),getgcd(b)));
}

void setval1(Node1 *&o,int l,int r)
{
//cout<<l<<" "<<r<<endl;
    if(!o)o=new Node1();
    if(l==r)
    {
        if(find(o->t,Q))remove(o->t,Q);
        insert(o->t,K);
        return ;
    }
    int mid=(l+r)/2;
    if(P<=mid)setval1(o->ch[0],l,mid);
    else setval1(o->ch[1],mid+1,r);
    setval2(o->t,gett(o->ch[0]),gett(o->ch[1]));
}

LL query2(Node2 *&o)
{
    if(!o)return 0;
    Node2 *a,*b,*c;
    split(o,Q-1,a,b);
    split(b,V,b,c);
    LL res=getgcd(b);
    return res;
}
LL query1(Node1 *&o,int l,int r)
{
    if(!o)return 0;
    if(P<=l&&r<=U)return query2(o->t);
    LL res=0;int mid=(l+r)/2;
    if(P<=mid)res=GCD(res,query1(o->ch[0],l,mid));
    if(U>mid)res=GCD(res,query1(o->ch[1],mid+1,r));
    return res;
}

void print(Node2 *&o,int dep)
{
    if(!o){puts("");return ;}
    for(int i=0;i<dep;i++)printf("\t");
    printf("pos:%d,gcd:%lld,v:%lld\n",o->key,o->gcd,o->v);
    for(int i=0;i<dep;i++)printf("\t");
    printf("{\n");
    for(int i=0;i<dep;i++)printf("\t");
    print(o->ch[0],dep+1);
    print(o->ch[1],dep+1);
    for(int i=0;i<dep;i++)printf("\t");
    printf("}\n");
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
            /*
            printf("printing tree:\n");
            print(TREE->t,0);
            printf("printing left tree:\n");
            if(TREE->ch[0])print(TREE->ch[0]->t,0);
            printf("printing right tree:\n");
            if(TREE->ch[1])print(TREE->ch[1]->t,0);
                */
        }
    }
}
