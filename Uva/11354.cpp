#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#define MAXN 50005
#define INF 2147483646
using namespace std;

struct edge
{
    int u,v,w;
    bool operator < ( const edge &rhs )const{
        return w<rhs.w;
    }
};
vector<edge> edges;
vector<int> G[MAXN],Gt[MAXN];
vector<edge> MST;
int N,M,Q;

int p[MAXN];
int find(int x){return x==p[x] ? x : p[x]=find(p[x]);}

void kruskal()
{
    sort(edges.begin(),edges.end());
    for(int i=0;i<edges.size();i++)
    {
        edge &e=edges[i];
        int u=e.u,v=e.v,x=find(u),y=find(v);
        if(x!=y)
        {
            p[x]=y;
            MST.push_back((edge){u,v,e.w});
            Gt[u].push_back(MST.size()-1);
            MST.push_back((edge){v,u,e.w});
            Gt[v].push_back(MST.size()-1);
        }
    }
}

int pa[MAXN];
int dep[MAXN];
int vis[MAXN];
int anc[MAXN][17];
int maxcost[MAXN][17];

void getParent(int now,int fa,int depth)
{
    pa[now]=fa;
    dep[now]=depth;
    vis[now]=1;
    for(int i=0;i<Gt[now].size();i++)
    {
        edge &e=MST[Gt[now][i]];
        if(!vis[e.v])
        {
            maxcost[e.v][0]=e.w;
            getParent(e.v,now,depth+1);
        }
    }
}

void pre_process()
{
    for(int i=0;i<N;i++)
    {
        anc[i][0]=pa[i];
        for(int j=1;(1<<j)<N;j++){maxcost[i][j]=-INF;anc[i][j]=-1;}
    }

    for(int j=1;(1<<j)<N;j++)
    {
        for(int i=0;i<N;i++)
        {
            anc[i][j]=anc[anc[i][j-1]][j-1];
            maxcost[i][j]=max(maxcost[i][j-1],maxcost[anc[i][j-1]][j-1]);
        }
    }
}

int query(int s,int t)
{
    if(dep[s]<dep[t])swap(s,t);
    int res=-INF;
    int lg;
    for(lg=0;(1<<lg)<=dep[s];lg++){}lg--;

    for(int i=lg;i>=0;i--)
    {
        if(dep[s]-(1<<i)>=dep[t]){res=max(res,maxcost[s][i]);s=anc[s][i];}
    }
    if(s==t)return res;
    for(int i=lg;i>=0;i--)
    {
        if(anc[s][i]!=-1&&anc[s][i]!=anc[t][i])
        {
            res=max(res,maxcost[s][i]);s=anc[s][i];
            res=max(res,maxcost[t][i]);t=anc[t][i];
        }
    }
    res=max(res,maxcost[s][0]);
    res=max(res,maxcost[t][0]);
    return res;
}

int main()
{
    int kase=0;
    while(scanf("%d%d",&N,&M)==2)
    {
        if(kase++)puts("");
        int u,v,w;
        MST.clear();
        edges.clear();
        for(int i=0;i<N;i++){G[i].clear();Gt[i].clear();vis[i]=0;p[i]=i;}
        for(int i=0;i<M;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            edges.push_back((edge){u-1,v-1,w});
            G[u].push_back(edges.size()-1);
            edges.push_back((edge){v-1,u-1,w});
            G[v].push_back(edges.size()-1);
        }
        kruskal();
        //cout<<MST[0].w<<endl;
        getParent(0,-1,0);
        pre_process();
        int s,t;
        scanf("%d",&Q);
        for(int i=0;i<Q;i++)
        {
            scanf("%d%d",&s,&t);
            printf("%d\n",query(s-1,t-1));
        }
    }
    return 0;
}
