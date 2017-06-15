#include <stdio.h>
#include <iostream>
#define LL long long int

using namespace std;

LL n, q;
int k;

int main()
{
	while(scanf("%I64d%d",&n,&k)==2)
	{
		LL i;q=0;
		int m=0;
		for(i=1;i*i<=n;i++)
		{
			if(n%i==0)
			{
				m++;
			}
		}
		int x=m*2-(i*i==n ? 1 : 0);
		if(k>x){puts("-1");continue;}
		int y=0;
		for(i=1;i*i<=n;i++)
		{
			if(n%i==0)
			{
				y++;
				if(y==k){printf("%I64d\n",i);break;}
				else if(x-y+1==k){printf("%I64d\n",n/i);break;}
			}
		}
	}
	return 0;
}
