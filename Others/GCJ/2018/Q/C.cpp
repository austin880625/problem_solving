#include <stdio.h>
#include <iostream>

using namespace std;

int p[1005][1005];

int main()
{
	int T, A;
	scanf("%d", &T);
	for(int kase=1; kase<=T; kase++){
		for(int i=0; i<=1001; i++){
			for(int j=0; j<=1001; j++)p[i][j] = 0;
		}
		scanf("%d", &A);
		int I=10000,J=10000;
		int np = 0, ti=2, tj = 2;
		while(I!=0||J!=0){
			if(p[ti-1][tj-1]&&p[ti][tj-1]&&p[ti+1][tj-1]){
				if(tj+1 <= 999 && np+9<A)tj++,np+=3;
				
			}
			printf("%d %d\n", ti, tj);
			fflush(stdout);
			scanf("%d %d", &I, &J);
			if(I==-1)break;
			p[I][J] = 1;
		}
	}
	return 0;
}
