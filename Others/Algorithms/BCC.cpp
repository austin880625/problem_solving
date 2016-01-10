#include<iostream>
#include <stdio.h>
#include <stack>
#include <queue>
#include <vector>
#define MAXN 1005
using namespace std;
struct edge
{
    int u,v;
    edge(int _u,int _v){u=_u;v=_v;}
};
vector<edge> edges;
vector<int> G[MAXN];
int N,M;
void addedge(int u,int v)
{
    G[u].push_back(edges.size());
    edges.push_back(edge(u,v));
    G[v].push_back(edges.size());
    edges.push_back(edge(v,u));
}

bool hate[MAXN][MAXN];
stack<edge> S;
int pre[MAXN],low[MAXN],bccno[MAXN];
bool iscut[MAXN];
int dfs_clock,bcc_cnt;
bool oddRing[MAXN];
vector<int> bcc[MAXN];

int dfs(int now,int fa)
{
    low[now]=pre[now]=++dfs_clock;
    int ch=0;
    iscut[now]=false;
    for(int i=0;i<G[now].size();i++)
    {
        edge e=edges[G[now][i]];
        int v=e.v;
        if(!pre[v])
        {
            ch++;
            S.push(e);
            low[now]=min(low[now],dfs(v,now));
            if(low[v]>=pre[now])
            {
                iscut[now]=true;
                bcc_cnt++;
                bcc[bcc_cnt].clear();
                while(1)
                {
                    edge x=S.top();S.pop();
                    if(bccno[x.u]!=bcc_cnt)bcc[bcc_cnt].push_back(x.u),bccno[x.u]=bcc_cnt;
                    if(bccno[x.v]!=bcc_cnt)bcc[bcc_cnt].push_back(x.v),bccno[x.v]=bcc_cnt;
                    if(x.u==now&&x.v==v)break;
                }
            }
        }
        else if(pre[v]<pre[now]&&v!=fa)
        {
            S.push(e);
            low[now]=min(low[now],pre[v]);
        }
    }
    if(fa<0&&ch==1)iscut[now]=false;
    return low[now];
}

int color[MAXN];
bool bipartite(int s,int b)
{
    queue<int> Q;
    Q.push(s);
    color[s]=0;
    while(!Q.empty())
    {
        int x=Q.front();Q.pop();
        //cout<<"now is at "<<x<<" filling "<<color[x]<<endl;;
        for(int i=0;i<G[x].size();i++)
        {
            edge &e=edges[G[x][i]];
            int v=e.v;
            //cout<<v<<endl;
            if(bccno[v]!=b)continue;
            if(color[v]!=-1)
            {
                //cout<<v<<" visited "<<color[v]<<"\n";
                if(color[x]==color[v])return false;
            }
            else
            {
                //cout<<v<<" not visited\n";
                color[v]=color[x]==1 ? 0:1;
                Q.push(v);
            }
        }
        //puts("");
    }
    return true;
}

int main()
{
    while(scanf("%d%d",&N,&M)==2&&(N||M))
    {
        edges.clear();
        for(int i=0;i<N;i++)
        {
            bccno[i]=pre[i]=0;
            oddRing[i]=false;
            G[i].clear();
            bcc[i].clear();
            for(int j=0;j<N;j++)hate[i][j]=false;
        }
        for(int i=0;i<M;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            u--,v--;
            hate[u][v]=hate[v][u]=true;
        }
        for(int i=0;i<N;i++)
        {
            for(int j=i+1;j<N;j++)
            {
                if(!hate[i][j])
                {
                    //printf("%d   %d\n",i+1,j+1);
                    addedge(i,j);
                }
            }
        }
        int ans=0;
        dfs_clock=bcc_cnt=0;
        for(int i=0;i<N;i++)if(!pre[i])dfs(i,-1);
        for(int i=1;i<=bcc_cnt;i++)
        {
            for(int j=0;j<N;j++)color[j]=-1;
            //cout<<i<<":"<<endl;
            for(int j=0;j<bcc[i].size();j++)bccno[bcc[i][j]]=i; // deal with cut vertex
            //puts("");
            int s=bcc[i][0];
            if(!bipartite(s,i))for(int j=0;j<bcc[i].size();j++)oddRing[bcc[i][j]]=true;
        }
        for(int i=0;i<N;i++)if(!oddRing[i])ans++;
        printf("%d\n",ans);
    }
    return 0;
}
