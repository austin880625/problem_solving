#include<stdio.h>


#define MAX_N 50
#define MAX_T 250
#define inf 20000000
int n,t;
int M1,M2;
int ans;
int times[MAX_N+25];
int hastraint[MAX_T][MAX_N];
int hastrainb[MAX_T][MAX_N];
int DP[MAX_T][MAX_N];
int d[MAX_N];
int e[MAX_N];

int main()
{
	int k=0;
	while(scanf("%d",&n))
	{
		if(!n)break;
		
		scanf("%d",&t);
		int i;
		for(i=0;i<=t;i++)
		{
			int j;
			for(j=0;j<=n;j++)
				hastraint[i][j]=hastrainb[i][j]=0;
		}

		for(i=1;i<n;i++)scanf("%d",&times[i]);
		scanf("%d",&M1);
		for(i=0;i<M1;i++)
		{
			scanf("%d",&d[i]);
			int dur=0;
			int j;
			for(j=1;j<n;j++)
			{
				if(d[i]+dur<=t)hastraint[d[i]+dur][j]=1;
				dur+=times[j];
			}
		}
		scanf("%d",&M2);
		for(i=0;i<M2;i++)
		{
			scanf("%d",&e[i]);
			int dur=0;
			int j;
			for(j=n;j>=1;j--)
			{
				if(e[i]+dur<=t)hastrainb[e[i]+dur][j]=1;
				if(j>1)dur+=times[j-1];
			}
		}
		for(i=t;i>=0;i--)
		{
			int j;
			for(j=0;j<=n;j++)
				DP[i][j]=inf;
		}
		DP[t][n]=0;
		
		for(i=t-1;i>=0;i--)
		{
			int j;
			for(j=1;j<=n;j++)
			{
				DP[i][j]=DP[i+1][j]+1;
				if(j<n&&hastraint[i][j]&&i+times[j]<=t)
				{
					if(DP[i][j]>DP[i+times[j]][j+1])DP[i][j]=DP[i+times[j]][j+1];
				}
				if(j>1&&hastrainb[i][j]&&i+times[j-1]<=t)
				{
					if(DP[i][j]>DP[i+times[j-1]][j-1])DP[i][j]=DP[i+times[j-1]][j-1];
				}
			}
		}
		printf("Case Number %d: ",++k);
		if(DP[0][1]>=inf)printf("impossible\n");
		else printf("%d\n",DP[0][1]);
	}
	return 0;
}

