#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define maxn 1050
using namespace std;
int n,ind[maxn],dp[maxn],day[maxn],res;
int vis[maxn];
vector<int> v[maxn];
void dfs(int x)
{
    vis[x]=1;
    for(int i=0;i<v[x].size();i++)
    {
        int&u=v[x][i];
        ind[u]--;
        dp[u]=max(dp[u],day[u]+dp[x]);
        if(!ind[u]&&!vis[u])dfs(u);
    }
}
int main()
{
    int t;
    while(scanf("%d",&t)==1)
    {
        while(t--)
        {
            memset(ind,0,sizeof(ind));
            memset(dp,0,sizeof(dp));
            memset(vis,0,sizeof(vis));
            scanf("%d",&n);
            for(int i=1;i<=n;i++)
            {
                v[i].clear();
                int m,a;
                scanf("%d %d",&day[i],&m);

                for(int j=0;j<m;j++)
                {
                    scanf("%d",&a);
                    v[i].push_back(a);
                    ind[a]++;
                }
            }
            res=0;
            for(int i=1;i<=n;i++)
            {
                if(ind[i]||vis[i])continue;
                dp[i]=day[i];
                dfs(i);
            }
            for(int i=1;i<=n;i++)
                res=max(res,dp[i]);
            printf("%d\n",res);
        }
    }
    return 0;
}
