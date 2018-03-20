#include <stdio.h>
#include <iostream>

using namespace std;

const int MAXN = 505;
int R,C;
char B[505][505];
int dr[4] = {0,1,0,-1}, dc[4] = {1,0,-1,0};

int main()
{
	scanf("%d%d",&R,&C);
	for(int i=0; i<R; i++){
		scanf("%s",B[i]);
	}
	int ans=1;
	for(int i=0; i<R;i++){
		for(int j=0; j<C; j++){
			if(B[i][j]!='W')continue;
			for(int d=0; d<4; d++){
				if(i+dr[d]<0||i+dr[d]>=R||j+dc[d]<0||j+dc[d]>=C)continue;
				if(B[i+dr[d]][j+dc[d]] == 'S')ans=0;
			}
		}
	}
	for(int i=0; i<R; i++)for(int j=0; j<C;j++)if(B[i][j]=='.')B[i][j]='D';
	if(ans){
		printf("Yes\n");
		for(int i=0; i<R; i++){
			printf("%s\n", B[i]);
		}
	}
	else puts("No");
	return 0;
}
