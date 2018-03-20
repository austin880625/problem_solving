#include <stdio.h>
#include <iostream>

using namespace std;

int MAT[250][250];
int RC[250][250];
int N;
int head[25000];

int main()
{
	scanf("%d",&N);
	for(int t=0; t<2; t++){
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				scanf("%d",&RC[t*N+i][j]);
			}
		}
	}
	int st=-1, row=-1;
	for(int i=0; i<N; i++)MAT[N][i]=RC[0][i];
	for(int i=1; i<2*N; i++){
		for(int j=0; j<N; j++){
			if(RC[i][j] == RC[0][0]){
				st = N-j, row = i;
				for(int k=0; k<N; k++){MAT[st+k][0]=RC[i][k];head[RC[i][k]] = k+1;}
				goto a;
			}
		}
	}
a:
	//printf("%d\n",row);
	for(int i=1; i<2*N; i++){
	//	printf("%d %d\n",RC[i][0],head[RC[i][0]]);
		if(head[RC[i][0]] && i != row){
			for(int j=0; j<N; j++)MAT[st+head[RC[i][0]]-1][j] = RC[i][j];
		}
	}
	for(int i=st; i<st+N; i++){
		for(int j=0; j<N; j++){printf("%d", MAT[i][j]);if((i!=st+N-1)||(j!=N-1))printf(" ");}
	}
	puts("");
	return 0;
}
