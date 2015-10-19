#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<math.h>

#define INF 200000000
using namespace std;

struct edge
{
    int from,to;
    int w;
};

struct heapNode
{
    int d,id;
    heapNode(int xd,int xid){
        d=xd;
        id=xid;
    }
    bool operator < (const heapNode &rhs)const
    {
        return rhs.d<d;
    }
};

vector<int> G[1000];
vector<edge> edges;
int done[1000];
int d[1000];
int ans;

void Dijkstra(int source,int dest)
{
    priority_queue<heapNode> Q;
    memset(done,0,sizeof(done));
    for(int i=0;i<1000;i++)d[i]=INF;
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
                Q.push(heapNode(d[edges[i].to],edges[i].to));
            }
        }
    }
}

int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        for(int i=0;i<m;i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            edges.push_back((edge){u,v,w});
            G[u].push_back(edges.size()-1);
            edges.push_back((edge){v,u,w});
            G[u].push_back(edges.size()-1);
        }
        Dijkstra(0,n-1);
        cout<<d[n-1]<<endl;
    }
    return 0;
}
