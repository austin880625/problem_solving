#include <stdio.h>
#include <iostream>
#include <vector>
#define MAXN 2005
using namespace std;

int N,M;
vector<int> G[MAXN];
vector<int> R[MAXN];
vector<int> SCC[MAXN];
int stamp_owner[MAXN];
int dfs_clock;
int scc_cnt;
int vis[MAXN];

void dfs_for_stamp(int now)
{
	vis[now]=1;
	for(int i=0;i<R[now].size();i++){
		int v=R[now][i];
		if(!vis[v]){
			dfs_for_stamp(v);
		}
	}
	stamp_owner[now]=++dfs_clock;
}

void dfs_for_scc(int now)
{
	vis[now]=true;
	SCC[scc_cnt].push_back(now);
	for(int i=0;i<G[now].size();i++){
		int v=G[now][i];
		if(!vis[v])dfs_for_scc(v);
	}
}

int main()
{
	while(scanf("%d%d",&N,&M)==2)
	{
		for(int i=0,u,v;i<M;i++){
			scanf("%d%d",&u,&v);
			G[u].push_back(v);
			R[v].push_back(u);
		}
		for(int i=1;i<=N;i++)stamp_owner[i]=0,SCC[i].clear();
		dfs_clock=0;
		for(int i=1;i<=N;i++)if(!stamp_owner[i])dfs_for_stamp(i);
		for(int i=1;i<=N;i++)vis[i]=0;
		scc_cnt=0;
		for(int i=dfs_clock;i>=1;i--){
			if(!vis[stamp_owner[i]]){
				dfs_for_scc(stamp_owner[i]),scc_cnt++;
			}
		}
		int ans=0;
		for(int i=0;i<scc_cnt;i++)ans=max(ans,(int)SCC[i].size());
		printf("%d\n",ans);
	}
	return 0;
}
