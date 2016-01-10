#include<iostream>
#include<stdio.h>
#include<vector>
#define MAXN 32800
using namespace std;

int lowbit(int x){return x&(-x);}
struct BIT
{
    int tree[MAXN];
    BIT(){}
    void add(int x,int v)
    {
        while(x<MAXN)
        {
            tree[x]+=v;
            x+=lowbit(x);
        }
    }
    int sufsum(int x)
    {
        int res=0;
        while(x>0)
        {
            res+=tree[x];
            x-=lowbit(x);
        }
        return res;
    }
};
vector<BIT> CHAINS;
//BIT CHAINS[MAXN];
struct edge
{
    int u,v;
};
vector<edge> edges;
vector<int> G[MAXN];

int chain[MAXN];
int top[MAXN];
int p[MAXN];
int dep[MAXN];
int sz[MAXN];
int N,Q,csz,es;
//int val[MAXN];

void dfs1(int now,int fa,int depth)
{
    //cout<<"1 "<<now<<endl;
    dep[now]=depth;
    sz[now]=0;
    p[now]=fa;
    for(int i=0;i<G[now].size();i++)
    {
        edge &e=edges[G[now][i]];
        if(e.v==fa)continue;
        dfs1(e.v,now,depth+1);
        sz[now]+=sz[e.v];
    }
    sz[now]++;
}

void dfs2(int now,int fa,int head,int ch)
{
    //cout<<"dfs2 "<<now<<endl;
    top[now]=head;
    chain[now]=ch;
    int maxw=0;
    edge e=edges[G[now][maxw]];
    for(int i=0;i<G[now].size();i++)
    {
        e=edges[G[now][i]];
        if(e.v==fa)continue;
        //cout<<sz[edges[G[now][maxw]].v]<<" ";
        if(edges[G[now][maxw]].v==fa||sz[edges[G[now][maxw]].v]<sz[e.v]){maxw=i;}
    }
    //out<<"maxw:"<<maxw<<endl;
    if(G[now].size()>1)
    {
        //cout<<"heavy!"<<endl;
        e=edges[G[now][maxw]];
        //if(now==5)
        //cout<<e.v<<" "<<sz[e.v]<<endl;
        dfs2(e.v,now,head,ch);
    }
    for(int i=0;i<G[now].size();i++)
    {
        e=edges[G[now][i]];
        if(i==maxw||e.v==fa||chain[e.v]!=-1)continue;
        CHAINS[csz++]=BIT();
        dfs2(e.v,now,e.v,csz-1);
    }
}

int query(int x)
{
    int res=0;
    while(x!=-1)
    {
        res+=CHAINS[chain[x]].sufsum(dep[x]-dep[top[x]]+1);
        x=top[x];
        x=p[x];
    }
    return res;
}

int main()
{
    while(scanf("%d",&N)==1)
    {
        int u,v;
        CHAINS.clear();csz=0;
        CHAINS.resize(N);
        edges.clear();es=0;
        edges.resize(2*N-2);
        for(int i=0;i<N;i++){chain[i]=-1;G[i].clear();}
        for(int i=0;i<N-1;i++)
        {
            scanf("%d%d",&u,&v);
            edges[es++]=(edge){u,v};
            G[u].push_back(es-1);
            edges[es++]=(edge){v,u};
            G[v].push_back(es-1);
        }
        dfs1(0,-1,0);
        CHAINS[csz++]=BIT();
        dfs2(0,-1,0,0);
        //for(int i=0;i<N;i++)cout<<top[i]<<" ";
        //puts("");
        //for(int i=0;i<N;i++)cout<<chain[i]<<" ";
        //puts("");
        scanf("%d",&Q);
        int x,k;
        for(int i=0;i<Q;i++)
        {
            scanf("%d%d",&x,&k);
            CHAINS[chain[x]].add(dep[x]-dep[top[x]]+1,k);
            printf("%d\n",query(x));
        }
    }
    return 0;
}
