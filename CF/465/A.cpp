#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	int ans=0;
	for(int i=1; i*2<=n; i++){
		if((n-i)%i==0)ans++;
	}
	printf("%d\n",ans);
	return 0;
}
