#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,m,k;
int dp[505][505];
int pre[505][505];
char s[5000];
vector<int> tt[505];

int main()
{
	scanf("%d%d%d", &n,&m,&k);
	for(int i=1; i<=n; i++){
		scanf("%s", s);
		for(int j=0; j<m; j++){
			if(s[j] == '1')tt[i].push_back(j);
		}
	}
	for(int i=1; i<=n; i++){
		pre[i][0] = tt[i].size() ? tt[i].back() - tt[i][0]+1 : 0;
		//cout<<pre[i][0]<<" ";
		for(int j=1; j<tt[i].size()&&j<=k; j++){
			pre[i][j] = pre[i][0];
			for(int t=0; t+tt[i].size()-j-1<tt[i].size(); t++){
				pre[i][j] = min(pre[i][j], tt[i][t+tt[i].size()-j-1]-tt[i][t]+1);
			}
			//cout<<pre[i][j]<<" ";
		}
		//puts("");
	}
	for(int i=1; i<=n; i++){
		dp[i][0] = dp[i-1][0]+pre[i][0];
		//cout<<dp[i][0]<<" ";
		for(int j=1; j<=k; j++){
			dp[i][j] = dp[i][0];
			for(int t=0; t<=j; t++){
				dp[i][j] = min(dp[i][j], dp[i-1][t] + pre[i][j-t]);
			}
		//	cout<<dp[i][j]<<" ";
		}
		//puts("");
	}
	printf("%d\n", dp[n][k]);

	return 0;
}
