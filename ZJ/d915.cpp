#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
#define MAXN 1505
#define MAXNode 25
#define INF 0x3f3f3f3f
using namespace std;

struct edge
{
    int u,v,w;
};
struct Node
{
    int d,id;
    bool operator <(const Node &rhs)const
    {
        return d>rhs.d;
    }
};
vector<int> G[MAXN];
//vector<int> Gt[MAXNode];
int Nodes[MAXNode];
vector<edge> edges;

int w[MAXNode][MAXNode];
int d[MAXN];
bool done[MAXN];

int N,M,S,T;

void addedge(int u,int v,int w)
{
    G[u].push_back(edges.size());
    edges.push_back((edge){u,v,w});
    G[v].push_back(edges.size());
    edges.push_back((edge){v,u,w});
}
void Dijkstra(int src)
{
    priority_queue<Node> Q;
    for(int i=1;i<=N;i++)done[i]=false,d[i]=INF;
    d[src]=0;
    Q.push((Node){0,src});
    while(!Q.empty())
    {
        Node x=Q.top();Q.pop();
        int u=x.id;
        //cout<<"now u is"<<u<<endl;
        if(done[u])continue;
        done[u]=true;
        for(int i=0;i<G[u].size();i++)
        {
            edge &e=edges[G[u][i]];
            if((u==S&&e.v==T||u==T&&e.v==S)&&e.w==0)continue;
            if(d[e.v]>d[u]+e.w)
            {
                d[e.v]=d[u]+e.w;
                //cout<<"\t"<<e.v<<" "<<d[e.v]<<"YE"<<endl;
                Q.push((Node){d[e.v],e.v});
            }
        }
    }
}

int dp[1<<MAXNode];
int C;
int DP(int S)
{
    int i,j;
    if(dp[S]!=-1)return dp[S];
    int res=INF;
    if(S==0)return 0;
    for(i=0;i<C;i++)if(S&(1<<i))break;

    for(j=0;j<C;j++)
    {
        if(j!=i&&((S>>j)&1))
        {
            int mask=(1<<i)|(1<<j);
            //cout<<mask<<" "<<j<<" "<<w[i][j]<<endl;
            res=min(res,DP(S^mask)+w[i][j]);
        }
    }
    return dp[S]=res;
}

int main()
{
    while(scanf("%d%d%d",&N,&M,&S)==3)
    {
        T=S;
        memset(dp,-1,sizeof(dp));
        int u,v,wi;
        for(int i=0;i<=N;i++)G[i].clear();
        edges.clear();
        long long int ans=0;
        for(int i=0;i<M;i++)
        {
            scanf("%d%d%d",&u,&v,&wi);
            addedge(u,v,wi);
            ans+=wi;
        }
        //addedge(S,T,0);
        C=0;
        for(int i=1;i<=N;i++)
        {
            //cout<<G[i].size()/2<<endl;
            if(G[i].size()&1)
            {
                Nodes[C++]=i;
            }
        }
        //printf("c is %d\n",C);
        for(int i=0;i<MAXNode;i++)for(int j=0;j<MAXNode;j++)w[i][j]=INF;
        for(int i=0;i<C;i++)
        {
            //cout<<Nodes[i]<<endl;
            Dijkstra(Nodes[i]);
            for(int j=i;j<C;j++){w[i][j]=w[j][i]=d[Nodes[j]];}
        }
        //cout<<ans<<endl;
        ans+=DP((1<<C)-1);
        printf("%lld\n",ans);
    }
    return 0;
}
