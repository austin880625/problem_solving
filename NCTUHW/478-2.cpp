#include <stdio.h>
#include <iostream>

using namespace std;

typedef long long int ll;
ll A[100005];
ll C[2][100005];

void add(ll pos, ll v, int n, int i){
	while(pos<=n){
		C[i][pos]+=v;
		pos+=(pos&(-pos));
	}
}
ll sum(ll pos, int i){
	ll res = 0;
	while(pos){
		res += C[i][pos];
		pos -= (pos&(-pos));
	}
	return res;
}

int main()
{
	int t,n;
	scanf("%d", &t);
	while(t--){
		for(int i=0; i<=100000; i++)C[0][i] = C[1][i] = 0;
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			scanf("%lld", A+i);
			add(A[i], A[i], 100000, 0);
			add(A[i], 1, 100000, 1);
		}
		ll a=100001, res = 0;
		for(int i=n-1; i>=0; i--){
			ll b = a;
			a = min(a, A[i]);
			ll s = sum(b, 0) - sum(a, 0);
			ll c = sum(b, 1) - sum(a, 1);
			res += a*(s - c*a);
			add(a, a*(c-1), 100000, 0);
			add(a, c-1, 100000, 1);
		}
		printf("%lld\n", res);
	}
	return 0;
}
