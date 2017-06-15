#include <stdio.h>
#include <iostream>
#include <algorithm>
#define LL long long int
#define MAXN 305
#define INF 21474836470000
LL dp[MAXN][MAXN];
LL C[MAXN][MAXN];
int T,M,N;

using namespace std;

int main()
{
    scanf("%d",&T);
    for(int kase=1;kase<=T;kase++)
    {
        int f=0;
        if(dp[N][N]==2)f=1;
        scanf("%d%d",&N,&M);
        if(f)cout<<N<<" "<<M;
        for(int j=0;j<=M;j++)dp[0][j]=INF;
        for(int i=1;i<=N;i++)
        {
            dp[i][0]=INF;
            for(int j=1;j<=M;j++)
            {
                scanf("%lld",&C[i][j]);
                // dp[i][j]=INF;
            }
            sort(C[i]+1,C[i]+1+M);C[i][0]=0;
            for(int j=1;j<=M;j++)
            {
                C[i][j]=C[i][j-1]+C[i][j]+2*j-1;
                // cout<<C[i][j]<<endl;
            }
        }
        dp[0][0]=0;
        for(int i=1;i<=N;i++)
        {
            dp[i][0]=0;
            for(int j=i;j<=N;j++)
            {
                if(j>M*i){dp[i][j]=INF;continue;}
                dp[i][j]=INF;
                for(int k=i-1;k<=j;k++)
                {
                    // cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j]<<" "<<dp[i-1][k]+C[i][j-k]<<endl;
                    if(j-k<=M)dp[i][j]=min(dp[i][j],dp[i-1][k]+C[i][j-k]);
                }
            }
        }
        printf("Case #%d: %lld\n",kase,dp[N][N]);
    }
    return 0;
}
