#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#define MAXN 20005

using namespace std;

vector<int> G[MAXN];
int sz[MAXN];
int path[MAXN];
int P;
queue<int> Q;
int N;

void dfs(int now,int pa)
{
    sz[now]=1;
    int X=0;
    for(int i=0;i<G[now].size();i++)
    {
        int v=G[now][i];
        if(v==pa)continue;
        dfs(v,now);
        sz[now]+=sz[v];
        X+=(sz[v]*(sz[v]+1))/2;
    }
    X+=((N-sz[now]+1)*(N-sz[now]))/2;
    path[now]=P-X;
}

int main()
{
    while(scanf("%d",&N)==1)
    {
        for(int i=0;i<N;i++)G[i].clear(),sz[i]=0;
        P=N*(N-1)/2;
        for(int i=0;i<N-1;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v),u--,v--;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dfs(0,-1);
        int ans=0,ansi=N-1;
        for(int i=N-1;i>=0;i--)if(ans<=path[i])ans=path[i],ansi=i;
        printf("%d %d\n",ansi+1,ans);
    }
}
