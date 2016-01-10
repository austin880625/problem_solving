#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000;
struct Edge
{
	int from,to,w;
	bool operator < (const Edge& rhs) const
	{
		return w < rhs.w;
	}
};
int n,m;
int g[maxn];
vector<Edge> edges;
int find(int x){return g[x]==x?x:g[x]=find(g[x]);}
void Kruskal()
{
	int ans=0;
	sort(edges.begin(),edges.end());
	for(int i=0;i<n;i++) g[i]=i;

	for(int i=0;i<edges.size();i++)
	{
		Edge& e=edges[i];
		int u=e.from,v=e.to,x=find(u),y=find(v);
		if(x!=y)
		{
			ans+=e.w;
			g[y]=x;
		}
	}
	printf("%d\n",ans);
}
int main()
{
	while(scanf("%d%d",&n,&m)&&n)
	{
		edges.clear();

		for(int i=0;i<m;i++)
		{
			int x,y,w;
			scanf("%d%d%d",&x,&y,&w);
			edges.push_back((Edge){x,y,w});
		}
		Kruskal();
	}
}
