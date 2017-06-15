#include <stdio.h>
#include <iostream>
#define INF 2147483647000000000
#define LL long long int

using namespace std;

int n,k;
LL m;
LL w[2005];
LL dp[2005][2005];

LL sum(LL x,LL y)
{
	LL t=x%m;
	if(t+y>m)
	{
		if(y<=m)return m*((x/m)+1)+y;
		else return INF;
	}
	return x+y;
}

int main()
{
    while(scanf("%d%d%lld",&n,&k,&m)==3)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",w+i);
        }
        dp[0][0]=0;
        dp[0][1]=INF;
        for(int i=1;i<=n;i++)
        {
        	dp[i][0]=0;
        	dp[i][i+1]=INF;
            for(int j=1;j<=i;j++)
			{
				dp[i][j]=min(dp[i-1][j],sum(dp[i-1][j-1],w[i]));
			}
        }
        for(int i=n;i>=0;i--)
		{
			LL r=dp[n][i]%m;
			//cout<<dp[n][i]<<" ";
			if(r&&dp[n][i]/m+1<=k){printf("%d\n",i);break;}
			else if(r==0&&dp[n][i]/m<=k){printf("%d\n",i);break;}
		}
    }
    return 0;
}
