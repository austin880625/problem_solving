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
    int d;
    heapNode(){
        d=INF;
    }
    bool operator < (const heapNode &rhs)const
    {
        return rhs.d<d;
    }
};

vector<int> G[1000];
heapNode V[1000];
vector<edge> edges;
int done[1000];
int ans;

void Dijkstra(int source,int dest)
{
    priority_queue<heapNode> Q;
    memset(done,0,sizeof(done));
    V[source].d=0;
    done[source]=1;
    Q.push(V[source]);
    
    while(!Q.empty())
    {
        heapNode now=Q.top(); Q.pop();
        if()
    }
}

int main()
{

    return 0;
}
