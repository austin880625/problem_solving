#include<iostream>
#include <stdio.h>
#include<math.h>
#include<vector>
using namespace std;
vector<long long int> prime;
int primes[1000001];
int isprime(long long int X)
{
    if(X==1)return 0;
    if(X==2)return 1;
    if(X<=1000000)return !primes[X];
    for(int i=0;prime[i]<=sqrt(X);i++)
    {
        if(X%prime[i]==0)return 0;
    }
    return 1;
}
void ct()
{
    primes[1]=1;
    primes[2]=0;
    for(long long int i=2;i<=1000000;i++)
    {
        if(!primes[i]){
        for(long long int j=i*2;j<=1000000;j+=i)
        {
            primes[j]=1;
        }
        prime.push_back(i);
        }
    }
}
vector<long long int> divis;
int main()
{
    unsigned long long int ans,n;
    ct();
    while(scanf("%I64d",&n)==1)
    {
        divis.clear();
        ans=1;
        for(long long int i=1;i*i<=n;i++)
        {
            //if(n%i==0)cout<<i<<endl;
            if(n%i==0&&isprime(i)){
                if(n/i!=i&&isprime(n/i))divis.push_back(n/i);
                ans*=i;
            }
        }
        for(int i=0;i<divis.size();i++)ans*=divis[i];
        if(isprime(n))ans=n;
        printf("%I64d\n",ans);
    }
    return 0;
}
