#include<bits/stdc++.h>
#define piHalf acos(0)
#define eps 1e-7
using namespace std;

#define ll long long
#define pt pair<ll,ll>



bool canLap(pt a, pt b){
	if( a.first*a.first+a.second*a.second < b.first*b.first+b.second*b.second)
		return false;
	if(a.first>b.first && a.second > b.second) return true;

	double l2 = sqrt(b.first*b.first + b.second*b.second);
	double t1= asin(a.second/l2);
	double t2 = acos(a.first/l2);
	return t1>t2;
}

int main(){
	int T; cin>>T;
	while(T--){
		int n; cin>>n;
		vector<pt> arr;
		set<pt> vis;
		vector<vector<int> > adjList;
		for(int i=0;i<n;++i){
			ll a,b;
			cin>>a>>b;
			if(a>b) swap(a,b);
			if(vis.count({a,b})) continue;
			vis.insert({a,b});
			arr.push_back({a,b});
			adjList.push_back(vector<int>());
			for(int j=0;j<arr.size()-1;++j){
				if( canLap(arr.back(),arr[j]) )
					adjList[arr.size()-1].push_back(j);
				else if( canLap(arr[j],arr.back()) )
					adjList[j].push_back(arr.size()-1);
			}
		}
		int out = 0;
		for(int i=0;i<arr.size();++i)
			if(adjList[i].empty()) ++out;
		cout<<out<<"\n";
	}


	return 0;
}

