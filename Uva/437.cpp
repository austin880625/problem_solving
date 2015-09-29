#include<iostream>
#include<vector>

using namespace std;

struct edge
{
	int u,v,w;
};
struct hed
{
	int h,l,w;
};

#define MAX_N 35
int n;
hed blocks[3*MAX_N];
vector<edge> edges;
vector<int>
G[3*MAX_N];
int dp[3*MAX_N];

bool cmp(hed h1,hed h2)
{
	return ((h1.l>h2.l&&h1.w>h2.w)||(h1.l>h2.w&&h1.w>h2.l));
}

void CG()
{
	for(int i=0;i<3*n;i++)
	{
		for(int j=0;j<3*n;j++)
		{
			if(cmp(blocks[i],blocks[j]))
			{
				edges.push_back((edge){i,j,blocks[i].h});
				G[i].push_back(edges.size()-1);
			}
		}
	}
}

int DP(int t)
{
	if(dp[t])return dp[t];
	else if(G[t].size())
	{
		for(int i=0;i<G[t].size();i++)
		{
			edge &e=edges[G[t][i]];
			dp[t]=max(dp[t],DP(e.v)+e.w);
		}
		return dp[t];
	}else return dp[t]=blocks[t].h;
}

int main()
{
	int k=0;
	while(cin>>n)
	{
		if(!n)break;
		edges.clear();
		for(int i=0;i<3*n;i++){G[i].clear();dp[i]=0;}
		for(int i=0;i<n;i++)
		{
			int w,l,h;
			cin>>w>>l>>h;
			blocks[3*i]=(hed){w,l,h};
			blocks[3*i+1]=(hed){l,w,h};
			blocks[3*i+2]=(hed){h,w,l};
		}
		CG();
		int ans=0;
		for(int i=0;i<3*n;i++)ans=max(ans,DP(i));
		cout<<"Case "<<++k<<": maximum height = "<<ans<<endl;
	}
	return 0;
}

