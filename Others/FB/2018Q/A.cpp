#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int ll;

struct Attr
{
	int id;
	char s[25];
}A[55];

int T;
ll K, N, V;
vector<int> ans;

int main()
{
	scanf("%d", &T);
	for(int kase = 1; kase <= T; kase++)
	{
		ans.clear();
		scanf("%lld%lld%lld", &N, &K, &V);
		for(int i=0; i<N; i++)
		{
			scanf("%s", A[i].s);
			A[i].id = i;
		}
		int k = (K*(V-1))%N;
		for(int i=0; i<K; i++){
			ans.push_back((k+i)%N);
		}
		sort(ans.begin(), ans.end());
		printf("Case #%d:", kase);
		for(int i=0; i<K; i++)
		{
			printf(" %s", A[ans[i]].s);
		}
		puts("");
	}
	return 0;
}
