#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#define MAXN 1000
#define INF 10000000
using namespace std;
int arr[25][25],m,n,ans;
int dx[4] = {1,0,0,-1}, dy[4] = {0,1,-1,0};
bool vis[25][25];

struct edge{
	int v,w;
	bool operator <(const edge &x)const{
		return w>x.w;
	}
};
priority_queue<edge> Q;
vector<edge> G[MAXN];
int d[MAXN];

int main(void){
	scanf("%d%d",&m,&n);
	for(int i=0;i<m;++i){
		for(int j=0;j<n;++j){
			scanf("%d",&arr[i][j]);
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<4;k++){
				int nx=i+dx[k],ny=j+dy[k];
				if(nx>=0&&nx<m&&ny>=0&&ny<n&&abs(arr[i][j]-arr[nx][ny])<=1){
					G[i*n+j].push_back((edge){nx*n+ny,abs(arr[i][j]-arr[nx][ny])});
					G[nx*n+ny].push_back((edge){i*n+j,abs(arr[i][j]-arr[nx][ny])});
				}
			}
		}
	}
	for(int i=0;i<m*n;i++)d[i]=INF;
	Q.push((edge){0,0});
	d[0]=0;
	while(!Q.empty()){
		edge e=Q.top();Q.pop();
		for(int i=0;i<G[e.v].size();i++){
			if(d[G[e.v][i].v]>d[e.v]+G[e.v][i].w){
				d[G[e.v][i].v]=d[e.v]+G[e.v][i].w;
				Q.push((edge){G[e.v][i].v,d[G[e.v][i].v]});
			}
		}
	}
	ans=d[m*n-1];
	if(ans==INF) puts("NA");
	else printf("%d\n",ans);
	return 0;
}
