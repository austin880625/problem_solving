#include<iostream>
#include<stdio.h>
#include<queue>
#define MAXN 1000005
#define ll long long int
using namespace std;

int C[MAXN];
int X[MAXN];
int F[MAXN];
int nxt[MAXN];
int prev[MAXN];

int N,M,A,B;
int T;

int ran()
{
    static int x=20151103;
    return x=x*0xdefaced+1;
}

struct Node
{
    int v,pri,sz;
    Node *ch[2];
    Node(int _v){v=_v;pri=ran();ch[0]=ch[1]=NULL;sz=1;}
    void maintain()
    {
        sz=1;
        if(ch[0])sz+=ch[0]->sz;
        if(ch[1])sz+=ch[1]->sz;
    }
};
int getsz(Node *&O){return O ? O->sz : 0;}
void rotate(Node *&O,int d)
{
    Node *T=O->ch[d^1];
    O->ch[d^1]=T->ch[d];
    T->ch[d]=O;
    O->maintain();T->maintain();
    O=T;
}
void Insert(Node *&O,int v)
{
    if(!O){O=new Node(v);return ;}
    int dir=(v<O->v ? 0 : 1);
    Insert(O->ch[dir],v);
    if(O->ch[dir]->pri > O->pri)rotate(O,dir^1);

    O->maintain();
}
void Delete(Node *&O,int v)
{
    if(O->v==v)
    {
        Node *P=O;
        if(!O->ch[0])
        {
            O=O->ch[1];
            delete P;
        }
        else if(!O->ch[1])
        {
            O=O->ch[0];
            delete P;
        }
        else
        {
            int dir=(O->ch[0]->pri > O->ch[1]->pri ? 1 : 0);
            rotate(O,dir);Delete(O->ch[dir],v);
        }
    }
    else
    {
        int dir=v<O->v ? 0:1;
        Delete(O->ch[dir],v);
    }
    if(O)O->maintain();
}
int kth(Node *&O,int k)
{
    int now=getsz(O->ch[0])+1;
    if(k==now)return O->v;
    int dir=k<now ? 0 : 1;
    return kth(O->ch[dir],k-dir*now);
}
Node *Treap;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        Treap=NULL;
        scanf("%d%d%d%d%d",&N,&M,&X[0],&A,&B);
        for(int i=1;i<=N;i++)
        {
            Insert(Treap,i);
            X[i]=((ll)A*(ll)X[i-1]+(ll)B)%M;
            C[i]=(((ll)X[i]+(ll)N-(ll)i)%((ll)N-i+1))+1;
        }
        for(int i=1;i<=N;i++)
        {
            int x=kth(Treap,C[i]);
            F[i]=x;
            Delete(Treap,x);
        }
        ll ans=0;
        ll t=1;

        printf("%lld\n",ans);
    }
    return 0;
}
