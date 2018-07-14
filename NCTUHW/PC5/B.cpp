#include <stdio.h>
#include <iostream>

using namespace std;

typedef long long int ll;
const ll mod = 1000000007;

ll d;
void gcd(ll a, ll b, ll &x, ll &y)
{
	if(b == 0){x=1, y=0; d=a; return ;}
	ll x0, y0;
	gcd(b, a%b, x0, y0);
	x = -y0;
	y = -x0 - (a/b)*y0;
}

ll mpow(ll v, ll d)
{
	ll x=v;
	ll res = 1;
	while(d){
		if(d&1){res *= x; res %= mod;}
		d>>=1;
		x = x*x;
		x%=mod;
	}
	return res;
}

ll inv(ll a)
{
	ll y, x;
	gcd(a, mod, x, y);
	return (x+mod)%mod;
}

int main()
{
	ll v,d;
	int T;
	scanf("%d", &T);
	for(int kase=1; kase<=T; kase++)
	{
		scanf("%lld%lld", &d, &v);
		printf("Case %d: ", kase);
		if(d == 0){puts("1"); continue;}
		if(v == 0){printf(d >= 1 ? "-1\n" : "1\n"); continue;}
		if(d == 1){printf("%lld\n", (v+1)%mod); continue;}
		if(v == 2){printf("%lld\n", (2*d+1)%mod); continue;}
		if(v == 1){puts("-1"); continue;}
		ll p = mpow(v-1, d);
		p = (p-1+mod)%mod;
		//cout << p << endl;
		p *= inv(v-2);
		p%=mod;
		p = (1+p*(v))%mod;
	printf("%lld\n", p);
	}
	return 0;
}
