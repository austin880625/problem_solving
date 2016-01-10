#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
#include <assert.h>
#define MAXC 105
#define INF 2147483646
using namespace std;
int C,S,Q;

struct edge
{
    int from,to,w;
    bool operator <(const edge &rhs)const{
        return w<rhs.w;
    }
};
vector<edge> edges;
vector<int> G[MAXC];
vector<edge> MST;
vector<int> Gt[MAXC];
int p[MAXC];
int vis[MAXC];
int maxcost[MAXC][MAXC];
void addEdge(int u,int v,int w)
{
    edges.push_back((edge){u,v,w});
    G[u].push_back(edges.size()-1);
    edges.push_back((edge){v,u,w});
    G[v].push_back(edges.size()-1);
}
int find(int x){return x==p[x] ? x : p[x]=find(p[x]);}
void Kruskal()
{
    sort(edges.begin(),edges.end());
    for(int i=0;i<edges.size();i++)
    {
        edge &e=edges[i];
        int from=e.from,to=e.to;
        int x=find(from),y=find(to);
        if(x!=y)
        {
            MST.push_back((edge){from,to,e.w});
            Gt[from].push_back(MST.size()-1);
            MST.push_back((edge){to,from,e.w});
            Gt[to].push_back(MST.size()-1);
            maxcost[from][to]=maxcost[to][from]=e.w;
            p[x]=y;
        }
        //assert(find(from)==find(to));
    }
}

void dfs(int now,int fa)
{
    vis[now]=1;
    if(fa!=-1)
    for(int i=1;i<=C;i++)
    {
        if(vis[i]&&i!=now)
        {
            maxcost[i][now]=maxcost[now][i]=max(maxcost[now][fa],maxcost[fa][i]);
        }
    }
    for(int i=0;i<Gt[now].size();i++)
    {
        edge &e=MST[Gt[now][i]];
        assert(e.from==now);
        if(e.to!=fa&&!vis[e.to])
            dfs(e.to,now);
    }
}

int main()
{
    int kase=0;
    while(scanf("%d%d%d",&C,&S,&Q)==3)
    {
        if(!C)break;
        for(int i=0;i<=C;i++){
            for(int j=0;j<=C;j++)
                maxcost[i][j]=-INF;
            maxcost[i][i]=0;
        }
        edges.clear();
        MST.clear();
        for(int i=0;i<MAXC;i++){G[i].clear();Gt[i].clear();p[i]=i;vis[i]=0;}
        for(int i=0;i<S;i++)
        {
            int c1,c2,d;
            scanf("%d%d%d",&c1,&c2,&d);
            addEdge(c1,c2,d);
        }
        Kruskal();
        //assert(MST.size()%2==0);
        //if(MST.size()<2*(C-1))cout<<C-1<<" "<<MST.size()<<endl;
        for(int i=1;i<=C;i++)if(!vis[i])dfs(i,-1);
        if(kase)puts("");
        printf("Case #%d\n",++kase);
        for(int i=0;i<Q;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            if(find(u)==find(v))printf("%d\n",maxcost[u][v]);
            else printf("no path\n");
        }
    }
    return 0;
}
