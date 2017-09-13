#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

#define MAXN 100005

using namespace std;

struct edge{
    int to,c;
};

vector<edge> G[MAXN];
int vis[MAXN];
int ans,N;

int dfs(int now)
{
    vis[now]=1;
    int m1=0,m2=0;
    for(int i=0;i<G[now].size();i++)
    {
        int to=G[now][i].to;
        if(vis[to])continue;
        int t=G[now][i].c+dfs(to);
        if(t>m1)m2=m1,m1=t;
        else if(t>m2)m2=t;
    }
    ans=max(m1+m2,ans);
    return m1;
}

int main()
{
    while(scanf("%d",&N)==1&&N!=0){
        for(int i=0;i<=N;i++)G[i].clear(),vis[i]=0;
        for(int i=0,u,v,c;i<N-1;i++)
        {
            scanf("%d%d%d",&u,&v,&c);
            G[u].push_back((edge){v,c});
            G[v].push_back((edge){u,c});
        }

        ans=0;
        dfs(1);
        printf("%d\n",ans);
    }
    return 0;
}
