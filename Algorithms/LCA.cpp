#include<iostream>
#include<stdio.h>
#include<vector>
#define MAXN 1000000
using namespace std;

struct edge
{
    int u,v,w;
};
vector<edge> edges;
vector<int> G[MAXN];
int p[MAXN];
int depth[MAXN];

int anc[MAXN][25]; //lg1048576 is 20
int maxcost[MAXN][25];
int N,Q;

void getParent(int now,int fa,int dep)
{
    p[now]=fa;
    depth[now]=dep;
    for(int i=0;i<G[now].size();i++)
    {
        edge &e=edges[G[now][i]];
        maxcost[e.v][0]=e.w;
        getParent(e.v,now,dep+1);
    }
}

void preProcess()
{
    for(int i=0;i<N;i++)
    {
        anc[i][0]=p[i];
        for(int j=1;(1<<j)<N;j++)anc[i][j]=-1;
    }
    for(int j=1;(1<<j)<N;j++)
    {
        for(int i=0;i<N;i++)
        {
            if(anc[i][j-1]!=-1)
            {
                anc[i][j]=anc[anc[i][j-1]][j-1];    //doubling
                maxcost[i][j]=max(maxcost[i][j],maxcost[anc[i][j-1]][j-1]);
            }
        }
    }
}

int query(int x,int y)
{
    int res;
    if(depth[x]<depth[y])swap(x,y);
    int Log=0;
    for(Log=0;(1<<Log)<=depth[x];Log++){}Log--;   //get log(depth[p])

    //pull up p such that depth[p]=depth[q]
    for(int i=Log; i>=0; i--)
    {
        if(depth[x]-(1<<i)>=depth[y])x=anc[x][i];
    }
    if(x==y)return x;
    for(int i=Log;i>=0;i--)
    {
        if(anc[x][i]!=-1&&anc[y][i]!=anc[x][i]){x=anc[x][i];y=anc[y][i];}
    }
    return p[x];
}

int main()
{
    while(scanf("%d %d",&N,&Q)==2)
    {
        int u,v,w;
        for(int i=0;i<N-1;i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            edges.push_back((edge){u,v,w});
            G[u].push_back(edges.size()-1);
        }
        getParent(0,-1,0);
        preProcess();
        for(int i=0;i<Q;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            printf("%d\n",query(x,y));
            //printf("%d\n",querymax(p,q));
        }
    }
    return 0;
}
