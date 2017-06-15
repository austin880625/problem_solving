#include <stdio.h>
#include <iostream>
#include <algorithm>
#define MAXN 105
#define INF 2147483647

using namespace std;

int w[MAXN][MAXN];
int dp[5005][5005][3][2];
int T,N,M,K;
int S[5005],D[5005];

int main()
{
    scanf("%d",&T);
    for(int kase=1;kase<=T;kase++)
    {
        scanf("%d%d%d",&N,&M,&K);
        for(int i=0;i<=N;i++){for(int j=0;j<=N;j++)w[i][j]=INF;w[i][i]=0;}
        for(int i=0;i<=K;i++)for(int j=0;j<=K;j++)for(int k=0;k<3;k++)dp[i][j][k][0]=dp[i][j][k][1]=INF;
        for(int i=0;i<M;i++)
        {
            int u,v,g;
            scanf("%d%d%d",&u,&v,&g);
            w[u][v]=w[v][u]=min(w[u][v],g);
        }
        for(int i=1;i<=K;i++)
        {
            scanf("%d%d",S+i,D+i);
        }
        for(int k=1;k<=N;k++)
        {
            for(int i=1;i<=N;i++)
            {
                for(int j=1;j<=N;j++)
                {
                    if(w[i][k]==INF||w[k][j]==INF)continue;
                    if(w[i][j]>w[i][k]+w[k][j])
                    {
                        w[i][j]=w[j][i]=w[i][k]+w[k][j];
                    }
                }
            }
        }
        S[0]=1;D[0]=0;
        dp[0][0][0][0]=dp[0][0][0][1]=0;
        for(int i=1;i<=K;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(i>j)
                {
                    for(int k=1;k<=2;k++){
                        if(w[S[i-1]][S[i]]!=INF&&dp[i-1][j][k-1][0]!=INF)dp[i][j][k][0]=min(dp[i][j][k][0],dp[i-1][j][k-1][0]+w[S[i-1]][S[i]]);
                        if(w[D[j]][S[i]]!=INF&&dp[i-1][j][k-1][1]!=INF)dp[i][j][k][0]=min(dp[i][j][k][0],dp[i-1][j][k-1][1]+w[D[j]][S[i]]);
                    }
                    //cout<<dp[i][j][0]<<" ";
                }
                if(j)
                {
                    for(int k=1;k>=0;k--)
                    {
                    if(w[S[i]][D[j]]!=INF&&dp[i][j-1][k+1][0]!=INF)dp[i][j][k][1]=min(dp[i][j][k][1],dp[i][j-1][k+1][0]+w[S[i]][D[j]]);
                    if(w[D[j-1]][D[j]]!=INF&&dp[i][j-1][k+1][1]!=INF)dp[i][j][k][1]=min(dp[i][j][k][1],dp[i][j-1][k+1][1]+w[D[j-1]][D[j]]);
                    }

                }
                //cout<<i<<" "<<j<<" "<<dp[i][j][0]<<" "<<dp[i][j][1]<<endl;
            }
        }
        printf("Case #%d: %d\n",kase,dp[K][K][0][1]==INF ? -1 : dp[K][K][0][1]);
    }
    return 0;
}
