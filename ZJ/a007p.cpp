#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

int prime[50001];
int primes[50001];
int len=0;

void pre_process()
{
    for(int i=2;i<=50000;i++)
    {
        if(prime[i])
        {
            primes[len++]=i;
            for(int j=2*i;j<=50000;j+=i)
            {
                prime[j]=0;
            }
        }
    }
}

int isprime(int N)
{
    if(N<=50000)return prime[N];
    else
    {
        int t=0;
        for(int i=2;i<=sqrt(N);i=primes[t++])
        {
            if(N%i==0)return 0;
        }
        return 1;
    }
}

int main()
{
    int N;
    memset(prime,1,sizeof(prime));
    pre_process();
    prime[1]=0;
    prime[2]=1;
    while(scanf("%d",&N)!=EOF)
    {
        printf(isprime(N) ? "質數\n" : "非質數\n");
    }
}
