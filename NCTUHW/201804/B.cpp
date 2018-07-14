#include <stdio.h>
#include <iostream>

using namespace std;

long long int w[305][305];

int main()
{
	int T;
	scanf("%d", &T);
	while(T--){
		int n, m;
		scanf("%d%d", &n, &m);
		for(int i=0; i<=n; i++){
			for(int j=0; j<=n; j++){
				if(i != j)w[i][j] = 0x3f3f3f3f;
				else w[i][j] = 0;
			}
		}
		for(int i=0, u, v, ww; i<m; i++){
			scanf("%d%d%d", &u, &v, &ww);
			w[u][v] = ww;
		}
		for(int k=1; k<=n; k++){
			for(int i=1; i<=n; i++){
				for(int j=1; j<=n; j++){
					w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
				}
			}
		}
		int ans=1;
		for(int i=1; i<=n; i++){
			if(w[i][i] < 0){
				ans = 0;
			}
		}
		printf(ans ? "Yes" : "No");
		puts("");
	}
	return 0;
}
