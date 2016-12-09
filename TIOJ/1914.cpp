#include <stdio.h>
#include <iostream>
#define MAXN 205
#define INF 2147483647
using namespace std;

int N,M;
int c[MAXN];
int dp[MAXN][MAXN];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&N,&M);
        for(int i=0;i<N;i++)
        {
            scanf("%d",c+i);
        }
        for(int i=0;i<N;i++)
        {
            dp[i][i]=1;
        }
        for(int gap=1;gap<N;gap++)
        {
            for(int l=0;l<N-1;l++)
            {
                int r=l+gap;
                if(r>=N)break;
                dp[l][r]=INF;
                for(int k=l;k<r;k++)
                {
                    dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]);
                }
                if(c[l]==c[r])dp[l][r]=min(dp[l][r],min(dp[l+1][r],dp[l][r-1]));
            }
        }
        printf("%d\n",dp[0][N-1]);
    }
    return 0;
}
