#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct edge{
	int from,to,w;
	bool operator < (const edge& rhs) const{
		return w<rhs.w;
	}
};

const int MAX_N=105,MAX_W=10005;
int n,m;
//vector<int> G[MAX_N];
vector<edge> edges;
int ans;
int p[MAX_N];
int Max,Min;

void pre_process(){
	Max=0;Min=MAX_W;
	edges.clear();
	for(int i=0;i<=n;i++){p[i]=i;}
	ans=-1;
}

int find(int x){return (x==p[x] ? x : p[x]=find(p[x]));}

int is_connected(){
	int res=1;
	int r=find(1);
	for(int i=1;i<=n;i++){
		if(find(i)!=r)res=0;
	}
	return res;
}

void Kruskal(){
	int es=n-1;
	sort(edges.begin(),edges.end());
	for(int i=0;es==n-1;i++){
	es=0;
	for(int r=i;r<edges.size();r++){
		edge& e=edges[r];
		int u=e.from,v=e.to;
		int x=find(u),y=find(v);
		if(x-y){
			p[x]=y;
			es++;
			if(e.w>Max)Max=e.w;
			if(e.w<Min)Min=e.w;
		}
	}
	int a=Max-Min;
	//cout<<Max<<" "<<Min<<" "<<es<<endl;
	for(int i=0;i<=n;i++)p[i]=i;	//from 1 to n
	if(es==n-1&&(a<ans||ans==-1))ans=a;
	
	Max=0;Min=MAX_W;
	}
}

int main(){
	while(cin>>n>>m&&(n!=0||m!=0)){
		pre_process();
		for(int i=0;i<m;i++){
			int a,b,w;
			cin>>a>>b>>w;
			edges.push_back((edge){a,b,w});
			//G[a].push_back(edges.size()-1);
			//edges.push_back((edge){b,a,w});
			//G[b].push_back(edges.size()-1);
		}

		Kruskal();	//Minimum bottle neck spanning tree
		cout<<ans<<endl;
	}
	return 0;
}

