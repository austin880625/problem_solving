#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

struct edge{
	int from,to;long long int w;
	bool operator < (const edge& rhs) const{
		return w<rhs.w;
	}
};

const int MAX_N=1005,MAX_Q=10;
//vector<int> Gt[MAX_N];
vector<edge> edges;
vector<edge> MSTedges;
//vector<edge> totry;
vector<int> sn[MAX_Q];
long long int Cost[MAX_Q];
long long int ans;
int p[MAX_N];
int X[MAX_N],Y[MAX_N];
int n,q;
int Totry[MAX_Q];

long long int distance(int x1,int y1,int x2,int y2){
	int dx=x2-x1;
	int dy=y2-y1;
	return dx*dx+dy*dy;
}

int find(int x){return (x==p[x] ? x : p[x]=find(p[x]));}

void pre_process(){
	ans=-1;
	//edges.clear();
	//totry.clear();
	MSTedges.clear();
	//for(int i=0;i<q;i++)sn[i].clear();
	for(int i=0;i<n;i++)p[i]=i;
	for(int i=0;i<q;i++)Totry[i]=0;
}

void emunerate(int s,int use){
	if(s==q){	//recursion finished
		long long int tmp=0;
		for(int i=0;i<n;i++)p[i]=i;
		for(int i=0;i<q;i++){
			//cout<<Totry[i]<<" ";
			if(Totry[i]){
				int o=sn[i][0];
				tmp+=Cost[i];
				for(int j=0;j<sn[i].size();j++)
					if(p[sn[i][j]]-sn[i][j])p[o]=find(sn[i][j]);	//if there is a vertex in TWO or more subnetworks
					else p[sn[i][j]]=o;
					//totry.push_back((edge){o,sn[i][j],0});
			}
			//for(int i=0;i<n;i++)cout<<p[i]<<" ";
			//cout<<endl;
		}
		/*for(int i=0;i<totry.size();i++){
			edge& e=totry[i];
			int f=e.from,t=e.to,x=find(f),y=find(t);
			if(x-y){
				p[x]=y;
				tmp+=e.w;
				//cout<<f<<" "<<t<<" "<<e.w<<"  "<<tmp<<endl;
			
				edge re=(edge){t,f,e.w};
				MSTedges.push_back(e);
				Gt[f].push_back(MSTedges.size()-1);
				MSTedges.push_back(re);
				Gt[t].push_back(MSTedges.size()-1);
					
			}
		}*/
		//cout<<endl;
		for(int i=0;i<MSTedges.size();i++){
			edge& e=MSTedges[i];
			int f=e.from,t=e.to,x=find(f),y=find(t);
			if(x-y){
				p[x]=y;
				tmp+=e.w;
				//cout<<f<<" "<<t<<" "<<e.w<<endl;
				/*
				edge re=(edge){t,f,e.w};
				MSTedges.push_back(e);
				Gt[f].push_back(MSTedges.size()-1);
				MSTedges.push_back(re);
				Gt[t].push_back(MSTedges.size()-1);
				*/
			}
		}
		//cout<<tmp<<endl;
		if(tmp<ans||ans==-1)ans=tmp;
		//totry.clear();
	}else{
		Totry[s]=use;
		//cout<<totry.size()<<endl;
		emunerate(s+1,0);
		emunerate(s+1,1);
	}
}

void Kruskal(){
	sort(edges.begin(),edges.end());

	for(int i=0;i<edges.size();i++){
		edge& e=edges[i];
		int f=e.from,t=e.to;
		int x=find(f),y=find(t);
		if(x-y){
			p[x]=y;
			//edge re=(edge){t,f,e.w};
			MSTedges.push_back(e);
			//cout<<i<<" "<<f<<" "<<t<<" "<<e.w<<endl;
			//Gt[f].push_back(MSTedges.size()-1);
			//MSTedges.push_back(re);
			//Gt[t].push_back(MSTedges.size()-1);
		}
		//cout<<i<<endl;
	}
	//Kruskal finished

	//for(int i=0;i<n;i++)p[i]=i;
	//a=0;
	emunerate(0,0);	//use sn[0]
	emunerate(0,1);	//didn't use sn[0]
}

int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>n>>q;
		edges.clear();
		for(int i=0;i<q;i++){
			sn[i].clear();
			int city,cost;
			cin>>city>>Cost[i];
			for(int j=0;j<city;j++){
				int c;
				cin>>c;
				sn[i].push_back(c-1);
			}
		}
		for(int i=0;i<n;i++){
			int x,y;
			cin>>x>>y;
			X[i]=x;
			Y[i]=y;
			for(int j=0;j<i;j++){
				edges.push_back((edge){i,j,distance(X[i],Y[i],X[j],Y[j])});
			}
		}
		pre_process();
		Kruskal();
		cout<<ans<<endl;
		if(T)cout<<endl;	//(if T!)a BLANK LINE!!
	
	}
	return 0;
}

