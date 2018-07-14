#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void pdr(int dr) {
 for (int i = 0; i < dr; ++i) {
 	cout << "--";
 }
}
int ans;
void dfs(const vector<int> state, const priority_queue<int,vector<int>, greater<int> > sp ,int now, int dr = 0)
{
	int n = state.size();
	/*pdr(dr);printf("beg: %d %d\n", n, now);
	for(int i=0; i<n; i++){
		printf("%d ", state[i]);
	}puts("");*/
	if(n==2){ 
		//pdr(dr);printf("upd: %d\n", now+max(state[0],state[1]));
		ans = min(ans, now+max(state[0],state[1])); 
		return ;
	}
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			int x=state[i], y=state[j];
			priority_queue<int, vector<int>, greater<int> > p = sp;
			vector<int> s = state;
			swap(s[j], s.back()); s.pop_back();
			swap(s[i], s.back()); s.pop_back();
			p.push(x); p.push(y);
			s.push_back(p.top());
			int cost = p.top();
			p.pop();
			dfs(s, p, now + max(x,y) + cost, dr + 1);
		}
	}
	//pdr(dr);printf("end: %d\n", n);
}
vector<int> v;
priority_queue<int, vector<int>, greater<int> > p;
int main()
{
	int t,n;
	scanf("%d", &t);
	while(t--){
		v.clear();
		scanf("%d", &n);
		for(int i=0,d,u; i<n; i++){scanf("%d%d",&d, &u); v.push_back(u);}
		ans=2147483647;
		dfs(v,p,0);
		printf("%d\n", ans);
	}

	return 0;
}
