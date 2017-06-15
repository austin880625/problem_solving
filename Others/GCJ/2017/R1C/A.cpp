#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#define MAXN 1005
#define LL long long int
#define PI 3.14159265358979323846

using namespace std;

int N,K;

struct pan
{
	LL R,H;
	bool operator <(const pan &x)const
	{
		return R<x.R;
	}
};
pan P[MAXN];

LL dp[MAXN][MAXN];

int main()
{
	int T;
	scanf("%d",&T);
	for(int kase=1;kase<=T;kase++)
	{
		scanf("%d%d",&N,&K);
		for(int i=1;i<=N;i++)
		{
			scanf("%lld%lld",&P[i].R,&P[i].H);
		}
		sort(P+1,P+1+N);
		for(int i=0;i<=N;i++)dp[0][i]=0;
		for(int i=1;i<=N;i++)
		{
			dp[i][0]=0;
			for(int j=1;j<=i;j++)
			{
				dp[i][j]=dp[i-1][j-1]+P[i].R*P[i].H;
				if(i>j)
				{
					for(int x=i-1;x>0;x--)
						if(dp[x-1][j-1]+P[x].R*P[x].H==dp[x][j])
						{
							if(2*dp[i][j]+P[i].R*P[i].R<2*dp[x][j]+P[x].R*P[x].R)
								dp[i][j]=dp[x][j];
							//continue;
						}

				}
			}
		}
		int x=N;
		while(dp[x-1][K-1]+P[x].R*P[x].H!=dp[x][K]&&x>=K)x--;
		//cout<<x<<" "<<" "<<P[x].R<<" "<<dp[x][K]<<endl;
		printf("Case #%d: ",kase);
		printf("%lf\n",((double)(P[x].R*P[x].R)+(double)dp[x][K]*2)*PI);
	}
	return 0;
}
