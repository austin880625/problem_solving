#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <assert.h>
#define MAXN 100

using namespace std;

int N,M;
char S[MAXN][MAXN];
int dis[MAXN][3];
int ans[3];

void examine(int x)
{
	dis[x][0]=dis[x][1]=dis[x][2]=1000;
	for(int i=0;i<M;i++)
	{
		if('0'<=S[x][i]&&S[x][i]<='9')dis[x][0]=min(dis[x][0],min(i,M-i));
		else if('a'<=S[x][i]&&S[x][i]<='z')dis[x][1]=min(dis[x][1],min(i,M-i));
		else if(S[x][i]=='#'||S[x][i]=='*'||S[x][i]=='&')dis[x][2]=min(dis[x][2],min(i,M-i));
	}
}

int main()
{
	while(scanf("%d%d",&N,&M)==2)
	{
		for(int i=0;i<N;i++)
		{
			scanf("%s",S[i]);
			examine(i);
		}
		ans[0]=ans[1]=ans[2]=1000;
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<3;j++)
			{
				ans[j]=min(ans[j],dis[i][j]);
			}
		}
		assert(ans[0]!=1000&&ans[1]!=1000&&ans[2]!=1000);
		printf("%d\n",ans[0]+ans[1]+ans[2]);
	}
	return 0;
}
