#include<iostream>
#include<queue>
#include<stack>
#include <stdio.h>
#include<string.h>
#include<math.h>

using namespace std;

vector<int> primes;
int prime[1000001];
void pre_process()
{
    for(int i=2;i<=100000;i++)
    {
        if(prime[i])
        {
            primes.push_back(i);
            for(int j=2*i;j<=100000;j+=i)
            {
                prime[j]=0;
            }
        }
    }
}

int isprime(int N)
{
    if(N<=100000)return prime[N];
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

int test(int k,int n)
{
    if(k==1)return isprime(n);
    if(k==2&&n%2)return isprime(n-2);
    else
    {
        int res=isprime(n-4);
        for(int i=0;i<50000;i++)
            res&=test(k-1,n-primes[i]);
    }
}

int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        if(isprime(n))printf("1\n%d",n);
        else if(test(2,n))printf("2\n%d %d\n",ans[0],ans[1]);
        else if(test(3,n))printf("3\n%d %d %d\n",ans[0],ans[1],ans[2]);
    }
    return 0;
}