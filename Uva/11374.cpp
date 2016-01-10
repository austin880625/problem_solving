#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#define MAXN 505
#define INF 0x3f3f3f3f
using namespace std;

int N,S,E;
int M,K;
struct edge
{
    int u,v,w;
};
vector<edge> edges;
vector<edge> commercial;
vector<int> G[MAXN];
int done[2][MAXN];
int d[2][MAXN];
int p[2][MAXN];
struct Node{
    int id,d;
    bool operator <(const Node &rhs)const{return d>rhs.d;}
};
priority_queue<Node> Q;
void addedge(int u,int v,int w)
{
    G[u].push_back(edges.size());
    edges.push_back((edge){u,v,w});
    G[v].push_back(edges.size());
    edges.push_back((edge){v,u,w});
}
void dijkstra(int s,int r)
{
    d[r][s]=0;
    Q.push((Node){s,0});
    while(!Q.empty())
    {
        Node x=Q.top();Q.pop();
        int u=x.id;
        if(done[r][u])continue;
        done[r][u]=0;
        for(int i=0;i<G[u].size();i++)
        {
            edge &e=edges[G[u][i]];
            int v=e.v;
            if(d[r][v]>d[r][u]+e.w)
            {
                d[r][v]=d[r][u]+e.w;
                p[r][v]=u;
                Q.push((Node){e.v,d[r][v]});
            }
        }
    }
}

int main()
{
    int kase=0;
    while(scanf("%d%d%d",&N,&S,&E)==3)
    {
        if(kase++)puts("");
        scanf("%d",&M);
        edges.clear(),commercial.clear();
        for(int i=0;i<=N;i++)G[i].clear(),done[0][i]=done[1][i]=0,d[0][i]=d[1][i]=INF,p[0][i]=p[1][i]=0;
        for(int i=0;i<M;i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            addedge(u,v,w);
        }
        scanf("%d",&K);
        for(int i=0;i<K;i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            commercial.push_back((edge){u,v,w});
            commercial.push_back((edge){v,u,w});
        }
        dijkstra(S,0),dijkstra(E,1);
        int ans=d[0][E];
        int cu=-1,cv=-1,ci=-1;
        for(int i=0;i<commercial.size();i++)
        {
            edge &e=commercial[i];
            if(d[0][e.u]+d[1][e.v]+e.w<ans)ans=d[0][e.u]+d[1][e.v]+e.w,cu=e.u,cv=e.v,ci=i;
        }
        int st=S;
        addedge(cu,cv,commercial[ci].w);
        for(int i=0;i<=N;i++)done[1][i]=0,d[1][i]=INF;
        dijkstra(E,1);
        //cout<<cu<<cv<<endl;
        //printf("%d",st);
        while(st!=E)
        {
            printf("%d ",st);
            st=p[1][st];
        }
        printf("%d\n",E);
        if(cu==-1)printf("Ticket Not Used\n");
        else printf("%d\n",cu);
        printf("%d\n",ans);
    }
}
