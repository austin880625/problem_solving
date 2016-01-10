#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <assert.h>
#define MAXN 100005
using namespace std;

struct Node
{
    int sum;
    Node *ch[2];
    Node(int _v){sum=_v;ch[0]=ch[1]=NULL;}
    Node(Node *T){sum=T->sum;ch[0]=T->ch[0],ch[1]=T->ch[1];}
    Node(){ch[0]=ch[1]=NULL;}
};
struct order
{
    int ord,v;
    bool operator <(const order &x)const{
        return v<x.v;
    }
};
Node *root[MAXN];
order A[MAXN];
int B[MAXN],pos[MAXN];
int N,M;
int x,v,ql,qr,k;

Node* copyNode(Node *&o)
{
    Node *res=new Node(o);
    return res;
}

void build(Node *&o,int l,int r)
{
    if(!o)o=new Node(0);
    if(l==r){o->sum=0;return ;}
    int mid=(l+r)/2;
    build(o->ch[0],l,mid);
    build(o->ch[1],mid+1,r);
    o->sum=o->ch[0]->sum+o->ch[1]->sum;
}

void add(Node *&o,int l,int r)
{
    if(l==r)
    {
        assert(l==x);
        o->sum+=v;
        return ;
    }
    int mid=(l+r)/2;
    if(x<=mid)o->ch[0]=copyNode(o->ch[0]),add(o->ch[0],l,mid);
    if(x>mid)o->ch[1]=copyNode(o->ch[1]),add(o->ch[1],mid+1,r);
    o->sum=o->ch[0]->sum+o->ch[1]->sum;
    //printf("%d %d %d\n",o->sum,l,r);
}

int query(Node *&o1,Node *&o2,int l,int r)
{
    if(l==r)return l;
    int now=o1->ch[0]->sum-o2->ch[0]->sum;
    int mid=(l+r)/2;
    //printf("%d %d %d\n",l,r,o1->ch[0]->sum);
    if(k<=now)
    {
        return query(o1->ch[0],o2->ch[0],l,mid);
    }
    else
    {
        k-=now;
        return query(o1->ch[1],o2->ch[1],mid+1,r);
    }
}
int main()
{
    while(scanf("%d%d",&N,&M)==2)
    {
        root[0]=NULL;
        for(int i=0;i<N+5;i++)B[i]=-1,pos[i]=1;
        for(int i=1;i<=N;i++)
        {
            scanf("%d",&A[i].v);
            A[i].ord=i;
            root[i]=NULL;
        }
        sort(A+1,A+N+1);
        int cnt=0,now=0;
        for(int i=1;i<=N;i++)
        {
            if(A[now].v!=A[i].v)now=i,cnt++;
            B[A[i].ord]=cnt;
            pos[cnt]=i;
            //printf("%d\n",cnt);
        }
        build(root[0],0,cnt+1);
        for(int i=1;i<=N;i++)
        {
            x=B[i],v=1;
            root[i]=new Node(root[i-1]);
            //printf("\n ver %d\n",i);
            add(root[i],0,cnt+1);
        }
        for(int i=0;i<M;i++)
        {
            scanf("%d%d%d",&ql,&qr,&k);
            int v=query(root[qr],root[ql-1],0,cnt+1);
            printf("%d\n",A[pos[v]].v);
        }
    }
    return 0;
}
