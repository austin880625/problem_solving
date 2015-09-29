#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
#include<cstdlib>
using namespace std;

const int MAX_V=205;

struct edge{
int to;
};

vector<edge> G[MAX_V];
int color[MAX_V];

void addEdge(int u,int v){
	edge e;
	e.to=v;
	G[u].push_back(e);
	e.to=u;
	G[v].push_back(e);
}

int dfs(int v,int c){
	color[v]=c;
	for(int i=0;i<G[v].size();i++){
		if(color[v]==color[G[v][i].to])return 0;
		else if(color[G[v][i].to]==0){
			if(!dfs(G[v][i].to,-c))return 0;
		}
	}
	return 1;
}

int main(){
	int V;
	int L;
	while(cin>>V){
		if(V==0)break;
		for(int i=0;i<MAX_V;i++){
			G[i].clear();
			color[i]=0;
		}
		cin>>L;
		while(L--){
			int u,v;
			cin>>u>>v;
			addEdge(u,v);
		}
		int ans=1;
		for(int i=0;i<V;i++){
			if(color[i]==0){
				if(!dfs(i,1)){ans=0;break;}
			}
		}
		cout<<(ans ? "BICOLORABLE." : "NOT BICOLORABLE.")<<endl;
	}
}
