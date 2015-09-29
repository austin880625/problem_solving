#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;

int dp[120][12005];
int dp2[120][12005];
int p[120];
int f[120];
int n,m;

int main()
{
    while(scanf("%d %d",&m,&n)==2)
    {
        int fl=0;
        if(m>1800){m+=200;fl=1;}
        for(int i=1;i<=n;i++)
        {
            scanf("%d %d",&p[i],&f[i]);
        }
        memset(dp,0,sizeof(dp));
        memset(dp2,0,sizeof(dp2));
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                dp[i][j]=dp[i-1][j];
                dp2[i][j]=dp2[i-1][j];
                if(j>=p[i])
                {
                    if(dp[i][j]<dp[i-1][j-p[i]]+f[i])
                    {
                        dp[i][j]=dp[i-1][j-p[i]]+f[i];
                        dp2[i][j]=dp2[i-1][j-p[i]]+p[i];
                    }
                }
            }
        }
        if(m>2000&&fl&&dp2[n][m]<=2000)m-=200;
        printf("%d\n",dp[n][m]);
    }
    return 0;
}
