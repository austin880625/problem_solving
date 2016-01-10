#include <iostream>
#include <stdio.h>
#include <vector>
#include <assert.h>
#include <algorithm>
#define MAXN 20005
#define MAXM 130005
#define MAXLOG 17
#define INF 21474836470
#define LL long long int
using namespace std;

struct edge
{
    int u,v;
    LL w;
    bool operator <(const edge &x)const{
        return w<x.w;
    }
};
vector<edge> edges;
vector<edge> MST;
vector<int> nonMST;
vector<int> G[MAXN];
int T,N,M;
LL MSTW;
int dj[MAXN];
int dep[MAXN],vis[MAXN];
int anc[MAXN][MAXLOG];
LL maxcost[MAXN][MAXLOG];
int find(int x){return x==dj[x]?x:dj[x]=find(dj[x]);}
void kruskal()
{
    MST.clear(),nonMST.clear();
    for(int i=0;i<N;i++)G[i].clear(),dj[i]=i,vis[i]=0;
    MSTW=0;
    sort(edges.begin(),edges.end());
    for(int i=0;i<edges.size();i++)
    {
        edge &e=edges[i];
        LL u=e.u,v=e.v,x=find(u),y=find(v);
        if(x!=y)
        {
            G[u].push_back(MST.size());
            MST.push_back((edge){u,v,e.w});
            G[v].push_back(MST.size());
            MST.push_back((edge){v,u,e.w});
            MSTW+=e.w;
            dj[x]=y;
        }
        else
        {
            nonMST.push_back(i);
        }
    }
}

void dfs(LL now,LL fa,LL depth)
{
    anc[now][0]=fa;
    dep[now]=depth;
    vis[now]=1;
    for(int i=1;(1<<i)<=N;i++)
    {
        if(anc[now][i-1]!=-1)
        {
            LL A=anc[now][i-1];
            anc[now][i]=anc[A][i-1];
            maxcost[now][i]=max(maxcost[now][i-1],maxcost[A][i-1]);
        }
    }
    for(int i=0;i<G[now].size();i++)
    {
        edge &e=MST[G[now][i]];
        int u=e.u,v=e.v;
        if(v==fa)continue;
        maxcost[v][0]=e.w;
        dfs(v,now,depth+1);
    }
}

LL query(int x,int y)
{
    int log;
    LL res=-INF;
    if(dep[x]<dep[y])swap(x,y);
    for(log=0;(1<<log)<=dep[x];log++);log--;
    for(int i=log;i>=0;i--)
    {
        if(dep[x]-(1<<i)>=dep[y])res=max(res,maxcost[x][i]),x=anc[x][i];
    }
    assert(dep[x]==dep[y]);
    if(x==y)return res;
    for(int i=log;i>=0;i--)
    {
        if(anc[x][i]!=-1&&anc[x][i]!=anc[y][i])
        {
            res=max(res,maxcost[x][i]),x=anc[x][i];
            res=max(res,maxcost[y][i]),y=anc[y][i];
        }
    }
    assert(anc[x][0]==anc[y][0]);
    res=max(res,maxcost[x][0]);
    res=max(res,maxcost[y][0]);
    return res;
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&N,&M);
        int u,v;
        LL w;
        edges.clear();
        for(int i=0;i<M;i++)
        {
            scanf("%d%d%lld",&u,&v,&w);
            edges.push_back((edge){u,v,w});
            //edges.push_back((edge){v,u,w});
        }
        kruskal();
        for(int i=0;i<N;i++)for(int j=1;j<MAXLOG;j++)anc[i][j]=-1,maxcost[i][j]=0;
        for(int i=0;i<N;i++)if(!vis[i])dfs(i,-1,0);
        LL secMST=INF;
        for(int i=0;i<nonMST.size();i++)
        {
            edge &e=edges[nonMST[i]];
            //printf("%d\n",secMST);
            assert(find(e.u)==find(e.v));
            LL mc=query(e.u,e.v);
            //printf("%d %d %d\n",e.u,e.v,mc);
            secMST=min(MSTW-mc+e.w,secMST);
        }
        printf("%lld\n",secMST-MSTW);
    }
    return 0;
}
