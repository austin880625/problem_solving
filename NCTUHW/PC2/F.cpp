#include <stdio.h>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

#define MAXN 150005

map<int, set<int> > M;
priority_queue<int, vector<int>, greater<int> > pq;
int a[MAXN];
int used[MAXN];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", a+i);
		if(M.find(a[i]) == M.end())M.insert(pair<int, set<int> >(a[i], set<int>()));
		M[a[i]].insert(i);
		used[i] = 1;
	}
	for(int i=0; i<n; i++) {if(M[a[i]].size()>=2)pq.push(i);}
	while(!pq.empty()){
		int i = pq.top(); pq.pop();
		if(!used[i]||M[a[i]].size()<2)continue;
		//cout << i << " " << a[i] << " " << M[a[i]].size() << endl;
		auto rit = M[a[i]].begin(); M[a[i]].erase(rit);
		auto lit = M[a[i]].begin(); 
		if(M[a[i]].size() == 0)M.erase(a[i]);
		if(M.find(2*a[i]) == M.end())M.insert(pair<int, set<int> >(2*a[i], set<int>()));
		M[2*a[i]].insert(*lit);
		int j=*lit;
		used[i] = 0;
		//cout << *rit << " ";
		M[a[i]].erase(lit);
		if(M[a[i]].size()>=2)pq.push(*(M[a[i]].begin()));
		a[j] = 2*a[i];
		//cout <<i<< "  " <<a[i] <<endl;
		if(M[2*a[i]].size() >= 2)pq.push(*(M[2*a[i]].begin()));
	}
	int f=0;
	int ans=0;
	for(int i=0; i<n; i++)ans+=used[i];
	printf("%d\n", ans);
	//for(int i=0; i<n; i++)cout << a[i] << " ";puts("");
	for(int i=0; i<n; i++){
		if(f&&used[i])printf(" ");
		if(used[i])f=1, printf("%d", a[i]);
	}
	puts("");
	return 0;
}
