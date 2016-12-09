#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#define MAXN 105
#define INF 2147483646

using namespace std;

struct edge
{
    int from,to,cap,flow;
};

vector<int> G[MAXN];
vector<edge> edges;
int N,C;
int s,t;
bool vis[MAXN];
int cur[MAXN],d[MAXN];

bool BFS()
{
    for(int i=0;i<=N;i++)vis[i]=false;
    queue<int> Q;
    Q.push(s);
    vis[s]=true;
    d[s]=0;
    while(!Q.empty())
    {
        int x=Q.front();Q.pop();
        for(int i=0;i<G[x].size();i++)
        {
            edge &e=edges[G[x][i]];
            if(!vis[e.to]&&e.cap>e.flow)
            {
                vis[e.to]=true;
                Q.push(e.to);
                d[e.to]=d[x]+1;
            }
        }
    }
    return vis[t];
}

int DFS(int now,int a)
{
    if(now==t||a==0)return a;
    int f,flow=0;
    for(int i=cur[now];i<G[now].size();i++)
    {
        edge &e=edges[G[now][i]];
        if(d[e.to]==d[now]+1)
        {
            f=DFS(e.to,min(a,e.cap-e.flow));
            if(f)
            {
                flow+=f;
                e.flow+=f;
                edges[G[now][i]^1].flow-=f;
                a-=f;
                if(a==0)break;
            }
        }
    }
    return flow;
}

int Dinic()
{
    int res=0;
    while(BFS())
    {
        for(int i=0;i<=N;i++)cur[i]=0;
        res+=DFS(s,INF);
    }
    return res;
}

int main()
{
    int kase=0;
    while(scanf("%d",&N)==1&&N!=0)
    {
        for(int i=0;i<=N;i++)G[i].clear();
        edges.clear();
        scanf("%d%d%d",&s,&t,&C);
        for(int i=0;i<C;i++)
        {
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            G[u].push_back(edges.size());
            edges.push_back((edge){u,v,c,0});
            G[v].push_back(edges.size());
            edges.push_back((edge){v,u,0,0});
            G[v].push_back(edges.size());
            edges.push_back((edge){v,u,c,0});
            G[u].push_back(edges.size());
            edges.push_back((edge){u,v,0,0});
        }
        int ans=Dinic();
        printf("Network %d\n",++kase);
        printf("The bandwidth is %d.\n\n",ans);
    }
    return 0;
}
