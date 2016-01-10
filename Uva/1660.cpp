#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <assert.h>
#define MAXN 110
#define INF 500000000
using namespace std;

struct edge
{
    int from,to,cap,flow;
};
vector<edge> edges;
vector<int> G[MAXN];
int N,M;
void addedge(int u,int v,int cap)
{
    G[u].push_back(edges.size());
    edges.push_back((edge){u,v,cap,0});
    G[v].push_back(edges.size());
    edges.push_back((edge){v,u,0,0});
}
queue<int> Q;
int vis[MAXN];
int d[MAXN];
int cur[MAXN];
bool BFS(int s,int t)
{
    for(int i=0;i<N;i++)vis[2*i]=vis[2*i+1]=0;
    Q.push(s);
    d[s]=0;
    vis[s]=1;
    while(!Q.empty())
    {
        int x=Q.front();Q.pop();
        for(int i=0;i<G[x].size();i++)
        {
            edge &e=edges[G[x][i]];
            if(!vis[e.to]&&e.cap>e.flow)
            {
                Q.push(e.to);
                vis[e.to]=1;
                d[e.to]=d[x]+1;
            }
        }
    }
    return vis[t];
}

int DFS(int now,int a,int t)
{
    if(a==0||now==t)return a;
    int f,flow=0;
    for(int &i=cur[now];i<G[now].size();i++)
    {
        edge &e=edges[G[now][i]];
        if(d[e.to]==d[now]+1)
        {
            f=DFS(e.to,min(a,e.cap-e.flow),t);
            if(f>0)
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

int Dinic(int s,int t)
{
    int res=0;
    while(BFS(s,t))
    {
        //if(s==0&&t==3)cout<<"YEE"<<res<<endl;
        for(int i=0;i<N;i++)cur[2*i]=cur[2*i+1]=0;
        res+=DFS(s,INF,t);
    }
    return res;
}

int main()
{
    while(scanf("%d%d",&N,&M)==2)
    {
        edges.clear();
        for(int i=0;i<N;i++){G[2*i].clear(),G[2*i+1].clear();}
        for(int i=0;i<N;i++)
        {
            addedge(2*i,2*i+1,1);
        }
        int u,v;
        for(int i=0;i<M;i++)
        {
            scanf(" (%d,%d)",&u,&v);
            addedge(2*u+1,2*v,INF);
            addedge(2*v+1,2*u,INF);
        }
        int ans=INF;
        for(int s=0;s<N;s++)
        {
            for(int t=0;t<N;t++)
            {
                if(s==t)continue;
                //cout<<s<<" "<<t<<" "<<ans<<endl;
                for(int i=0;i<edges.size();i++)edges[i].flow=0;
                ans=min(ans,Dinic(2*s+1,2*t));
                //cout<<ans<<endl;
            }
        }
        if(ans>=INF-5)printf("%d\n",N);
        else
        {
            printf("%d\n",ans);
        }
    }
    return 0;
}
