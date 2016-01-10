#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
#include<cstring>
#include<stdio.h>
using namespace std;

const int MAX_N=1010;

struct Edge{
	int from,to;
	double w;
	bool operator < (const Edge& rhs) const{
		return w<rhs.w;
	}
};
vector<Edge> edges;
vector<int> G[MAX_N],Gt[MAX_N];
vector<int> nonmst;

double MST;
int n;
double X[MAX_N];
double Y[MAX_N];
int P[MAX_N];
int g[MAX_N];
int origin_size;
double maxCost[MAX_N][MAX_N];
int vis[MAX_N];
double ans;

int find(int x){
	return g[x]==x ? x : g[x]=find(g[x]);
}

void Kruskal(){
	sort(edges.begin(),edges.end());
	origin_size=edges.size();  //the origin edges.size()
	int ae=-2;
	for(int i=0;i<origin_size;i++){
		Edge& e=edges[i];
		int u=e.from,v=e.to;
		double w=e.w;
		//cout<<w<<endl;
		int r1=find(u),r2=find(v);
		if(r1!=r2){
			g[r1]=r2;
			edges.push_back((Edge){u,v,w});	//edges.size() increases
			Gt[u].push_back(edges.size()-1);  //the graph of the MST
			edges.push_back((Edge){v,u,w});  //so that from edges[s] to edges[edges.size()-1] are edges of the MST
			Gt[v].push_back(edges.size()-1);
			maxCost[u][v]=maxCost[v][u]=w;
			MST+=w;
			ae=i;
		}else{
			if(i!=ae+1){
			nonmst.push_back(i);
			}
			ae=-2;
		}
	}
}

void pre_process(){
	ans=0;
	memset(vis,0,sizeof(vis));
}

void dfs(int now, int fa){
	vis[now]=1;
	if(fa!=-1){
	for(int i=0;i<n;i++){
		if(vis[i]==1&&i!=now){
			maxCost[now][i]=maxCost[i][now]=max(maxCost[now][fa],maxCost[fa][i]);
			//cout<<now<<" "<<i<<" "<<maxCost[now][i]<<endl;;
		}
	}
	}
	for(int i=0;i<Gt[now].size();i++){  //every edges from now
		Edge& e=edges[Gt[now][i]];
		if(!vis[e.to]){
			//vis[e.to]=1;
			dfs(e.to,now);  
			//in the next dfs, maxCost[e.to(the next i which vis[i]=1)][e.to(the next now)] will be updated
		}
	}
}

void enumerate(){
	double a=0;
	for(int i=0;i<n;i++){
		for(int j=1;(i-j)&&j<=i;j++){
			a=(P[i]+P[j])/(MST-maxCost[i][j]);
			if(a>ans)ans=a;
		}
	}
}

int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<n;i++){
		G[i].clear();
		Gt[i].clear();
		X[i]=Y[i]=0;
		P[i]=0;
		}
		edges.clear();
		nonmst.clear();
		memset(maxCost,0,sizeof(maxCost));
		MST=0;

		for(int i=0;i<n;i++){
			g[i]=i;

			cin>>X[i]>>Y[i]>>P[i];
			for(int j=0;j<i;j++){
				double dx=X[i]-X[j];
				double dy=Y[i]-Y[j];
				double D=sqrt(dx*dx+dy*dy);
				edges.push_back((Edge){i,j,D});
				G[i].push_back(edges.size()-1);  //the origin graph
				edges.push_back((Edge){j,i,D});
				G[j].push_back(edges.size()-1);
			}
		}
		//for(int i=0;i<edges.size();i++)cout<<edges[i].from<<" "<<edges[i].to<<" "<<edges[i].w<<endl;
		Kruskal();

		pre_process();
		dfs(0,n);
		/*for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				cout<<maxCost[i][j]<<" ";
			cout<<endl;
		}*/
		enumerate();
		printf("%.2f\n",ans);
	}
	return 0;
}

