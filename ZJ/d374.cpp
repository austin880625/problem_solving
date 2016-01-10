#include <iostream>
#include <stdio.h>
#define LL long long int

using namespace std;

LL x,y;
LL M,N;

void ext_gcd(LL a,LL b)
{
    int A=max(a,b),B=min(a,b);
    int p=A/B,Q=A%B;

}

void solve(LL a,LL b)
{

}

int main()
{
	while(scanf("%lld",&M)==1)
	{
		LL Mp,Mq;
		for(LL i=1;i*i<=M;i++)
		{
			if(M%i==0)
            {
                Mp=i,Mq=M/i;
                //solving Mp*x-Mq*y=2
                solve(Mp,Mq);
                swap(Mp,Mq);
                solve(Mp,Mq);
            }
		}
	}
	return 0;
}
