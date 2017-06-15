#include <stdio.h>
#include <iostream>
#include <vector>
#define MAXN 1000005
#define LL long long int

using namespace std;

int h[MAXN];
vector<int> G[MAXN];
LL N;
int ans1;LL ans2;
int stk[MAXN];
LL sz[MAXN];
int f,r;
inline int Sz(){return r-f+1;}
inline int back(){return stk[r];}
inline int back2(){return stk[r-1];}

void dfs(int now,int fa)
{
	sz[now]=1LL;
	LL tmp=(N-1)*N;
	for(int i=0;i<G[now].size();i++)
	{
		int v=G[now][i];
		if(v==fa)continue;
		dfs(v,now);
		tmp-=sz[v]*(sz[v]-1);
		sz[now]+=sz[v];
	}
	tmp-=(N-sz[now])*(N-sz[now]-1);
	if(tmp>ans2)
	{
		ans2=tmp;ans1=now;
	}
	else if(tmp==ans2)ans1=min(ans1,now);
}

int main()
{
	scanf("%lld",&N);
	f=0;r=-1;
	ans1=MAXN+10;
	ans2=0;
	for(LL i=0;i<N;i++)
	{
		scanf("%d",h+i);
		while(Sz()&&h[i]>h[back()])
		{
			//cout<<i<<" "<<back()<<endl;
			if(Sz()<2)
			{

				int v=back();
				G[i].push_back(v);G[v].push_back(i);
			}
			else
			{
				int v=back2();
				if(h[i]>h[v])
				{
					G[v].push_back(back());
					G[back()].push_back(v);
				}
				else
				{
					G[back()].push_back(i);
					G[i].push_back(back());
				}
			}
			r--;
		}
		stk[++r]=i;
	}
	while(Sz()>=2)
	{
		G[back()].push_back(back2());
		G[back2()].push_back(back());
		r--;
	}
	/*for(int i=0;i<N;i++)
	{
		cout<<"from "<<i<<" :";
		for(int j=0;j<G[i].size();j++)cout<<G[i][j]<<" ";
		puts("");
	}*/
	dfs(0,-1);

	printf("%lld %d\n",ans2,ans1+1);
	return 0;
}
