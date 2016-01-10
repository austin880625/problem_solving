#include <iostream>
#include <stdio.h>
#include <vector>
#include <assert.h>
#define MAXV 105
#define MAXN 205
#define INF 0x3f3f3f3f

using namespace std;

//int w[MAXV][MAXV];
vector<int> G[MAXV];
int P[MAXN];
int T,N1,N2,N;
int dp[MAXN][MAXV];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&N1,&N2);
        for(int i=0;i<=N1;i++)
        {
            G[i].clear();
        }
        for(int i=0;i<N2;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        //assert(0);
        scanf("%d",&N);
        for(int i=0;i<N;i++)
        {
            scanf("%d",&P[i]);
        }
        dp[0][P[0]]=0;
        for(int i=1;i<=N1;i++)
        {
            G[i].push_back(i);
            if(i!=P[0])dp[0][i]=1;
        }
        //printf("%d\n",P[0]);
        for(int i=1;i<N;i++)
        {
            //printf("%d\t",P[i]);
            for(int j=1;j<=N1;j++)
            {
                dp[i][j]=INF;
                for(int k=0;k<G[j].size();k++)
                {
                    int x=dp[i-1][G[j][k]];
                    if(j!=P[i])x++;
                    dp[i][j]=min(dp[i][j],x);
                }
                //printf("%d ",dp[i][j]);
            }
            //puts("");
        }
        int ans=INF;
        for(int i=1;i<=N1;i++)ans=min(ans,dp[N-1][i]);
        printf("%d\n",ans);
    }
}
