#include<iostream>
#include<stdio.h>
#include<string.h>
#define MAXN 55
#define MAXT 8700
#define INF 2147483646
using namespace std;
int n,t;
int T;
int w[MAXN];
int dp[MAXN][MAXT];
int maxs,maxt;
int main()
{
    int kase=0;
    scanf("%d",&T);
    while(T--)
    {
        maxs=0;
        scanf("%d%d",&n,&t);
        for(int i=0;i<n;i++){scanf("%d",&w[i]);}
        memset(dp,-1,sizeof(dp));
        dp[0][0]=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<t;j++)
            {
                //if(j==30)cout<<i<<dp[i][j]<<endl;
                if(dp[i][j]!=-1)
                {
                    dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
                    if(j+w[i]<t)dp[i+1][j+w[i]]=max(dp[i][j]+1,dp[i+1][j+w[i]]);
                }
            }
        }
        for(int j=0;j<t;j++)if(dp[n][j]>=maxs){maxs=dp[n][j];maxt=j;}
        printf("Case %d: %d %d\n",++kase,maxs+1,maxt+678);
    }
    return 0;
}
