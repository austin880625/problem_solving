#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int R,C;
char B[70][70];
int r[70], c[70];

void clear(int i, int j)
{
	r[i] = c[j] = 1;
	B[i][j] = '*';
	for(int k=1; k<=R; k++){
		if(B[k][j] == '#')clear(k,j);
	}
	for(int k=1; k<=C; k++){
		if(B[i][k] == '#')clear(i,k);
	}
}

int main()
{
	scanf("%d%d", &R,&C);
	for(int i=1; i<=R; i++){
		scanf("%s", B[i]+1);
	}
	int ans = 1;
	for(int i=1; i<=R; i++){
		for(int j=1; j<=C; j++){
			for(int k=1; k<=R; k++)r[k] = 0;
			for(int k=1; k<=C; k++)c[k] = 0;

			if(B[i][j] == '#')clear(i,j);
			for(int k=1; k<=R; k++){
				for(int l=1; l<=C; l++){
					if(B[k][l] == '.' && r[k] && c[l])ans=0;
				}
			}
		}
	}
	if(ans)puts("Yes");
	else puts("No");
	return 0;
}
