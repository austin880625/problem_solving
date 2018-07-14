#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <queue>

using namespace std;
#define LL long long int
#define pii pair<int, int>
LL w[100005];
queue<pii > Q;

int main()
{
	int T;
	scanf("%d", &T);
	for(int kase=1; kase<=T; kase++){
		int N;
		scanf("%d", &N);
		for(int i=1; i<=N; i++)scanf("%lld", w+i);

		Q.push(pii(0,0));
		while(!Q.empty()){
			pii now = Q.front(); Q.pop();
			
		}

		printf("Case #%d: ", kase);
		printf("%lld\n", ans);
	}
	return 0;
}
