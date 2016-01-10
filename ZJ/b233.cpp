#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>
#define MAXN 30000

using namespace std;

int N,M,K;
struct edge
{
    int u,v;
    edge(int _u,int _v){u=_u,v=_v;}
};
vector<edge> edges;
vector<int> G[MAXN];
bool iscut[MAXN];
int sz[MAXN],pre[MAXN],low[MAXN];
int dfs_clock,ans,ansp;

int dfs(int now,int fa)
{
    pre[now]=low[now]=++dfs_clock;
    sz[now]=1;
    iscut[now]=false;
    int ch=0,s=0;
    for(int i=0;i<G[now].size();i++)
    {
        edge &e=edges[G[now][i]];
        int v=e.v;
        if(!pre[v])
        {
            //if(now==5)cout<<v<<" "<<pre[v]<<endl;
            ch++;
            low[now]=min(dfs(v,now),low[now]);
            if(fa==-1&&ch>1)
            {
                iscut[now]=true;
            }
            else if(low[v]>=pre[now])
            {
                s+=sz[v];
                iscut[now]=true;
            }
            sz[now]+=sz[v];
        }
        else if(v!=fa)
        {
            low[now]=min(pre[v],low[now]);
        }
    }
    if(now!=K&&iscut[now]&&(ans<s||ans==s&&ansp>now)){ans=s;ansp=now;}
    return low[now];
}

int main()
{
    int t=0;
    while(scanf("%d",&N)==1)
    {
        scanf("%d",&M);
        dfs_clock=0;
        for(int i=0;i<N;i++)
        {
            pre[i]=0;
            iscut[i]=0;
            G[i].clear();
        }
        for(int i=0;i<M;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            u--,v--;
            G[u].push_back(edges.size());
            edges.push_back(edge(u,v));
            G[v].push_back(edges.size());
            edges.push_back(edge(v,u));
        }
        scanf("%d",&K);K--;
        ans=0;ansp=-1;
        dfs(K,-1);
        if(t++)puts("");
        if(ansp!=-1)
            printf("%d %d\n",ansp+1,dfs_clock-ans);
        else
            printf("0\n");
    }
    return 0;
}
