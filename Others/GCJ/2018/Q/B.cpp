#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> e, o;

int main()
{
	int T,N;
	scanf("%d", &T);
	for(int kase=1; kase<=T; kase++){
		scanf("%d", &N);
		e.clear(); o.clear();
		for(int i=0,x; i<N; i++){
			scanf("%d", &x);
			if(i%2)o.push_back(x);
			else e.push_back(x);
		}
		sort(e.begin(), e.end());
		sort(o.begin(), o.end());
		int ans = -1;
		printf("Case #%d: ", kase);
		for(int _i=0; _i<N-1; _i++){
			int i = _i/2, j = (_i+1)/2;
			if(i == j && e[i] > o[j]){
				ans = _i;
				break;
			}
			else if(i+1 == j && o[i] > e[j]){
				ans = _i;
				break;
			}
		}
		if(ans == -1)puts("OK");
		else printf("%d\n", ans);
	}
	return 0;
}
