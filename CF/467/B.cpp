#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>

using namespace std;

typedef long long int ll;
ll prime[50001];
ll primes[50001];
int len=0;

void pre_process()
{
	for(ll i=2; i<=50000;i++)prime[i]=1;
    for(ll i=2;i<=50000;i++)
    {
        if(prime[i])
        {
            primes[len++]=i;
            for(ll j=2*i;j<=50000;j+=i)
            {
                prime[j]=0;
            }
        }
    }
}

int isprime(ll N, ll p)
{
        int t=1;
        for(ll i=3;i<=p&&t<len&&i*i<=N;i=primes[t++])
        {
            if(N%i==0)return 0;
        }
        return 1;
}

ll p,y;
int main()
{
	pre_process();
	cin>>p>>y;
	if((y&1)==0)y--;
	
		while(y>p&&!isprime(y,p))y-=2;
		cout<<(y<=p ? -1:y)<<endl;
	
	return 0;
}
