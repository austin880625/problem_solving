#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int a[10005];
int b[10005];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d", a+i);
	}
	sort(a+1, a+n+1);
	int l=1, r=n;
	int cnt=1;
	while(l<=r){
		if(cnt%2){
			b[cnt++] = a[l];
			l++;
		}else{
			b[cnt++] = a[r];
			r--;
		}
	}
	for(int i=1; i<cnt; i++){
		if(i>1)printf(" ");
		printf("%d", b[i]);
	}
	puts("");
	return 0;
}
