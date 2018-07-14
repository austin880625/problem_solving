#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>

using namespace std;
#define LL long long int
LL dp[2][100005];
LL w[100005];
const LL INF = (1LL << 62);
int main()
{
	int T;
	scanf("%d", &T);
	for(int kase=1; kase<=T; kase++){
		int N;
		scanf("%d", &N);
		for(int i=1; i<=N; i++)scanf("%lld", w+i);
		dp[0][0] = 0; dp[0][1] = INF;
		int st=16;
		for(int i=1; i<=N; i++){
			dp[i&1][0] = 0; dp[i&1][i+1] = INF;
			for(int j=1; j<=i; j++){
				dp[i&1][j] = dp[(i-1)&1][j];
				if(w[i]*6 >= dp[(i-1)&1][j-1]){
					dp[i&1][j] = min(dp[i&1][j], dp[(i-1)&1][j-1]+w[i]);
				}
				if(i==N)st=j;
				if(dp[i&1][j] == INF)break;
			}
		}
		int ans=0;
		for(int i=st; i>=0; i--)if(dp[N&1][i] != INF){ans = i; break;}
		printf("Case #%d: ", kase);
		printf("%d\n", ans);
	}
	return 0;
}
