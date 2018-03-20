#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include <string.h>
#include<math.h>

#define INF 1000000000000000000
using namespace std;

struct edge
{
    int from,to;
    int w;
};

struct heapNode
{
    long long int d;int id;
    heapNode(long long int xd,int xid){
        d=xd;
        id=xid;
    }
    bool operator < (const heapNode &rhs)const
    {
        return rhs.d<d;
    }
};

vector<int> G[100005];
vector<edge> edges;
int done[100005];
int p[100005];
long long int d[100005];
int ans;

void Dijkstra(int source,int dest)
{
    priority_queue<heapNode> Q;
    memset(done,0,sizeof(done));
    for(int i=0;i<100005;i++)d[i]=INF,p[i]=-1;
    d[source]=0;
    Q.push(heapNode(0,source));

    while(!Q.empty())
    {
        heapNode now=Q.top(); Q.pop();
        int u=now.id;
        if(done[u])continue;
        done[u]=1;
        for(auto i:G[u])
        {
            if(d[edges[i].to]>d[u]+edges[i].w)
            {
                d[edges[i].to]=d[u]+edges[i].w;
                p[edges[i].to]=u;
                Q.push(heapNode(d[edges[i].to],edges[i].to));
            }
        }
    }
}
vector<int> path;
int main()
{
    int n,m;
    ios::sync_with_stdio(0);cin.tie(0);
    while(cin>>n>>m)
    {
        path.clear();
        for(int i=0;i<n;i++)G[i].clear();
        for(int i=0;i<m;i++)
        {
            int u,v;long long int w;
            cin>>u>>v>>w;u--,v--;
            edges.push_back((edge){u,v,w});
            G[u].push_back(edges.size()-1);
            edges.push_back((edge){v,u,w});
            G[v].push_back(edges.size()-1);
        }
        Dijkstra(0,n-1);
        if(d[n-1]!=INF)for(int i=n-1;i!=-1;i=p[i])path.push_back(i);
        if(d[n-1]==INF)cout<<"-1"<<endl;
        else for(int i=path.size()-1;i>=0;i--){cout<<path[i]+1;if(i)cout<<" ";}
        cout<<endl;
    }
    return 0;
}
