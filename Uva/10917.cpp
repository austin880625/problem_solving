#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#define MAXN 1005
#define INF 2147483647

using namespace std;

struct edge
{
    int from,to,w;
};
struct Node
{
    int d,id;
    bool operator <(const Node &x)const{
        return d>x.d;
    }
};

vector<edge> edges;
vector<int> G[MAXN];
vector<int> DAG[MAXN];

int N,M;
int d[MAXN];
int ind[MAXN];
int ans[MAXN];

void Dijkstra(int s)
{
    for(int i=0;i<=N;i++)d[i]=INF;
    d[s]=0;
    priority_queue<Node> Q;
    Q.push((Node){0,s});
    while(!Q.empty())
    {
        Node x=Q.top();Q.pop();
        for(int i=0;i<G[x.id].size();i++)
        {
            edge &e=edges[G[x.id][i]];
            if(d[e.to]>d[x.id]+e.w)
            {
                d[e.to]=d[x.id]+e.w;
                Q.push((Node){d[e.to],e.to});
            }
        }
    }
}

int main()
{
    while(scanf("%d",&N)==1&&N)
    {
        for(int i=0;i<=N;i++)G[i].clear(),DAG[i].clear(),ans[i]=ind[i]=0;
        edges.clear();
        scanf("%d",&M);
        for(int i=0;i<M;i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            G[u].push_back(edges.size());
            edges.push_back((edge){u,v,w});
            G[v].push_back(edges.size());
            edges.push_back((edge){v,u,w});
        }
        Dijkstra(2);
        //puts("dijkstra finished");
        for(int i=0;i<edges.size();i++)
        {
            edge &e=edges[i];
            if(d[e.to]<d[e.from])DAG[e.from].push_back(e.to),ind[e.to]++;
        }

        queue<int> Q;
        for(int i=1;i<=N;i++)
        {
            if(ind[i]==0)Q.push(i);
        }
        ans[1]=1;
        while(!Q.empty())
        {
            int x=Q.front();Q.pop();
            for(int i=0;i<DAG[x].size();i++)
            {
                int v=DAG[x][i];
                ans[v]+=ans[x];
                ind[v]--;
                if(!ind[v])Q.push(v);
            }
        }
        printf("%d\n",ans[2]);
    }
    return 0;
}
