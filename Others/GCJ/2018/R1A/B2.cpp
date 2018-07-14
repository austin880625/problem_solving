#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <assert.h>

using namespace std;

#define ll long long
#define MAXN 100000
struct cas
{
	ll m,s,p;
	bool operator <(const cas &x)const{
		return s<x.s;
	}
};
cas c[MAXN];

ll det(ll subset, ll C, ll B, ll R){
	ll res=0;
	ll r=0;
	ll t=subset;
	while(t){r+=(t&1); t>>=1;}
	//cout<<r<<" "<<R<<endl;
	if(r > R)return 1LL<<62;
	for(ll i=0; i<C; i++){
		if(!B)break;
		if((subset>>i)&1){
			res=max(res, c[i].p + c[i].s);
			B--;
		}
	}
	//cout<<subset<<" "<<B<<endl;
	for(ll i=0; i<C; i++){
		if(!B)break;
		if((subset>>i)&1){
			if(B>c[i].m-1){res = max(res, c[i].p+c[i].s*c[i].m); B-=(c[i].m-1);}
			else {res = max(res, c[i].p+c[i].s*(B+1)); B=0;}
		}
	}
	//cout<<B<<endl;
	if(B)return (1LL<<62);
	return res;
}
int main()
{
	ll T,R,C;
	ll B;
	scanf("%lld", &T);
	for(ll kase=1; kase <= T; kase++){
		scanf("%lld%lld%lld", &R, &B, &C);
		for(ll i=0; i<C; i++){
			scanf("%lld%lld%lld", &c[i].m, &c[i].s, &c[i].p);
		}
		sort(c, c+C);
		ll ans = (1LL<<62);
		for(ll S=0; S<(1<<C); S++){
			ans = min(ans, det(S,C,B,R));
		}
		assert(ans!=(1LL<<62));
		printf("Case #%lld: %lld\n", kase, ans);
	}
	return 0;
}
