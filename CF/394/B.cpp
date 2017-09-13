#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 105

using namespace std;

int N,L;
int A[2][MAXN];
int D[2][MAXN];
bool ans;

void match(int pos)
{
	bool tmp=true;
	for(int i=0;i<N;i++)
	{
		if(D[0][i]!=D[1][(pos+i)%N])tmp=false;
	}
	ans|=tmp;
}

int main()
{
	while(scanf("%d%d",&N,&L)==2)
	{
		ans=false;
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<N;j++)
			{
				scanf("%d",&A[i][j]);
				if(j)D[i][j-1]=A[i][j]-A[i][j-1];
			}
			D[i][N-1]=L-A[i][N-1]+A[i][0];
		}
		for(int i=0;i<=N;i++)
		{
			match(i);
		}
		printf(ans ? "YES" : "NO");
		puts("");
	}
	return 0;
}

