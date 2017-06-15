#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 100005

using namespace std;

int a,b;

int main()
{
	while(scanf("%d%d",&a,&b)==2)
	{
		if(abs(a-b)<=1&&(a!=0||b!=0))puts("YES");
		else puts("NO");
	}
	return 0;
}
