#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

typedef int ll;
#define MAXN 100005
ll x[MAXN];

void print(ll ans){
	printf("%d", ans);
}
int main()
{
	int m;
	scanf("%d", &m);
	while(m--){
		int t;
		scanf("%d", &t);
		for(int i=0, id; i<t; i++){
			scanf("%d %d", &id, x+i);
		}
		sort(x, x+t);
		ll ans = 0;
		int n;
		for(n=t; n>3; n-=2){
			ll t1 = x[1] + x[0] + x[n-1] + x[1];
			ll t2 = x[n-1] + x[0] + x[n-2] + x[0];
			ans += 2*x[1] > x[0] + x[n-2] ? t2 : t1;
		}
		if(n == 3){ ans += x[0] + x[1] + x[2]; }
		else if(n == 2){ ans += x[1]; }
		else { ans += x[0]; }
		print(ans);
		puts("");
	}
	return 0;
}
