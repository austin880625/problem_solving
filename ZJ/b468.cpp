#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <assert.h>
#define MAXN 10005
#define MAXLOG 16
#define INF 1000000000
using namespace std;

struct edge
{
    int u,v;
    int w;
    bool operator <(const edge &e)const{
        return w>e.w;
    }
};
vector<edge> E;
vector<int> G[MAXN];
vector<edge> MST;
int N,M,Q;
int dj[MAXN];
int mincost[MAXN][MAXLOG];
int anc[MAXN][MAXLOG];
int vis[MAXN];
int depth[MAXN];
int find(int x){return x==dj[x] ? x : dj[x]=find(dj[x]);}
void Kruskal()
{
    MST.clear();
    sort(E.begin(),E.end());
    for(int i=0;i<=N;i++)G[i].clear(),dj[i]=i;
    assert(E.size()==2*M);
    for(int i=0;i<E.size();i++)
    {
        int u=E[i].u,v=E[i].v,x=find(u),y=find(v);
        if(x!=y)
        {
            G[u].push_back(MST.size());
            MST.push_back((edge){u,v,E[i].w});
            G[v].push_back(MST.size());
            MST.push_back((edge){v,u,E[i].w});
            dj[x]=y;
        }
    }
}

void dfs(int now,int fa,int dep)
{
    anc[now][0]=fa;
    vis[now]=1;
    depth[now]=dep;
    //for(int i=0;i<dep;i++)printf("\t");
    for(int i=0;i<G[now].size();i++)
    {
        edge &e=MST[G[now][i]];
        int v=e.v;
        if(v==fa||vis[v])continue;
        mincost[v][0]=e.w;
        //if(v==3)cout<<mincost[v][0]<<endl;
        dfs(v,now,dep+1);
    }
}

void pre_process()
{
    for(int i=1;i<=N;i++)
    {
        for(int j=1;(1<<j)<=N;j++)anc[i][j]=-1;
    }
    for(int j=1;(1<<j)<=N;j++)
    {
        for(int i=1;i<=N;i++)
        {
            if(anc[i][j-1]!=-1)
            {
                int A=anc[i][j-1];
                anc[i][j]=anc[A][j-1];
                mincost[i][j]=min(mincost[i][j-1],mincost[A][j-1]);
                //cout<<"YEE"<<i<<" "<<j<<" "<<mincost[i][j]<<endl;
            }
        }
    }
}

int query(int x,int y)
{
    int res=INF;
    int log;
    if(depth[x]<depth[y])swap(x,y);
    for(log=0;(1<<log)<=depth[x];log++);log--;
    for(int i=log;i>=0;i--)
    {
        if(depth[x]-(1<<i)>=depth[y])res=min(res,mincost[x][i]),x=anc[x][i];
    }
    assert(depth[x]==depth[y]);
    if(x==y)return res;
    for(int i=log;i>=0;i--)
    {
        if(anc[x][i]!=-1&&anc[x][i]!=anc[y][i])
        {
            res=min(res,mincost[x][i]),x=anc[x][i];
            res=min(res,mincost[y][i]),y=anc[y][i];
        }
    }
    assert(anc[x][0]==anc[y][0]);
    res=min(res,mincost[x][0]);
    res=min(res,mincost[y][0]);
    return res;
}

int main()
{
    while(scanf("%d%d",&N,&M)==2)
    {
        int x,y,z;
        E.clear();
        for(int i=0;i<M;i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            //G[x].push_back(E.size());
            E.push_back((edge){x,y,z});
            //G[y].push_back(E.size());
            E.push_back((edge){y,x,z});
        }
        for(int i=0;i<=N;i++)for(int j=0;j<MAXLOG;j++)mincost[i][j]=INF;
        Kruskal();
        //for(int i=0;i<MST.size();i++)cout<<"MST"<<i<<" "<<MST[i].u<<" "<<MST[i].v<<" "<<MST[i].w<<endl;
        for(int i=0;i<=N;i++)vis[i]=0;
        for(int i=1;i<=N;i++)if(!vis[i])
        {
            dfs(i,-1,0);
        }
        pre_process();
        scanf("%d",&Q);
        for(int i=0;i<Q;i++)
        {
            scanf("%d%d",&x,&y);
            if(find(x)!=find(y))printf("-1\n");
            else printf("%d\n",query(x,y));
        }
    }
    return 0;
}
/*
3 4
1 2 1
2 3 1
2 3 3
1 3 5

*/
