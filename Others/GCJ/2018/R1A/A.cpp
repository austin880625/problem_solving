#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

typedef long long int ll;
#define MAXN 105
char W[MAXN][MAXN];
int S[MAXN][MAXN];
vector<int> sph, spv;

int main()
{
	int T,R,C,H,V;
	scanf("%d", &T);
	for(int kase=1; kase <= T; kase++){
		scanf("%d%d%d%d", &R, &C, &H, &V);
		sph.clear(); spv.clear();
		sph.push_back(0); spv.push_back(0);
		for(int i=1; i<=R; i++){
			scanf("%s", W[i]+1);
			for(int j=1; j<=C; j++){
				S[i][j] = S[i][j-1] + S[i-1][j] - S[i-1][j-1];
				if(W[i][j] == '@')S[i][j]++;
				//cout << S[i][j] << " ";
			}
			//puts("");
		}
		int n = S[R][C], d = (H+1)*(V+1);
		printf("Case #%d: ", kase);
		if(n%(H+1) || n%(V+1) || n%d){printf("IMPOSSIBLE\n"); continue;}
		if(n == 0){
			if(H<R&&V<C)printf("POSSIBLE\n");
			else printf("IMPOSSIBLE\n");
			continue;
		}
		int hd = n/(H+1), vd = n/(V+1);
		for(int i=1; i<=R; i++){
			if(S[i][C] - S[sph.back()][C] == hd){
				sph.push_back(i);
			}
		}
		if(sph.size()-1 != H+1){printf("IMPOSSIBLE\n"); continue;}
		for(int i=1; i<=C; i++){
			if(S[R][i] - S[R][spv.back()] == vd){
				spv.push_back(i);
			}
		}
		if(spv.size()-1 != V+1){printf("IMPOSSIBLE\n"); continue;}
		int w = n/d, ans=1;
		for(int i=1; i<sph.size(); i++){
			for(int j=1; j<spv.size(); j++){
				int lr=sph[i-1], rr=sph[i], lc=spv[i-1], rc=spv[i];
				//cout<<S[rr][rc] - S[lr][rc] - S[rr][lc] + S[lr][lc]<<endl;
				if(S[rr][rc] - S[lr][rc] - S[rr][lc] + S[lr][lc] != w){
					ans = 0;
				}
			}
		}
		if(ans)printf("POSSIBLE\n");
		else printf("IMPOSSIBLE\n");
	}
	return 0;
}
