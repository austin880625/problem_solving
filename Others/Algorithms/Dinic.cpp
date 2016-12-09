#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#define MAXN 505
#define INF 2147483647
using namespace std;
struct edge
{
    int from,to,cap,flow;
};
vector<int> G[MAXN];
vector<edge> edges;
int N,M;
bool vis[MAXN];
int d[MAXN];
int cur[MAXN];
int s,t;

bool BFS()
{
    for(int i=0;i<MAXN;i++)vis[i]=0;
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
                vis[e.to]=1;
                d[e.to]=d[x]+1;
                Q.push(e.to);
            }
        }
    }
    return vis[t];
}

int DFS(int x,int a)
{
    if(x==t||a==0)return a;
    int flow=0,f;
    for(int& i=cur[x];i<G[x].size();i++)
    {
        edge &e=edges[G[x][i]];
        if(d[e.to]==d[x]+1)
        {
            f=DFS(e.to,min(a,e.cap-e.flow));
            if(f>0)
            {
                a-=f;
                e.flow+=f;
                edges[G[x][i]^1].flow-=f;
                flow+=f;
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

    return 0;
}
