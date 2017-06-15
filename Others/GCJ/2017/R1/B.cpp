#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <set>
#include <map>

#define MAXN 1005

using namespace std;

vector<int> G[MAXN];
int N;
int path[MAXN];
int C[MAXN];
int isset[7]={1,1,1,0,1,0,0};
int colorname[7]={0,1,3,2,6,4,5};
char color[7]={'c','R','Y','O','B','V','G'};
int cnt;

int mat[7][7]={{0,0,0,0,0,0,0},{0,0,1,0,1,0,1},{0,1,0,0,1,1,0},{0,0,0,0,1,0,0},{0,1,1,1,0,0,0},{0,0,1,0,0,0,0},{0,1,0,0,0,0,0}};

int con[MAXN];
int vis[MAXN];

int canconnect(int x,int y)
{
	//if(C[x]==C[y])return 0;
	//cout<<C[x]<<C[y]<<endl;
	return mat[C[x]][C[y]];
	for(int c=1;c<=6;c++)if(isset[c]&&c<=C[x]&&c<=C[y] )
		if(isset[C[x]-c]&&isset[C[y]-c])return 0;
	return 1;
}

int dfs(int now,int step)
{
	path[step]=now;
	//cout<<step<<" "<<now<<endl;
	if(step==N-1&&canconnect(now,0))return 1;
	for(int i=0;i<G[now].size();i++)
	{
		int v=G[now][i];
		if(!vis[v])
		{
			vis[v]=1;
			int res=dfs(v,step+1);
			if(res)return 1;
			vis[v]=0;
		}
	}
	return 0;
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int kase=1;kase<=T;kase++)
	{
		cnt=0;
		scanf("%d",&N);

		for(int i=1;i<=6;i++)
		{
			int t;
			scanf("%d",&t);
			for(int j=0;j<t;j++)
			{
				C[cnt++]=colorname[i];
			}
		}
		for(int i=0;i<N;i++)G[i].clear();
		//for(int i=0;i<N;i++)cout<<colorname[C[i]];cout<<endl;
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<i;j++)
			{
				if(canconnect(i,j))
				{
					G[i].push_back(j);
					G[j].push_back(i);
				}
			}
		}
		int ans=1;
		/*for(int i=0;i<N;i++)
		{
			cout<<G[i].size()<<": ";
			for(int j=0;j<G[i].size();j++)cout<<G[i][j]<<" ";cout<<endl;
			//if(G[i].size()%2){ans=0;break;}
		}*/
		//cout<<endl;

		for(int i=0;i<N;i++)vis[i]=con[i]=0;
		vis[0]=1;
		ans=dfs(0,0);

		printf("Case #%d: ",kase);
		if(ans==0){printf("IMPOSSIBLE\n",kase);continue;}

		for(int i=0;i<N;i++)printf("%c",color[C[path[i]]]);
		puts("");
	}
    return 0;
}
