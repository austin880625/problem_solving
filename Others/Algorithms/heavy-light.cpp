#include<iostream>
#include<stdio.h>
#include<vector>
#define INF 2147483646
using namespace std;
const int MAXN=33000;

int sz[MAXN];
int vis[MAXN];
int p[MAXN],dep[MAXN];
int top[MAXN],chain[MAXN];
int csz;

struct STNode
{
    int sum;
    STNode *lc,*rc;
    STNode(int _v){sum=v=_v;}
};
STNode *ST[MAXN];

void build(STNode *&O,int L,int R)
{
    if(!O)O=new STNode(0);
    if(L==R){O->sum=0;return ;}
    int mid=(L+R)/2;
    build(O->lc,L,mid);
    build(O->rc,mid+1,R);
}

int X,qL,qR;
int qv;
void addST(STNode *&O,int L,int R)
{
    if(L==R){O->sum+=qv;return ;}
    int mid=(L+R)/2;
    if(X<=L)addST(O->lc,L,mid);
    else addST(O->rc,mid+1,R);
    O->sum=0;
    if(O->lc)O->sum+=O->lc->sum;
    if(O->rc)O->sum+=O->rc->sum;
}

struct edge
{
    int u,v,w;
};

vector<edge> edges;
vecto<int> G[MAXN];

void dfs1(int now,int fa,int depth)
{
    vis[now]=1;
    dep[now]=depth;
    p[now]=fa;
    sz[now]=0;
    for(int i=0;i<G[now].size();i++)
    {
        edge &e=edges[G[now][i]];
        if(!vis[e.v])
        {
            dfs(e.v,now,depth+1);
            sz[now]+=sz[e.v];
        }
    }
    sz[now]++;
}

void dfs2(int now,int head,int ch)
{
    top[now]=head;
    chain[now]=ch;
    int maxch=0;
    edge &e=edges[G[now][maxch]];
    for(int i=0;i<G[now].size();i++)
    {
        e=edges[G[now][i]];
        if(sz[edges[G[now][maxch]].v]<sz[e.v])maxch=i;
    }
    e=edges[G[now][maxch]];
    addST(ST[ch],depth[e.to]-depth[head],e.w);
    dfs2(e.to,head,ch);
    for(int i=0;i<G[now].size();i++)
    {
        if(i==maxch)continue;
        e=edges[G[now][i]];
        dfs2(e.to,e.to,++csz);
    }
}

int main()
{
    csz=0;
    return 0;
}
