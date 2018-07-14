#include <stdio.h>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
#define MAXN 100005
int S;
struct sign{
	int D,A,B;
	bool operator <(const sign &x) const {
		return D-B == x.D-x.B ? D+A < x.D+x.A : D-B < x.D-x.B;
	}
} signs[MAXN];
map<int, int> M;
int main()
{
	int T;
	scanf("%d", &T);
	for(int kase=1; kase <= T; kase++){
		scanf("%d", &S);
		for(int i=0; i<S; i++){
			scanf("%d%d%d", &signs[i].D, &signs[i].A, &signs[i].B);
		}
		int l, r;
		int y=0, z=0;
#define INF 2147483647
		for(l=0; l<S; l++){
			for(r=l; r<S;r++){
				if(r-l+1 < y)continue;
				sign &s1 = signs[l];
				int N = s1.D-s1.B, M=INF, f=1;
				for(int i=l; i<=r; i++){
					if(signs[i].D-signs[i].B != N){
						if(M!=INF && signs[i].D+signs[i].A!=M)f=0;
						else M=signs[i].D+signs[i].A;
					}
				}
				if(f){ if(r-l+1 > y){y=r-l+1; z=1;}else if(r-l+1==y)z++; }
				M = s1.D+s1.A, N=INF;
				int f2=1;
				for(int i=l; i<=r; i++){
					if(signs[i].D+signs[i].A != M){
						if(N!=INF && signs[i].D-signs[i].B!=N)f2=0;
						else N=signs[i].D-signs[i].B;
					}
				}
				if(f2&&!f){ if(r-l+1 > y){y=r-l+1; z=1;}else if(r-l+1==y)z++; }
				if(!(f||f2)) break;
			}
		}
		/*for(r=0; r<S; r++){
			sign &x = signs[r];
			auto it = M.find(x.D-x.B);
			if(it==M.end()){
				M.insert(pair<int, int>(x.D-x.B, 1));
			}else{
				M[x.D-x.B] ++;
			}
			it = M.find(x.D+x.A);
			if(it==M.end()){
				M.insert(pair<int, int>(x.D+x.A, 1));
			}else{
				M[x.D+x.A] ++;
			}
			if(r-l+1 > y){
				y=r-l+1;
				z=1;
			}else if(r-l+1 == y) z++;
		}*/
		printf("Case #%d: ", kase);
		printf("%d %d\n", y, z);
	}
	return 0;
}
