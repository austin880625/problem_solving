#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <assert.h>
#define MAXN 1000005
#define INF 2147483647

using namespace std;

struct edge
{
    int u,v,w;
    bool operator <(const edge &x)const{
        return w>x.w;
    }
};
vector<edge> edges;
vector<int> G[MAXN];
int out[MAXN];
int maxp[MAXN];
int block[MAXN];
int N,T,L,S;
int ans;
struct Node
{
    int id,dist,w;
    bool operator<(const Node &x)const{
        return dist>x.dist;
    }
};
priority_queue<Node> Q;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        ans=0;
        while(!Q.empty())Q.pop();
        scanf("%d%d",&N,&L);
        S=0;
        edges.clear();
        for(int i=0;i<N;i++)out[i]=0,maxp[i]=block[i]=0,G[i].clear();
        for(int i=0;i<N-1;i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            G[u].push_back(edges.size());
            edges.push_back((edge){u,v,w});
            G[v].push_back(edges.size());
            edges.push_back((edge){v,u,w});
            S+=w;
            out[u]++;
            out[v]++;
        }
        //printf("%d\n",S);
        for(int i=0;i<N;i++)
        {
            if(out[i]==1)Q.push((Node){i,edges[G[i][0]].w,G[i][0]});
        }
        while(S>L)
        {
            Node x=Q.top();Q.pop();
            int t=x.id;
            out[t]--;
            block[t]=1;
            S-=edges[x.w].w;
            ans=max(ans,x.dist);
            out[edges[x.w].v]--;
            if(out[edges[x.w].v]>1)continue;
            for(int i=0;i<G[edges[x.w].v].size();i++)
            {
                edge e=edges[G[edges[x.w].v][i]];
                if(block[e.v])continue;
                //out[e.u]--;
                Q.push((Node){e.u,x.dist+e.w,G[edges[x.w].v][i]});
            }
        }

        //assert(ans!=-INF);
        printf("%d\n",ans);
    }
    return 0;
}
/*
2
3 0
0 1 30
1 2 70
8 0
2 5 6
1 2 5
5 6 6
3 1 9
6 7 15
7 0 12
4 3 12

1
8 33
2 5 6
1 2 5
5 6 6
3 1 9
6 7 15
7 0 12
4 3 12

*/
