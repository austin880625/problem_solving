#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#define MAXN 105
#define MAXM 1005
#define INF 2147483647
#define LL long long int
using namespace std;

struct edge{
    int u,v,w,eid;
};
struct Node{
    int id;
    LL d;
    bool operator <(const Node &x)const{
        return d>x.d;
    }
};

vector<edge> edges;
vector<int> G[MAXN];

int N,M,L;
//distance and edges to parents in the tree
LL d[MAXN];
int p[MAXN];
//candidate answers for deleteing each edge
LL can[MAXM];
bool done[MAXN];

//do Dijkstra when we deleted edge numbered de
LL Dijkstra(int s,int de)
{
    priority_queue<Node> Q;
    for(int i=0;i<=N;i++)
    {
        d[i]=INF;
        done[i]=false;
        p[i]=-1;
    }
    d[s]=0;
    Q.push((Node){s,0});
    while(!Q.empty())
    {
        Node x=Q.top();Q.pop();
        if(done[x.id])continue;
        done[x.id]=true;
        int u=x.id;
        for(int i=0;i<G[u].size();i++)
        {
            edge &e=edges[G[u][i]];
            if(e.eid==de)continue;
            if(d[e.v]>d[u]+e.w)
            {
                d[e.v]=d[u]+e.w;
                Q.push((Node){e.v,d[e.v]});
                p[e.v]=e.eid;
            }
        }
    }
    LL res=0;
    for(int i=1;i<=N;i++)
    {
        res+=(d[i]==INF ? L : d[i]);
        //printf("%d %lld\n",s,res);
    }
    return res;
}

//for each vertex, do n times of Dijkstra and add the value of candidate answer
//by deleting each edge in the path tree
int tmpP[MAXN];
void calc_candidate()
{
    for(int i=1;i<=N;i++)
    {
        //calculate value c for the vertex
        //didn't delete any edge yet
        LL c=Dijkstra(i,-1);
        //printf("%lld\n",c);
        for(int j=1;j<=N;j++)tmpP[j]=p[j];
        for(int j=0;j<=M;j++)can[j]+=c;

        for(int j=1;j<=N;j++)
        {
            if(tmpP[j]!=-1)
            {
                can[tmpP[j]]+=Dijkstra(i,tmpP[j])-c;
            }
        }
    }
}

int main()
{
    while(scanf("%d",&N)==1)
    {
        edges.clear();
        for(int i=0;i<=N;i++)G[i].clear();
        scanf("%d%d",&M,&L);
        for(int i=0;i<M;i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            //eid are same in the edges
            G[u].push_back(edges.size());
            edges.push_back((edge){u,v,w,i});
            G[v].push_back(edges.size());
            edges.push_back((edge){v,u,w,i});
        }
        for(int i=0;i<=M;i++)can[i]=0;
        calc_candidate();
        LL ans=0;
        for(int i=0;i<M;i++)
        {
            ans=max(ans,can[i]);
        }
        printf("%lld %lld\n",can[M],ans);
    }
    return 0;
}
