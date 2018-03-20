#include <stdio.h>
#include <iostream>

using namespace std;

int f(int n){int res=1; while(n){int r=n%10; if(r)res*=r;n/=10;} return res;}
int g(int n){
	if(n<10)return n;
	else return g(f(n));
}

int table[1000001][11];

int main()
{
	int q,l,r,k;
	for(int i=1; i<=1000000; i++){for(int j=0;j<11;j++)table[i][j]=table[i-1][j];int t=g(i);table[i][t] = table[i-1][t]+1;}
	scanf("%d", &q);
	while(q--){
		scanf("%d%d%d",&l,&r,&k);
		printf("%d\n", table[r][k]-table[l-1][k]);
	}
	return 0;
}
