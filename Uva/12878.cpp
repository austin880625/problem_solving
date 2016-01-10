#include<iostream>
#include<stdio.h>
#include<queue>
#include<vector>
#define MAXP 10005
#define INF 2147483646
using namespace std;

struct node
{
    int id,d;
    bool operator <(const node &rhs)const
    {
        return d>rhs.d;
    }
};
struct edge
{
    int u,v,w;
};
vector<edge> edges;
vector<int> G[MAXP];
priority_queue<node> Q;
int d[2][MAXP];
int done[MAXP];
int P,T;
void addEdge(int u,int v,int w)
{
    G[u].push_back(edges.size());
    edges.push_back((edge){u,v,w});
    G[v].push_back(edges.size());
    edges.push_back((edge){v,u,w});
}

void Dijkstra(int dir,int s,int t)
{
    for(int i=0;i<P;i++){done[i]=0;d[dir][i]=INF;}
    d[dir][s]=0;
    Q.push((node){s,0});
    while(!Q.empty())
    {
        node x=Q.top();Q.pop();
        int u=x.id;
        if(done[u])continue;
        done[u]=1;
        for(int i=0;i<G[u].size();i++)
        {
            edge &e=edges[G[u][i]];
            int v=e.v;
            if(d[dir][v]>d[dir][u]+e.w)
            {
                d[dir][v]=d[dir][u]+e.w;
                Q.push((node){v,d[dir][v]});
            }
        }
    }
}

int main()
{
    while(scanf("%d%d",&P,&T)==2)
    {
        edges.clear();
        for(int i=0;i<P;i++)G[i].clear();
        for(int i=0;i<T;i++)
        {
            int p1,p2,l;
            scanf("%d%d%d",&p1,&p2,&l);
            addEdge(p1,p2,l);
        }
        Dijkstra(0,0,P-1);
        Dijkstra(1,P-1,0);
        int ans=0;
        for(int i=0;i<edges.size();i++)
        {
            edge &e=edges[i];
            if(d[0][e.u]+d[1][e.v]+e.w==d[0][P-1])ans+=e.w*2;
        }
        printf("%d\n",ans);
    }
    return 0;
}
