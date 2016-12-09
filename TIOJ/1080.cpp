#include <stdio.h>
#include <iostream>
#define MAXN 100005
using namespace std;

int N;
int A[MAXN];
long long int ANS;

int rand()
{
    static int x=7122;
    return x=x*0xdefaced+1;
}

struct Node
{
    int pri,v;
    long long int sz;
    Node *ch[2];
    Node(int _v)
    {
        pri=rand();
        v=_v;
        sz=1;
        ch[0]=ch[1]=NULL;
    }
};

long long int getsz(Node *&o)
{
    if(!o)return 0;
    o->sz=1;
    if(o->ch[0])o->sz+=o->ch[0]->sz;
    if(o->ch[1])o->sz+=o->ch[1]->sz;
    return o->sz;
}

void split(Node *&o,int k,Node *&l,Node *&r)
{
    if(!o)l=r=NULL;
    else if(o->v>k)
    {
        l=o;
        split(o->ch[1],k,l->ch[1],r);
        getsz(l);
    }
    else
    {
        r=o;
        split(o->ch[0],k,l,r->ch[0]);
        getsz(r);
    }
}
// satisfy that evry nodes in *l is smaller than every nodes in *r
Node *merge(Node *l,Node *r)
{
    if(!l||!r)return l?l:r;
    if(l->pri>r->pri)
    {
        l->ch[1]=merge(l->ch[1],r);
        getsz(l);
        return l;
    }
    else
    {
        r->ch[0]=merge(l,r->ch[0]);
        getsz(r);
        return r;
    }
}

Node *T;
int kase=0;
int main()
{
    while(scanf("%d",&N)==1&&N)
    {
        T=NULL;
        ANS=0;
        for(int i=0;i<N;i++)
        {
            scanf("%d",A+i);
            Node *L=NULL,*R=NULL;
            split(T,A[i],L,R);
            ANS+=getsz(L);
            T=merge(L,new Node(A[i]));
            T=merge(T,R);
        }
        printf("Case #%d: %lld\n",++kase,ANS);
    }
    return 0;
}
