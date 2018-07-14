#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int ll;
#define MAXN 100000
struct cas
{
	ll m,s,p;
	bool operator <(const cas &x)const{
		return s<x.s;
	}
};
cas c[MAXN];

int main()
{
	int T,R,B,C;
	scanf("%d", &T);
	for(int kase=1; kase <= T; kase++){
		scanf("%d%d%d", &R, &B, &C);
		for(int i=0; i<C; i++){
			scanf("%lld%lld%lld", &c[i].m, &c[i].s, &c[i].p);
		}
		sort(c, c+C);
		printf("Case #%d: ", kase);
	}
	return 0;
}
