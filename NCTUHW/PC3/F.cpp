#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int a[1000005];
int p[1000005];
vector<int> rr[1000005];
vector<int> L;
int R[1000005];
typedef long long int ll;

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; i++){
		scanf("%d", a+i);
		p[a[i]] = i;
	}
	int x,y;
	for(int i=0; i<m; i++){
		scanf("%d%d", &x, &y);
		int l=min(p[x], p[y]), r=max(p[x], p[y]);
		L.push_back(l); R[r]++; rr[l].push_back(r);
	}
	R[n+1] = 1;
	sort(L.begin(), L.end());
	int li=0, ri=0;
	ll ans=(ll)n*(ll)(n-1)/2LL + (ll)n;
	for(int i=1; i<=n; i++){
		while(li<L.size()&&i>L[li]){
			for(int j=0; j<rr[L[li]].size(); j++){
				R[ rr[L[li]][j] ]--;
			}
			rr[L[li]].clear();
			li++;

		}
		while(R[ri]<=0)ri++;
		ll t = ri;
		ans -= n+1-t;
		//cout << ans <<endl;
	}
	printf("%lld\n", ans);
	return 0;
}
