#include <stdio.h>
#include <iostream>

using namespace std;
#define MAXN 100005
int n,U;
int E[MAXN];

int main()
{
	scanf("%d %d", &n,&U);
	for(int i=0; i<n; i++)scanf("%d",E+i);
	int pos = -1;
	double ans=0;
	for(int i=0; i<n-2; i++){
		int l=i+1, r=n;
		while(l<r){
			int mid=(l+r)>>1;
			if(E[mid]-E[i] <= U){
				l=mid+1;
			}
			else{
				r=mid;
			}
		}
		if(l-1 <= i+1)continue;
		pos=0;
		ans = max(ans, (double)(E[l-1] - E[i+1])/(double)(E[l-1] - E[i]));
	}
	if(pos == -1)puts("-1");
	else{
		printf("%.12f\n", ans);
	}
	return 0;
}
