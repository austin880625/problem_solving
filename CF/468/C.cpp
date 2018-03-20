#include <stdio.h>
#include <iostream>

using namespace std;

const int MAXN = 100006;

int n;
int x[MAXN];
int cnt[3];

int main()
{
	scanf("%d",&n);
	int minv=10000000, maxv=-10000000;
	for(int i=0; i<3; i++)cnt[i]=0;
	for(int i=0;i<n;i++){
		scanf("%d",x+i);
		minv=min(minv, x[i]);
		maxv=max(maxv, x[i]);
	}
	if(maxv == minv+1){
		printf("%d\n", n);
		printf("%d", x[0]);
		for(int i=1; i<n; i++)printf(" %d", x[i]);
		puts("");
	}
	else{
		for(int i=0; i<n; i++){
			cnt[x[i]-minv]++;
		}
		int ans=n, aa, ab, ac;
		for(int c=0; c<=n; c++){
			int b = cnt[1]-2*(c-cnt[2]);
			if(b<0||b>n)continue;
			int a = n-b-c;
			if(a<0||a>n)continue;
			int d = min(a,cnt[0]) + min(b,cnt[1]) + min(c,cnt[2]);
			if(d<=ans){
				ans=d;
				aa=a; ab=b; ac=c;
			}
		}
		printf("%d\n", ans);
		for(int i=0; i<aa+ab+ac; i++){
			if(i)printf(" ");
			if(i<aa)printf("%d", minv);
			else if(i<aa+ab)printf("%d", minv+1);
			else printf("%d", minv+2);
		}
		puts("");
	}
	return 0;
}
