#include <stdio.h>
#include <iostream>

using namespace std;

int x[105];
int y[105];

int a, b;
int ans=0;
void test(int i, int j){
	int w1=x[i], h1=y[i], w2=x[j], h2=y[j];
	if(w1+w2 <= a && max(h1, h2) <= b)ans = max(ans, w1*h1+w2*h2);
	if(w1+h2 <= a && max(h1, w2) <= b)ans = max(ans, w1*h1+w2*h2);
	if(h1+w2 <= a && max(w1, h2) <= b)ans = max(ans, w1*h1+w2*h2);
	if(h1+h2 <= a && max(w1, w2) <= b)ans = max(ans, w1*h1+w2*h2);
	if(w1+w2 <= b && max(h1, h2) <= a)ans = max(ans, w1*h1+w2*h2);
	if(w1+h2 <= b && max(h1, w2) <= a)ans = max(ans, w1*h1+w2*h2);
	if(h1+w2 <= b && max(w1, h2) <= a)ans = max(ans, w1*h1+w2*h2);
	if(h1+h2 <= b && max(w1, w2) <= a)ans = max(ans, w1*h1+w2*h2);
}

int main()
{
	int n;
	scanf("%d%d%d", &n, &a, &b);
	for(int i=0; i<n; i++){
		scanf("%d%d", x+i, y+i);
	}
	if(n==1){puts("0");return 0;}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i==j)continue;
			test(i, j);
		}
	}
	printf("%d\n", ans);
	return 0;
}
