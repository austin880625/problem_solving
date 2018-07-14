#include <stdio.h>
#include <iostream>

using namespace std;

int g[35][35];
int rem[35];
int n, m;

int main()
{
	while(scanf("%d%d", &n,&m)==2){
		for(int i=0; i<n; i++)for(int j=0; j<n; j++)g[i][j] = 0;
		for(int i=0; i<n; i++)rem[i] = 0;
		for(int i=0; i<m; i++)
		{
			int u,v;
			scanf("%d%d", &u, &v);
			g[u][v] = g[v][u] = 1;
		}
		if(m==0)
		{
			if(n>0)printf("1\n");
			else printf("0\n");
			continue;
		}
		int ans = 0;
		for(int l=0; l<n; l++)
		for(int i=0; i<n; i++)
		{
			if(!g[l][i])continue;
			for(int j=0; j<n; j++)rem[j]=0;
			rem[i] = 1;
			rem[l] = 1;

			int tmp = 0;
			for(int j=0; j<n; j++)
			{
				if(g[i][j] && g[l][j])
				{
					rem[j] = 1;
				}
			}
			for(int j=0; j<n; j++)if(rem[j])tmp++;
			int v=1;
			for(int j=0; j<n; j++)
			{
				for(int k=0; k<n; k++)
				{
					if(j!=k && rem[j] && rem[k] && !g[j][k])v=0;
				}
			}
			if(v)ans = max(ans, tmp);
		}
		printf("%d\n", ans);
	}
	return 0;
}
