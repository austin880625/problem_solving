#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int f[25][25];
long long int ex[25][25];
long long int inq[1<<21];
long long int dp[1<<21];
const long long int mod = 1000000007;

int main()
{
	int n,m;
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; i++){
		for(int j=0; j<m; j++){
			scanf("%d", &f[i][j]);
			f[i][j]--;
			ex[i][f[i][j]] ++;
		}
	}
	queue<int> Q;
	dp[0] = 1;
	Q.push(0);
	while(!Q.empty()){
		int s = Q.front(); Q.pop();
		int i = __builtin_popcount(s);
		for(int j=0; j<n; j++){
			if(ex[i+1][j]&&!(s&(1<<j))){
				int ns = s^(1<<j);
				//cout<<j<<" ";
				dp[ns] += (dp[s]*ex[i+1][j])%mod;
				dp[ns] %= mod;
				if(!inq[ns])Q.push(ns), inq[ns] = 1;
			}
		}
	}
	printf("%lld\n", dp[(1<<n)-1]);
	
	return 0;
}
