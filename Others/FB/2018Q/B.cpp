#include <stdio.h>
#include <iostream>

using namespace std;

int T, N;
int p[55], d[55];

int check(int i)
{
	return i;
}

int main()
{
	scanf("%d", &T);
	for(int kase = 1; kase <= T; kase++)
	{
		scanf("%d", &N);
		for(int i=0; i<=N; i++)scanf("%d", p+i), d[i] = i+1;
		printf("Case #%d: %d\n", kase, N%2 ? 1 : 0);
		if(N%2){puts("0.0");}
	}
	return 0;
}
