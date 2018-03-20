#include <stdio.h>
#include <iostream>
#define MAXN 205

using namespace std;

int w[MAXN][MAXN];
int vis[MAXN];
int deg[MAXN];
int p[MAXN*5];

int main()
{
	int T,n,m;
	scanf("%d",&T);
LOOP:	while(T--)
	{
		scanf("%d%d",&n,&m);
		int h=n/2;
		for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)w[i][j]=0;
		for(int i=0;i<=n;i++)vis[i]=deg[i]=0;
		for(int i=0,u,v; i<m; i++){
			scanf("%d%d",&u,&v);
			w[u][v]=w[v][u]=1;
			deg[u]++,deg[v]++;
		}
		if(n%2){puts("-1"); goto LOOP;}
		for(int i=0;i<n;i++)if(deg[i]!=3){puts("-1"); goto LOOP;}
		int p0=0, p1, p2, p3;
		p[0]=p0;
		for(p1=1; p1<n&&w[0][p1]==0; p1++);
		for(p2=1; p2<n; p2++){
			if(w[p0][p2]&&p2!=p1){
				for(p3=1;p3<n&&!(w[p2][p3]&&w[p1][p3]);p3++);
				if(p3!=n)break;
			}
		}
		if(p1==n||p2==n||p3==n){puts("-1"); goto LOOP;}
		int d1,d2;
		for(d1=0; d1<n&&!(w[p0][d1]&&d1!=p1&&d1!=p2); d1++);
		for(d2=0; d2<n&&!(w[p1][d2]&&d2!=p0&&d2!=p3); d2++);
		if(d1==n||d2==n){puts("-1"); goto LOOP;}
		if(w[d1][d2]){
			p[h]=p1;
			p[1]=p2;
			p[h+1]=p3;
		}
		else{
			p[1]=p1;
			p[h]=p2;
			p[h+1]=p3;
		}
		vis[p[0]] = vis[p[1]] = vis[p[h]] = vis[p[h+1]] = 1;
		int ans=1;
		for(int i=2; i<h; i++){
			int j;
			for(j=0;j<n;j++){
				if(w[j][p[i-1]]&&!vis[j]){
					p[i] = j;
					vis[j] = 1;
					break;
				}
			}
			if(j==n)ans=-1;
			for(j=0;j<n;j++){
				if(w[j][p[h+i-1]]&&!vis[j]){
					p[h+i] = j;
					vis[j] = 1;
					break;
				}
			}
			if(j==n)ans=-1;
			if(w[p[i]][p[h+i]]==0)ans=-1;
		}
		if(!(w[p[h-1]][p[0]]&&w[p[h+h-1]][p[h]]))ans=-1;
		if(ans==-1)puts("-1");
		else{
		printf("%d",p[0]);
			for(int i=1;i<n;i++)printf(" %d",p[i]);
		puts("");
		}

	}
	return 0;
}
