#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 100005;

int n,ans;
int p[MAXN];
int d[MAXN];
vector<int> G[MAXN];

void dfs(int now, int dep){
	d[dep]++;
	for(int i=0; i<G[now].size(); i++){
		int v = G[now][i];
		dfs(v, dep+1);
	}
}

int main()
{
	scanf("%d",&n);
	ans=0;
	for(int i=2;i<=n;i++){
		scanf("%d",p+i);
		G[p[i]].push_back(i);
	}
	dfs(1,1);
	for(int i=1; i<=n; i++)if(d[i]%2)ans++;
	printf("%d\n",ans);
	
	return 0;
}
