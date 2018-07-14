#include <stdio.h>
#include <iostream>

using namespace std;

typedef long long int ll;
ll gcd(ll a, ll b){
	return b ? gcd(b, a%b) : a;
}

int main()
{
	int n;
	scanf("%d", &n);
	while(n--){
		ll a, c;
		scanf("%lld%lld", &a, &c);
		if(c%a){puts("-1"); continue;}
		//ll ans=1;
		ll d=c/a;
		ll d0=d;
		while(d0!=1){
			ll dd=gcd(a,d0);
			a/=dd;
			d0=dd;
		}
		//ll b=d;
		ll b=c/a;
		printf("%lld\n", b);
	}
	return 0;
}
