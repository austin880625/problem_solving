#include <stdio.h>
#include <iostream>

using namespace std;

int cnt[100006];
int pos[100006];
int a[100006];
int ans[100005];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d", a+i);
		pos[a[i]] = i;
		cnt[a[i]] ++;
		if(cnt[a[i]]>1||a[i]>n)a[i]=-1;
	}
	int cur=1;
	for(int i=1; i<=n; i++){
		if(a[i]!=-1)continue;
		while(cnt[cur])cur++;
		a[i]=cur;
		cur++;
	}
	for(int i=1; i<=n ;i++){
		if(i>1)printf(" ");
		printf("%d", a[i]);
	}
	return 0;
}
