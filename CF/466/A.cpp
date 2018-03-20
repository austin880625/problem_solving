#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n,d;
int A[200];

int main()
{
	scanf("%d%d",&n,&d);
	for(int i=0;i<n;i++)scanf("%d",A+i);
	sort(A,A+n);
	int ans=n+1;
	for(int l=0; l<n; l++){
		int r=l;
		while(A[r]-A[l]<=d && r<n)r++;
		ans = min(ans, n-r+l);
	}
	printf("%d\n",ans);
	return 0;
}
