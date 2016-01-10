#include <iostream>
#include <stdio.h>
#include <string.h>
#define MAXN 21
#define INF 0x3f3f3f3f
using namespace std;
int N,M,K;
int sum[MAXN][MAXN];
int grid[MAXN][MAXN];
int dp[MAXN][MAXN][MAXN][MAXN];
int cherrycnt(int l,int r,int t,int d)
{
    return sum[d][r]-sum[d][l-1]-sum[t-1][r]+sum[t-1][l-1];
}
int DP(int l,int r,int t,int d)
{
    if(dp[l][r][t][d]!=-1)return dp[l][r][t][d];
    if(cherrycnt(l,r,t,d)==1)return 0;
    int res=INF;
    for(int i=l;i<r;i++)
    {
        if(cherrycnt(l,i,t,d)&&cherrycnt(i+1,r,t,d))res=min(res,d-t+1+DP(l,i,t,d)+DP(i+1,r,t,d));
    }
    for(int i=t;i<d;i++)
    {
        if(cherrycnt(l,r,t,i)&&cherrycnt(l,r,i+1,d))res=min(res,r-l+1+DP(l,r,t,i)+DP(l,r,i+1,d));
    }
    return dp[l][r][t][d]=res;
}

int main()
{
    int kase=0;
    while(scanf("%d%d%d",&N,&M,&K)==3)
    {
        int r,c;
        for(int i=0;i<=N;i++)for(int j=0;j<=M;j++)grid[i][j]=sum[i][j]=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<K;i++)
        {
            scanf("%d%d",&r,&c);
            grid[r][c]=1;
        }

        for(int i=0;i<=N;i++)
        {
            for(int j=0;j<=M;j++)
            {
                sum[i][j]=grid[i][j];
                if(i)sum[i][j]+=sum[i-1][j];
                if(j)sum[i][j]+=sum[i][j-1];
                if(i&&j)sum[i][j]-=sum[i-1][j-1];
            }
        }
        //cout<<sum[N][M]<<endl;
        int ans=DP(1,M,1,N);
        printf("Case %d: %d\n",++kase,ans);
    }
    return 0;
}
