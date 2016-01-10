#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#define ll unsigned long long int
#define MAXN 2200000

using namespace std;
const ll INF=(1LL<<63);
int N,M;

struct edge
{
    int u,v;
    ll w;
};
struct Node
{
    int id;
    ll d;
    bool operator <(const Node &rhs)const{
        return d>rhs.d;
    }
};

vector<edge> edges;
vector<int> G[MAXN];
ll d[MAXN];
int done[MAXN];

void Dijkstra(int s,int t)
{
    priority_queue<Node> Q;
    d[s]=0LL;
    Q.push((Node){s,0LL});

    while(!Q.empty())
    {
        Node x=Q.top();Q.pop();
        int u=x.id;
        if(done[u])continue;
        done[u]=1;
        for(int i=0;i<G[u].size();i++)
        {
            edge &e=edges[G[u][i]];
            int v=e.v;
            ll w=e.w;
            if(d[v] > d[u]+w)
            {
                d[v]=d[u]+w;
                Q.push((Node){v,d[v]});
            }
        }
    }
}
int kase;
int main()
{
    kase=1;
    while(scanf("%d%d",&N,&M)==2)
    {
        if(!N&&!M)break;
        edges.clear();
        for(int i=0;i<2*N*M+50;i++){G[i].clear();d[i]=INF;done[i]=0;}
        int u,v;
        ll w;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M-1;j++)
            {
                scanf("%llu",&w);
                u=3+2*i*(M-1)+2*j;
                v=3+2*(i-1)*(M-1)+2*j-1;
                if(i==0)v=1;
                if(i==N-1)u=0;
                edges.push_back((edge){u,v,w});
                G[u].push_back(edges.size()-1);
                edges.push_back((edge){v,u,w});
                G[v].push_back(edges.size()-1);
            }
        }
        for(int i=0;i<N-1;i++)
        {
            for(int j=0;j<M;j++)
            {
                scanf("%llu",&w);
                u=3+2*i*(M-1)+2*(j-1);
                v=3+2*i*(M-1)+2*j-1;
                if(j==0)u=0;
                if(j==M-1)v=1;
                edges.push_back((edge){u,v,w});
                G[u].push_back(edges.size()-1);
                edges.push_back((edge){v,u,w});
                G[v].push_back(edges.size()-1);
            }
        }
        for(int i=0;i<N-1;i++)
        {
            for(int j=0;j<M-1;j++)
            {
                scanf("%llu",&w);
                u=3+2*i*(M-1)+2*j-1;
                v=u+1;
                edges.push_back((edge){u,v,w});
                G[u].push_back(edges.size()-1);
                edges.push_back((edge){v,u,w});
                G[v].push_back(edges.size()-1);
            }
        }
        Dijkstra(0,1);
        printf("Case %d: Minimum = %llu\n",kase++,d[1]);
    }
    return 0;
}
