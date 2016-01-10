#include <iostream>
#include <stdio.h>
#include <vector>
#define MAXN 1005
using namespace std;
int T,N,M;
int dp[MAXN][2];
int vis[MAXN];
vector<int> G[MAXN];

int DFS(int now,int fa,int lamp)
{
    if(dp[now][lamp]!=-1)return dp[now][lamp];
    vis[now]=1;
    int res=5000;
    for(int i=0;i<G[now].size();i++)
    {
        int v=G[now][i];
        if(v==fa)continue;
        res+=DFS(v,now,1);
    }
    if(fa!=-1&&lamp==0)res++;

    if(lamp||fa==-1)
    {
        int sum=0;
        for(int i=0;i<G[now].size();i++)
        {
            int v=G[now][i];
            if(v==fa)continue;
            sum+=DFS(v,now,0);
        }
        if(fa!=-1)sum++;
        res=min(res,sum);
    }
    return dp[now][lamp]=res;
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&N,&M);
        for(int i=0;i<N;i++){G[i].clear();vis[i]=0;dp[i][0]=dp[i][1]=-1;}
        for(int i=0;i<M;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            G[a].push_back(b);
            G[b].push_back(a);
        }
        int ans=0;
        for(int i=0;i<N;i++)if(!vis[i])ans+=DFS(i,-1,0);
        printf("%d %d %d\n",ans/5000,M-ans%5000,ans%5000);
    }
    return 0;
}
