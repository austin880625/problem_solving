#include <stdio.h>
#include <iostream>

using namespace std;

#define MAXN 100005
long long int m[MAXN];
int n;
long long int nl[MAXN];

int main()
{
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%I64d",m+i);
	}
	long long int M = n-1;
	for(int i=n-1; i>=0; i--){
		nl[i] = max(1LL, m[M]+1 - (M-i));
		if(m[i]+1 >= m[M]+1-(M-i)){
			M = i;
			nl[i] = m[i]+1;
		}
	}
	long long int s=0;
	for(int i=1; i<n; i++){
		nl[i] = max(nl[i-1], nl[i]);
		//cout<<nl[i]<<" ";
		s += nl[i] - m[i] - 1;
	}
	printf("%I64d\n", s);
	return 0;
}
