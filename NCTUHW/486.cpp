#include <stdio.h>
#include <iostream>

using namespace std;

int f[25][25];
int dp[25][1<<21];
int ans[25];

int main()
{
	int n,m;
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; i++){
		for(int j=0; j<m; j++){
			scanf("%d", &f[i][j]);
			f[i][j]--;
		}
	}
	dp[0][0] = 1;
	for(int i=1; i<=n; i++){
		for(int j=0; j<m; j++){
			for(int S=0; S<(1<<n); S++){
				if( dp[i-1][S] && !(S&(1<<f[i][j])) ){ 
	//				cout<<i<<" "<<j<<" "<<S<<" "<<(S^(1<<f[i][j]))<<endl;
					dp[i][S^(1<<f[i][j])] = 1;
				}
			}
		}
	}
	int s = (1<<n)-1;
	for(int i=n; i>0; i--){
		for(int j=0; j<m; j++){
			if(dp[i][s] && dp[i-1][s^(1<<f[i][j])]){
				s = s^(1<<f[i][j]);
				ans[i] = j+1;
				break;
			}
		}
	}
	for(int i=1; i<=n; i++){
		if(i-1)printf(" ");
		printf("%d", ans[i]);
	}
	puts("");
	
	return 0;
}
