#include <stdio.h>
#include <iostream>
#include <vector>
#define MAXN 1000006

using namespace std;

vector<int> G[MAXN];
int dep[MAXN];
int h[2][MAXN];
int r[MAXN];

void dfs(int now, int pa, int d){
	dep[now] = d;
	h[0][now] = 1;
	h[1][now] = 1; 
	for(int i=0; i<G[now].size(); i++){
		int v = G[now][i];
		dfs(v, now, d+1);
		if(h[0][v] + 1 >= h[0][now]){
			h[1][now] = h[0][now];
			h[0][now] = h[0][v] + 1;
		}
	}
}

void dfs2(int now, int pa, int d){
	if(pa!=0)r[now] = max(r[pa]+1, h[0][now] + 1 == h[0][pa] ? h[1][pa] : h[0][pa]);
	for(int i=0; i<G[now].size(); i++){
		int v = G[now][i];
		dfs2(v, now, d+1);
	}
}
int pa[MAXN];
int main()
{
	int T;
	scanf("%d", &T);
	while(T--){
		int n;
		scanf("%d", &n);
		for(int i=0;i<=n;i++)G[i].clear(), r[i]=0, dep[i]=0, pa[i] = -1, h[0][i]=h[1][i]=0;
		for(int i=0,p,c ;i<n-1; i++){
			scanf("%d%d", &p,&c);
			G[p].push_back(c);
			pa[c] = p;
		}
		int root=0;
		for(int i=1; i<=n; i++)if(pa[i] == -1){root = i; break;}
		dfs(root, 0, 0);
		r[root] = 0;
		dfs2(root, 0, 0);
		long long int H=0,R=0;
		for(int i=1; i<=n; i++){
			//printf("%d %d %d\n", h[0][i]-1, h[1][i]-1, r[i]);
			H += h[0][i]-1;
			R += max(h[0][i]-1, r[i]);
		}
		printf("%lld %lld\n", H, R);
	}
	return 0;
}
